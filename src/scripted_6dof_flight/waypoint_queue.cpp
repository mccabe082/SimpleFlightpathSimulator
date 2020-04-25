#include "waypoint_queue.h"
#include "waypoint.h"

namespace Scripted6DoFFlight
{

	void WaypointQueue::addWaypoint(const Waypoint& newWP)
	{
		_data.push(newWP);
	}

	std::optional<Waypoint> WaypointQueue::currentWaypoint() const
	{
		return !_data.empty() ? std::optional<Waypoint>(_data.front()) : std::nullopt;
	}

	unsigned WaypointQueue::waypointsRemaining() const
	{
		return (unsigned) _data.size();
	}

}
