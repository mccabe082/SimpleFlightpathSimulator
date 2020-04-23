#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace Scripted6DoFFlight
{
    class AircraftState : public Position, public Orientation, public Velocity, public Rotation
    {
    public:
        AircraftState(Position p, Orientation o, Velocity v, Rotation r);
    };
}