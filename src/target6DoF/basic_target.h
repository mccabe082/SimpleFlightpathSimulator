#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace target6Dof
{
    struct BasicTarget 
    {
        BasicTarget(Position p, Orientation o, Velocity v, Rotation r);
        
        double altitude() const;
        double speed() const;
        double groundSpeed() const;

        Position position;
        Orientation orientation; 
        Velocity velocity;
        Rotation rotation;
    };
}