#include "simple_flightpath_sim/flightpath.h"
#include <string_view>

SIMPLEFLIGHTPATHSIM_EXPORT void* __cdecl loadFlightpath(const char* waypointQueueFile)
{
	try
	{
		std::string_view waypointQueueFileStr = waypointQueueFile;
		int test = 12345;
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