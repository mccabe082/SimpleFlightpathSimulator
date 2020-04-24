#include "follow_waypoints.h"
#include"waypoint.h"

namespace Scripted6DoFFlight
{
	FollowWaypoints::FollowWaypoints(
		const AircraftState& enteringCondition,
		const WaypointQueue& qWaypints)
		: flightpath(qWaypints)
	{}

	AircraftState FollowWaypoints::update(double tStep, double& manueoverTimeRemaining, const AircraftState& currentState) const
	{
		return currentState;
	}

	bool FollowWaypoints::completed() const
	{
		return false;//flightpath.empty();
	}

}