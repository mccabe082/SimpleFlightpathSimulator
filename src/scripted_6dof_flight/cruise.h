#pragma once

#include "maneuover.h"

namespace Scripted6DoFFlight
{
	class AircraftState;

	class Cruise : Maneuover
	{
	public:
		//Cruise(const AircraftState& initialState, const Orientation& offset, double tTransition);
		AircraftState update(double deltaTime, const AircraftState& currentState) const override;
	private:
	//	Velocity targetV;
	//	Orientation targetO;
		Cruise() = delete;
		double transitionTimeRemaining;
	};
}