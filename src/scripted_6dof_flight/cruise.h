#pragma once

#include "maneuover.h"

namespace Scripted6DoFFlight
{
    class TargetState;

    class Cruise : Maneuover
    {
    public:
        Cruise(const TargetState& initialState);
        TargetState update(double deltaTime, const TargetState& currentState) const override;
    private:
        double targetHeading;
        Cruise() = delete;
    };
}