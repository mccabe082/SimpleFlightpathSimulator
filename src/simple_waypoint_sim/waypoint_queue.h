#pragma once
#include <vector>
#include <optional>
#include <string_view>
#include "waypoint.h"

namespace SimpleWaypointSim
{
	class WaypointQueue
	{
	public:


		static bool readFromXML(WaypointQueue& waypoints, const std::string& fileName);

		bool addWaypoint(const Waypoint& newWP);

		std::optional<Waypoint> nextWaypoint(double simTime) const;

		std::optional<Waypoint> operator[](unsigned int iWaypoint) const;

		unsigned waypointsRemaining(double simTime) const;

		bool empty() const;

	private:
		std::vector<Waypoint> _data;
	};

}
