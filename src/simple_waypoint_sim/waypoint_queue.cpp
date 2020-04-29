#include "waypoint_queue.h"
#include "waypoint.h"
#include <limits>
#include <iterator>
#include <fstream>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

namespace
{

	void dirtyWaypointQueueReading(SimpleWaypointSim::WaypointQueue& waypoints, const std::string& fileName)
	{
		using namespace SimpleWaypointSim;
		using namespace rapidxml;

		WaypointQueue wpBuffer;
		try
		{
			rapidxml::file<> xmlFile(fileName.c_str()); // Default template is char
			rapidxml::xml_document<> doc;
			doc.parse<0>(xmlFile.data());

			xml_node<>* waypointQueueNode = doc.first_node("WaypointQueue");
			if (waypointQueueNode)
			{
				xml_node<>* waypointNode = waypointQueueNode->first_node("Waypoint");
				while (waypointNode)
				{
					double flyThroughTime = atof(waypointNode->first_attribute("time")->value());

					xml_node<>* positionNode = waypointNode->first_node("Position");
					double x = atof(positionNode->first_attribute("x")->value());
					double y = atof(positionNode->first_attribute("y")->value());
					double z = atof(positionNode->first_attribute("z")->value());

					xml_node<>* orientationNode = waypointNode->first_node("Orientation");
					double pitch = atof(orientationNode->first_attribute("pitch")->value());
					double roll = atof(orientationNode->first_attribute("roll")->value());
					double yaw = atof(orientationNode->first_attribute("yaw")->value());
					
					wpBuffer.addWaypoint(Waypoint(Position(x,y,z), Orientation(pitch,roll,yaw), flyThroughTime));

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
		return _data.size()>=iWaypoint ? std::optional<Waypoint>(_data[iWaypoint]) : std::nullopt;
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
