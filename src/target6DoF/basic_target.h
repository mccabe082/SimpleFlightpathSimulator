#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace target6Dof
{
    struct ScriptedTarget 
    {
        ScriptedTarget(Position p, Orientation o, Velocity v, Rotation r);
        
        double altitude() const;
        double speed() const;
        double groundSpeed() const;

        Position position;
        double x() const;
        double y() const;
        double z() const;

        Orientation orientation;
        double roll() const;
        double pitch() const;
        double yaw() const;

        Velocity velocity;
        double Vx() const;
        double Vy() const;
        double Vz() const;

        Rotation rotation;
        double rollRate() const;
        double pitchRate() const;
        double yawRate() const;
    };
}