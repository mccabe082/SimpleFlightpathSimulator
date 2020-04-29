#pragma once         
#include "simpleflightpathsim_export.h"

extern "C" SIMPLEFLIGHTPATHSIM_EXPORT void* __cdecl loadFlightpathSim(const char* waypointQueueFile);

extern "C" SIMPLEFLIGHTPATHSIM_EXPORT bool __cdecl advanceWaypointSim(void* handleSimData, double tStep,
	double& x, double& y, double& z,
	double& pitch, double& roll, double& yaw);
