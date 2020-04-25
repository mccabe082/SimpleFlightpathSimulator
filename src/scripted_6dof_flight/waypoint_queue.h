#pragma once
#include <queue>
#include <optional>
#include "waypoint.h"

namespace Scripted6DoFFlight
{
	class WaypointQueue
	{
	public:
		void addWaypoint(const Waypoint& newWP);

		std::optional<Waypoint> currentWaypoint() const;
		//std::optional<Waypoint> nextWaypoint();
		//std::optional<Waypoint> getWaypoint(unsigned i);
		unsigned waypointsRemaining() const;

	private:
		std::queue<Waypoint> _data;
	};

}
