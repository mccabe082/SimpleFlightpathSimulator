#include "simple_waypoint_sim/simple_waypoint_sim.h"
#include <string>
#include "waypoint_queue.h"
#include "follow_waypoints.h"
#include "aircraft_state.h"



namespace
{
	struct SimData
	{
		enum class Status
		{
			SIM_UNINITIALISED = -1,
			SIM_INITIALISED = 0,
			UNSPECIFIED_ERROR = 1,
		} simStatus;

		SimpleWaypointSim::FollowWaypoints waypointSim;

		SimpleWaypointSim::AircraftState aircraft;

		double simTime;
	private:
		SimData() = delete;
	};
}

namespace SimpleWaypointSim
{
	void* loadWaypointSim(const char* waypointQueueFile)
	{
		try
		{
			WaypointQueue waypoints;
			SimpleWaypointSim::WaypointQueue::readFromXML(waypoints, std::string(waypointQueueFile));

			if (!waypoints.empty())
			{
				Waypoint wp0 = waypoints[0].value();

				// place aircraft at the first waypoint
				auto pos = Position(wp0.position());
				auto ori = Orientation(wp0.orientation());

				// just set it as stationary to begin with?!
				auto vel = Velocity(0., 0., 0.);
				auto rot = Rotation(0., 0., 0.);

				// start the simulation at first waypoint
				double simTime = wp0.arrivalTime();

				return new SimData{
					SimData::Status::SIM_INITIALISED,
					FollowWaypoints(waypoints),
					AircraftState(pos,ori,vel,rot),
					simTime
				};
			}
		}
		catch (...)
		{
			//too bad
		}

		return nullptr;
	}

	bool advanceWaypointSim(void* handleSimData, double tStep,
		double& x, double& y, double& z,
		double& pitch, double& roll, double& yaw)
	{
		try
		{
			if (handleSimData)
			{
				SimData* pSimData = static_cast<SimData*>(handleSimData);

				AircraftState currentState = pSimData->aircraft;
				pSimData->aircraft = pSimData->waypointSim.update(tStep, pSimData->simTime, currentState);
				pSimData->simTime += tStep;

				x = pSimData->aircraft.x();
				y = pSimData->aircraft.y();
				z = pSimData->aircraft.z();
				pitch = pSimData->aircraft.pitch();
				roll = pSimData->aircraft.roll();
				yaw = pSimData->aircraft.yaw();

				return true;
			}
		}
		catch(...)
		{
			//too bad
		}
		return false;
	}
}