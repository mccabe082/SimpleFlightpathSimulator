#include "scripted_6dof_flight/simple_waypoint_sim.h"
#include <string>
#include "waypoint_queue.h"

namespace Scripted6DoFFlight
{
    void* loadWaypoints(const char* waypointQueueFile)
    {
	try
	{
		std::string fStr = waypointQueueFile;
		Scripted6DoFFlight::WaypointQueue waypoints;
		bool ok = Scripted6DoFFlight::WaypointQueue::readFromXML(waypoints, fStr);
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