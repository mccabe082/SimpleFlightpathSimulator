#pragma once         

namespace SimpleWaypointSim
{
    void* loadWaypoints(const char* waypointQueueFile);
    
    bool __cdecl loadFlightpath(void* handle);
}