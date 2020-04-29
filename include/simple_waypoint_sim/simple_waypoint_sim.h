#pragma once         

namespace SimpleWaypointSim
{
    void* loadWaypointSim(const char* waypointQueueFile);

	bool advanceWaypointSim(void* handleSimData, double tStep,
		double& x, double& y, double& z,
		double& pitch, double& roll, double& yaw);

}