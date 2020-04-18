#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace Scripted6DoFFlight
{
    class TargetState;
    class Maneuover 
    {
        public:
        virtual Position updatePosition(double deltaTime, const TargetState& currentState) const = 0;
        virtual Orientation updateOrientation(double deltaTime, const TargetState& currentState) const = 0;
        virtual Velocity updateVelocity(double deltaTime, const TargetState& currentState) const = 0;
        virtual Rotation updateRotation(double deltaTime, const TargetState& currentState) const = 0;
    };
}