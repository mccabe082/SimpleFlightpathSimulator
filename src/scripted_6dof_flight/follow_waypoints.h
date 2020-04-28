#pragma once

#include "maneuover.h"
#include "scripted_6dof_flight/waypoint.h"
#include "scripted_6dof_flight/waypoint_queue.h"

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
		AircraftState update(double tStep, double t0, const AircraftState& currentState) const override;
		bool completed() const;

	private:
		WaypointQueue course;
		FollowWaypoints() = delete;
	};
}