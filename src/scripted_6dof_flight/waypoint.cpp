#include "waypoint.h"

namespace Scripted6DoFFlight
{

	Waypoint::Waypoint(double arrivalTime) : timeToArrival(arrivalTime)
	{}

	FranksWaypoint::FranksWaypoint(const Position& p, double arrivalTime, const Orientation& o)
	: targetPos(p), Waypoint(arrivalTime), targetOrient(o)
	{}
}