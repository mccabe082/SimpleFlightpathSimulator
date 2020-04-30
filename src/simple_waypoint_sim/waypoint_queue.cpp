#include "waypoint_queue.h"
#include "waypoint.h"
#include <limits>
#include <iterator>
#include <fstream>
#include <string>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

namespace
{
	const double pi = std::acos(-1.);

	double deg2red(double alpha)
	{
		return pi * alpha / 180.;
	}

	bool hasAttribute(rapidxml::xml_node<>* node, const char* attr)
	{
		return node->first_attribute(attr);
	}

	std::string getAttribute(rapidxml::xml_node<>* node, const char* attr)
	{
		return hasAttribute(node, attr) ? std::string(node->first_attribute(attr)->value()) : std::string();
	}

	void dirtyWaypointQueueReading(SimpleWaypointSim::WaypointQueue& waypoints, const std::string& fileName)
	{
		using namespace SimpleWaypointSim;
		using namespace rapidxml;

		bool pitchInverted = false;
		bool rollInverted = false;
		bool yawInverted = false;
		bool pitchDegrees = false;
		bool rollDegrees = false;
		bool yawDegrees = false;
		bool xInverted = false;
		bool yInverted = false;
		bool zInverted = false;

		WaypointQueue wpBuffer;
		try
		{
			rapidxml::file<> xmlFile(fileName.c_str()); // Default template is char
			rapidxml::xml_document<> doc;
			doc.parse<0>(xmlFile.data());

			xml_node<>* waypointQueueNode = doc.first_node("WaypointQueue");
			if (waypointQueueNode)
			{
				{
					pitchInverted = getAttribute(waypointQueueNode, "pitch_value") == std::string("inverted");
					rollInverted = getAttribute(waypointQueueNode, "roll_value") == std::string("inverted");
					yawInverted = getAttribute(waypointQueueNode, "yaw_value") == std::string("inverted");
					pitchDegrees = getAttribute(waypointQueueNode, "pitch_units") == std::string("deg");
					rollDegrees = getAttribute(waypointQueueNode, "roll_units") == std::string("deg");
					yawDegrees = getAttribute(waypointQueueNode, "yaw_units") == std::string("deg");
					xInverted = getAttribute(waypointQueueNode, "x_value") == std::string("inverted");
					yInverted = getAttribute(waypointQueueNode, "y_value") == std::string("inverted");
					zInverted = getAttribute(waypointQueueNode, "z_value") == std::string("inverted");
				}

				xml_node<>* waypointNode = waypointQueueNode->first_node("Waypoint");
				while (waypointNode)
				{
					double flyThroughTime = atof(waypointNode->first_attribute("time")->value());

					xml_node<>* positionNode = waypointNode->first_node("Position");
					double x = atof(positionNode->first_attribute("x")->value());
					double y = atof(positionNode->first_attribute("y")->value());
					double z = atof(positionNode->first_attribute("z")->value());

					if (xInverted) x *= -1.;
					if (yInverted) y *= -1.;
					if (zInverted) z *= -1.;

					xml_node<>* orientationNode = waypointNode->first_node("Orientation");
					double pitch = atof(orientationNode->first_attribute("pitch")->value());
					double roll = atof(orientationNode->first_attribute("roll")->value());
					double yaw = atof(orientationNode->first_attribute("yaw")->value());

					if (pitchDegrees) pitch = deg2red(pitch);
					if (rollDegrees) roll = deg2red(roll);
					if (yawDegrees) yaw = deg2red(yaw);

					if (pitchInverted) pitch *= -1.;
					if (rollInverted)  roll *= -1.;
					if (yawInverted)   yaw *= -1.;

					wpBuffer.addWaypoint(Waypoint(Position(x, y, z), Orientation(pitch, roll, yaw), flyThroughTime));

					waypointNode = waypointNode->next_sibling("Waypoint");
				}
			}
		}
		catch (...)
		{
			//too bad
		}

		waypoints = std::move(wpBuffer);
	}
}


namespace SimpleWaypointSim
{

	bool WaypointQueue::readFromXML(WaypointQueue& waypoints, const std::string& fileName)
	{
		try {
			dirtyWaypointQueueReading(waypoints, fileName);
		}
		catch (...) {
			return false;
		}
		return true;
	}

	bool WaypointQueue::addWaypoint(const Waypoint& newWP)
	{
		if (!_data.empty())
		{
			if (_data.back().arrivalTime() > newWP.arrivalTime()) return false;
		}

		_data.push_back(newWP);
		return true;
	}

	std::optional<Waypoint> WaypointQueue::nextWaypoint(double simTime) const
	{
		const auto& next = std::find_if(_data.begin(), _data.end(), [simTime](const Waypoint& wp) {
			return wp.arrivalTime() > simTime + std::numeric_limits<double>::epsilon();
			});
		return next != _data.end() ? std::optional<Waypoint>(*next) : std::nullopt;
	}

	std::optional<Waypoint> WaypointQueue::operator[](unsigned int iWaypoint) const
	{
		return _data.size() >= iWaypoint ? std::optional<Waypoint>(_data[iWaypoint]) : std::nullopt;
	}

	unsigned WaypointQueue::waypointsRemaining(double simTime) const
	{
		const auto& next = std::find_if(_data.begin(), _data.end(), [simTime](const Waypoint& wp) {
			return wp.arrivalTime() > simTime + std::numeric_limits<double>::epsilon();
			});
		return (unsigned)std::distance(next, _data.end());
	}

	bool WaypointQueue::empty() const
	{
		return _data.empty();
	}
}
