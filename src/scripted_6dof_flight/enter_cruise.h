#pragma once

#include "maneuover.h"

namespace Scripted6DoFFlight
{
	class AircraftState;

	class Cruise : Maneuover
	{
	public:
		Cruise(
			const AircraftState& enteringCondition, 
			double transitionTime,
			double targetSpeed,
			double targetAzimouth,
			const Orientation& offsetDuringManueover = Orientation(0.,0.,0.)
		);
		AircraftState update(double timeStepOvermanueoverTimeRemaining, const AircraftState& currentState) override;
		bool Cruise::completed() const;

	private:
		
		Orientation targetOrient;
		Velocity targetVel;	

		double remainingTransitionTime;
		Cruise() = delete;
	};
}