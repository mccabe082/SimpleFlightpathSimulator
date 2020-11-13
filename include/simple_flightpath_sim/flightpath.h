#pragma once         
#include "simpleflightpathsim_export.h"

SIMPLEFLIGHTPATHSIM_EXPORT extern void* loadFlightpathSim(const char* waypointQueueFile);

SIMPLEFLIGHTPATHSIM_EXPORT extern bool advanceWaypointSim(void* handleSimData, double tStep,
	double& x, double& y, double& z,
	double& pitch, double& roll, double& yaw);
