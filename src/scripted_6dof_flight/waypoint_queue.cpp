#include "waypoint_queue.h"
#include "waypoint.h"
#include <limits>
#include <iterator>

namespace Scripted6DoFFlight
{

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
