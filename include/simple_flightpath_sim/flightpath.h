#pragma once         
#include "simpleflightpathsim_export.h"

SIMPLEFLIGHTPATHSIM_EXPORT void* __cdecl loadFlightpathSim(const char* waypointQueueFile);

SIMPLEFLIGHTPATHSIM_EXPORT bool __cdecl loadFlightpath(void* handle);