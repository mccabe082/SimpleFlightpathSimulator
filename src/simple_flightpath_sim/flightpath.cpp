#include "simple_flightpath_sim/flightpath.h"
#include "simple_waypoint_sim/simple_waypoint_sim.h"



void* loadFlightpathSim(const char* waypointQueueFile)
{
	return SimpleWaypointSim::loadWaypointSim(waypointQueueFile);
}

bool advanceWaypointSim(void* handleSimData, double tStep,
	double& x, double& y, double& z,
	double& pitch, double& roll, double& yaw)
{
	return SimpleWaypointSim::advanceWaypointSim(handleSimData, tStep, x, y, z, pitch, roll, yaw);
}

