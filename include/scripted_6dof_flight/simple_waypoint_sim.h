#pragma once         

namespace Scripted6DoFFlight
{
    void* loadWaypoints(const char* waypointQueueFile);
    
    bool __cdecl loadFlightpath(void* handle);
}