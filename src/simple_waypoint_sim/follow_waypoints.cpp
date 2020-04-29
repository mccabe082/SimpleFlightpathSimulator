#include "follow_waypoints.h"
#include "waypoint.h"
#include "waypoint_queue.h"
#include <geometry3d/position.h>
#include <geometry3d/velocity.h>

namespace SimpleWaypointSim
{
	FollowWaypoints::FollowWaypoints(
		const WaypointQueue& qWaypints)
		: course(qWaypints)
	{}

	AircraftState FollowWaypoints::update(double tStep, double t0, const AircraftState& currentState) const
	{

		if (course.waypointsRemaining(t0))
		{
			auto nextWaypoint = course.nextWaypoint(t0).value();

			if (nextWaypoint.arrivalTime() >= tStep + t0)
			{
				double ratio = tStep / (nextWaypoint.arrivalTime() - t0);

				Position newX = currentState.approach(nextWaypoint.position(), ratio);
				Geometry3D::Velocity newXDot = Geometry3D::Velocity::from(currentState, newX, tStep);

				Orientation newTheta = currentState.approach(nextWaypoint.orientation(), ratio);
				Geometry3D::Rotation newThetaDot = Geometry3D::Rotation::from(currentState, newTheta, tStep);

				return AircraftState(newX, newTheta, newXDot, newThetaDot);
			}
			else
			{
				return FollowWaypoints::update(tStep - (nextWaypoint.arrivalTime() - t0), nextWaypoint.arrivalTime(), currentState);
			}
		}

		return currentState;
	}

	bool FollowWaypoints::completed() const
	{
		return false;
	}

}