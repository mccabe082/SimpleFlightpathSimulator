#pragma once

#include "aircraft_state.h"

namespace SimpleWaypointSim
{
	class Maneuover
	{
	public:
		virtual AircraftState update(double tStep, double t0, const AircraftState& currentState) const = 0;
		virtual bool completed() const = 0;
	};
}