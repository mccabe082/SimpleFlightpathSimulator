#pragma once

#include "maneuover.h"
#include "waypoint.h"
#include "waypoint_queue.h"

namespace SimpleWaypointSim
{
	class AircraftState;
	class Waypoint;

	class FollowWaypoints : Maneuover
	{
	public:
		FollowWaypoints(
			const WaypointQueue& qWaypoints
		);
		AircraftState update(double tStep, double t0, const AircraftState& currentState) const override;
		bool completed() const;

	private:
		WaypointQueue course;
		FollowWaypoints() = delete;
	};
}