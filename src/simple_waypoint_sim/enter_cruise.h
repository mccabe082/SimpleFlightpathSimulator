#pragma once

#include "maneuover.h"

namespace SimpleWaypointSim
{
	class AircraftState;

	class EnterCruise : Maneuover
	{
	public:
		EnterCruise(
			const AircraftState& enteringCondition, 
			double targetSpeed,
			double targetAzimouth,
			const Orientation& offsetDuringManueover = Orientation(0.,0.,0.)
		);
		AircraftState update(double tStep, double t0, const AircraftState& currentState) const override;
		bool completed() const;

	private:
		
		Orientation targetOrient;
		Velocity targetVel;	

		double remainingTransitionTime;
		EnterCruise() = delete;
	};
}