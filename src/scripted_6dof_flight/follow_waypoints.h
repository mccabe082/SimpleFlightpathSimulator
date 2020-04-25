#pragma once

#include "maneuover.h"
#include "waypoint.h"
#include "waypoint_queue.h"

namespace Scripted6DoFFlight
{
	class AircraftState;
	class Waypoint;

	class FollowWaypoints : Maneuover
	{
	public:
		FollowWaypoints(
			const AircraftState& enteringCondition,
			const WaypointQueue& qWaypints
		);
		AircraftState update(double tStep, const AircraftState& currentState) const override;
		bool completed() const;

	private:
		WaypointQueue course;
		FollowWaypoints() = delete;
	};
}