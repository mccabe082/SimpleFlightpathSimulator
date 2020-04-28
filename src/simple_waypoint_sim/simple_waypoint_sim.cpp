#include "simple_waypoint_sim/simple_waypoint_sim.h"
#include <string>
#include "waypoint_queue.h"
#include "follow_waypoints.h"

namespace SimpleWaypointSim
{
    void* loadWaypointSim(const char* waypointQueueFile)
    {
		WaypointQueue waypoints;
		SimpleWaypointSim::WaypointQueue::readFromXML(waypoints, std::string(waypointQueueFile));
		return new FollowWaypoints(waypoints);
    }
    
    bool loadFlightpath(void* handle)
    {
		return true;
    }
}