#include "waypoint.h"
#include <limits>

namespace Scripted6DoFFlight
{

	Waypoint::Waypoint(const Position& p, double arrivalTime, const Orientation& o) :
		flythroughPosition(p),
		timeToArrival(arrivalTime),
		flythroughOrientation(o)
	{}

	double Waypoint::arrivalTime() const
	{
		return timeToArrival;
	}

	void Waypoint::updateArrivalTime(double tNew)
	{
		timeToArrival = tNew;
	}

	bool Waypoint::passed() const
	{
		return timeToArrival < std::numeric_limits<double>::epsilon();
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