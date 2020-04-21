#include "cruise.h"
#include "aircraft_state.h"

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>
using namespace Geometry3D;

namespace Scripted6DoFFlight
{

    //Cruise::Cruise(const AircraftState& initialState, const Orientation& offset, double tTransition)
	//: vTarget(Velocity(initialState.Vx, initialState.Vy, 0.))
	//, oTarget(offset + Orientation(0.,0.,initialState.yaw()))
    //{}

    // Todo: avoid creating new TargetState Objects evey call
    AircraftState Cruise::update(double deltaTime, const AircraftState& currentState) const
    {
        AircraftState nextState(currentState);
        {
			//peek update
			//nextState.x = interpolate;
        }
        return nextState;
    }
}