#pragma once

__declspec(dllexport) void* __cdecl loadFlightpath(const char* waypointQueueFile);

__declspec(dllexport) bool __cdecl loadFlightpath(void* handle);