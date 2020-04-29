#pragma once         
#include "simpleflightpathsim_export.h"

SIMPLEFLIGHTPATHSIM_EXPORT void* __cdecl loadFlightpathSim(const char* waypointQueueFile);

SIMPLEFLIGHTPATHSIM_EXPORT bool __cdecl advanceWaypointSim(void* handleSimData, double tStep,
	double& x, double& y, double& z,
	double& pitch, double& roll, double& yaw);
