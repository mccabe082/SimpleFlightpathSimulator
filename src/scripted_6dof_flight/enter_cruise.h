#pragma once

#include "maneuover.h"

namespace Scripted6DoFFlight
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
		AircraftState update(double tStep, double manueoverTimeRemaining, const AircraftState& currentState) override;
		bool EnterCruise::completed() const;

	private:
		
		Orientation targetOrient;
		Velocity targetVel;	

		double remainingTransitionTime;
		EnterCruise() = delete;
	};
}