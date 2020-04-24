#pragma once

#include "maneuover.h"
#include "waypoint.h"
#include <queue>

namespace Scripted6DoFFlight
{
	class AircraftState;
	class Waypoint;
	using WaypointQueue = std::queue<Waypoint>;

	class FollowWaypoints : Maneuover
	{
	public:
		FollowWaypoints(
			const AircraftState& enteringCondition,
			const WaypointQueue& qWaypints
		);
		AircraftState update(double tStep, double manueoverTimeRemaining, const AircraftState& currentState) override;
		bool completed() const;

	private:
		WaypointQueue flightpath;
		FollowWaypoints() = delete;
	};
}