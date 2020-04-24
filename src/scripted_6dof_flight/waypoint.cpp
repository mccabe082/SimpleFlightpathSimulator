#include "waypoint.h"

namespace Scripted6DoFFlight
{
	VelocityWaypoint::VelocityWaypoint(const Position& p, const Orientation& o, double arrivalTime)
	: targetPos(p), targetOrient(o), timeToArrival(arrivalTime)
	{}
}