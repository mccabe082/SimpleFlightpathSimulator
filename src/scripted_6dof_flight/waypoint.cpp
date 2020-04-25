#include "waypoint.h"
#include <limits>

namespace Scripted6DoFFlight
{

	Waypoint::Waypoint(const Position& p, double arrivalTime, const Orientation& o) :
		flythroughPosition(p),
		timeOnArrival(arrivalTime),
		flythroughOrientation(o)
	{}

	double Waypoint::arrivalTime() const
	{
		return timeOnArrival;
	}

	void Waypoint::updateArrivalTime(double tNew)
	{
		timeOnArrival = tNew;
	}

	bool Waypoint::passed() const
	{
		return timeOnArrival < std::numeric_limits<double>::epsilon();
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