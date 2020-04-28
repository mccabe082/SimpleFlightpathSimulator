#pragma once
#include <vector>
#include <optional>
#include <string_view>
#include "waypoint.h"

namespace Scripted6DoFFlight
{
	class WaypointQueue
	{
	public:


		static bool readFromXML(WaypointQueue& waypoints, const std::string& fileName);

		bool addWaypoint(const Waypoint& newWP);

		std::optional<Waypoint> nextWaypoint(double simTime) const;

		unsigned waypointsRemaining(double simTime) const;

	private:
		std::vector<Waypoint> _data;
	};

}
