#include "cruise.h"
#include "target_state.h"

#include <geometry3d/quaternion.h> // WHY?!

#include <numeric>

namespace
{
    inline double mean(double a, double b){return 0.5*(a+b);}
}

namespace Scripted6DoFFlight
{
    Cruise::Cruise(const TargetState& initialState)
    : targetHeading(initialState.heading())
    {}

    // Todo: avoid creating new TargetState Objects evey call
    TargetState Cruise::update(double deltaTime, const TargetState& currentState) const
    {
        TargetState nextState(currentState);
        {
            //eular transform
            //earth axes mention
            //orientation follows trajectory - bank -max angle ratio
        }
        return nextState;
    }
}