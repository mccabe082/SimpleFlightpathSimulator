#include "simple_flightpath_sim/flightpath.h"
#include "simple_waypoint_sim/simple_waypoint_sim.h"



SIMPLEFLIGHTPATHSIM_EXPORT void* __cdecl loadFlightpathSim(const char* waypointQueueFile)
{
	return SimpleWaypointSim::loadWaypointSim(waypointQueueFile);
}

SIMPLEFLIGHTPATHSIM_EXPORT bool __cdecl advanceWaypointSim(void* handleSimData, double tStep,
	double& x, double& y, double& z,
	double& pitch, double& roll, double& yaw)
{
	return SimpleWaypointSim::advanceWaypointSim(handleSimData, tStep, x, y, z, pitch, roll, yaw);
}

