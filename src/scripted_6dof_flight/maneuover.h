#pragma once

#include "target_state.h"
namespace Scripted6DoFFlight
{
    class Maneuover 
    {
        virtual Position updatePosition(double deltaTime, const TargetState& currentState) const = 0;
        virtual Orientation updateOrientation(double deltaTime, const TargetState& currentState) const = 0;
        virtual Velocity updateVelocity(double deltaTime, const TargetState& currentState) const = 0;
        virtual Rotation updateRotation(double deltaTime, const TargetState& currentState) const = 0;
    };
}