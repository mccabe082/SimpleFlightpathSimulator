#include "waypoint_queue.h"
#include "waypoint.h"

namespace Scripted6DoFFlight
{

	void WaypointQueue::addWaypoint(const Waypoint& newWP)
	{
		_data.push(newWP);
	}

	std::optional<Waypoint> WaypointQueue::currentWaypoint()
	{
		return !_data.empty() ? std::optional<Waypoint>(_data.front()) : std::nullopt;
	}

	unsigned WaypointQueue::waypointsRemaining()
	{
		return (unsigned) _data.size();
	}

}
