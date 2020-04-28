#include "scripted_6dof_flight/waypoint.h"

namespace Scripted6DoFFlight
{

	Waypoint::Waypoint(const Position& p, const Orientation& o, double arrivalTime) :
		flythroughPosition(p),
		flythroughOrientation(o),
		timeOnArrival(arrivalTime)
	{}

	double Waypoint::arrivalTime() const
	{
		return timeOnArrival;
	}

	Position Waypoint::position() const
	{
		return flythroughPosition;
	}

	Orientation Waypoint::orientation() const
	{
		return flythroughOrientation;
	}
}