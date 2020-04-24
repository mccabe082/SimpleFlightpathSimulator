#pragma once

#include "aircraft_state.h"

namespace Scripted6DoFFlight
{
	class Maneuover
	{
	public:
		// update is involked with the desired time to complete maneuover however, in actuallity more time might be required.
		// the call returns a best estimate of the time required to complete the maneuover.
		virtual AircraftState update(double tStep, double& manueoverTimeRemaining, const AircraftState& currentState) = 0;
		virtual bool completed() const = 0;
	};
}