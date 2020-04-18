#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace target6Dof
{
    struct BasicTarget : public Position, Orientation, Velocity, Rotation
    {

        double altitude() const;
    };
}