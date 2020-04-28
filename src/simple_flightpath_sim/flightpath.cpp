#include "simple_flightpath_sim/flightpath.h"
#include <string>

SIMPLEFLIGHTPATHSIM_EXPORT void* __cdecl loadFlightpath(const char* waypointQueueFile)
{
	try
	{
		std::string fStr = waypointQueueFile;
		//SimpleWaypointSim::WaypointQueue waypoints;
		//bool ok = SimpleWaypointSim::WaypointQueue::readFromXML(waypoints, fStr);
		static int test = 12345;
		return &test;
	}
	catch (...)
	{

	}
}

SIMPLEFLIGHTPATHSIM_EXPORT bool __cdecl loadFlightpath(void* handle)
{
	int* i = static_cast<int*>(handle);
	return *i = 12345;
}