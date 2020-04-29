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

		SimpleWaypointSim::WaypointQueue waypoints;

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
				waypoints,
				AircraftState(pos,ori,vel,rot),
				simTime
			};
		}

		return nullptr;
	}

	bool loadFlightpath(void* handle)
	{
		//AircraftState update(double tStep, double t0, const AircraftState & currentState) const override;
		return true;
	}
}