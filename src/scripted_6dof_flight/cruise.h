#pragma once

#include "maneuover.h"

namespace Scripted6DoFFlight
{
    class TargetState;

    class Cruise : Maneuover
    {
    public:
        Position updatePosition(double deltaTime, const TargetState& currentState) const override;
        Orientation updateOrientation(double deltaTime, const TargetState& currentState) const override;
        Velocity updateVelocity(double deltaTime, const TargetState& currentState) const override;
        Rotation updateRotation(double deltaTime, const TargetState& currentState) const override;
    private:
        const double Vz_target = 0.0;
        //const double Vy_target = 

    };
}