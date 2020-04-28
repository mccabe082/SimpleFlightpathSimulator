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
					xml_node<>* positionNode = waypointNode->first_node("Position");
					xml_node<>* orientationNode = waypointNode->first_node("Orentation");

					//Position pos; Orientation orient; double arrivalTime;
					//Waypoint waypoint();
					//waypoints.addWaypoint(waypoint);
					waypointNode = waypointNode->next_sibling("Waypoint");
				}
			}
		}
		catch (...)
		{

		}

		//cout << "Node foobar has value " << node->value() << "\n";
		/*for (xml_attribute<>* attr = node->first_attribute();
			attr; attr = attr->next_attribute())
		{
			cout << "Node foobar has attribute " << attr->name() << " ";
			cout << "with value " << attr->value() << "\n";
		}*/
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

	unsigned WaypointQueue::waypointsRemaining(double simTime) const
	{
		const auto& next = std::find_if(_data.begin(), _data.end(), [simTime](const Waypoint& wp) {
			return wp.arrivalTime() > simTime + std::numeric_limits<double>::epsilon();
			});
		return (unsigned)std::distance(next, _data.end());
	}
}
