#include "simple_waypoint_sim/simple_waypoint_sim.h"
#include <string>
#include "waypoint_queue.h"

namespace SimpleWaypointSim
{
    void* loadWaypointSim(const char* waypointQueueFile)
    {
	try
	{
		std::string fStr = waypointQueueFile;
		SimpleWaypointSim::WaypointQueue waypoints;
		bool ok = SimpleWaypointSim::WaypointQueue::readFromXML(waypoints, fStr);
		static int test = 12345;
		return &test;
	}
	catch (...)
	{

	}
    }
    
    bool loadFlightpath(void* handle)
    {
		return true;
    }
}