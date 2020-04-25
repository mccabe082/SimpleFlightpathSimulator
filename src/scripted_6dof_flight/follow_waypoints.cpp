#include "follow_waypoints.h"
#include "waypoint.h"
#include "waypoint_queue.h"
#include <geometry3d/position.h>
#include <geometry3d/velocity.h>

namespace Scripted6DoFFlight
{
	FollowWaypoints::FollowWaypoints(
		const AircraftState& enteringCondition,
		const WaypointQueue& qWaypints)
		: course(qWaypints)
	{}

	AircraftState FollowWaypoints::update(double tStep, const AircraftState& currentState) const
	{

		if (course.waypointsRemaining())
		{
			Waypoint wp = course.currentWaypoint().value();

			double tWaypoint = wp.arrivalTime();

			if (tWaypoint < tStep)
			{
				Position newPos = currentState.approach(wp.position(), tStep);
				Geometry3D::Velocity newVel = Geometry3D::Velocity::from(currentState, newPos, tStep);
			}
		}
		else
		{

		}

		return currentState;
	}

	bool FollowWaypoints::completed() const
	{
		return false;
	}

}