#pragma once

namespace Scripted6DoFFlight
{
    class AircraftState;
    class Maneuover 
    {
        public:
        virtual AircraftState update(double deltaTime, const AircraftState& currentState) const = 0;
    };
}