#pragma once
#include <vector>
#include <optional>
#include "waypoint.h"

namespace Scripted6DoFFlight
{
	class WaypointQueue
	{
	public:
		bool addWaypoint(const Waypoint& newWP);

		std::optional<Waypoint> nextWaypoint(double simTime) const;

		unsigned waypointsRemaining(double simTime) const;

	private:
		std::vector<Waypoint> _data;
	};

}
