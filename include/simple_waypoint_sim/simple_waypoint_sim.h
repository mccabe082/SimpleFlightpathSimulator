#pragma once         

namespace SimpleWaypointSim
{
    void* loadWaypointSim(const char* waypointQueueFile);
    
    bool loadFlightpath(void* handle);
}