#pragma once

#include "aircraft_state.h"

namespace Scripted6DoFFlight
{
	class Maneuover
	{
	public:
		virtual AircraftState update(double timeStepOvermanueoverTimeRemaining, const AircraftState& currentState) = 0;
		virtual bool completed() const = 0;
	};
}