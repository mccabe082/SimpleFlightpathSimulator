#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace target6Dof
{
    class ScriptedTarget 
    {
    public:
        ScriptedTarget(Position p, Orientation o, Velocity v, Rotation r);
        
        double altitude() const;
        double speed() const;
        double groundSpeed() const;

        Position position() const;
        void setPosition(const Position& p);
        double x() const;
        double y() const;
        double z() const;
        
        Orientation orientation() const;
        void setOrientation(const Orientation& o);
        double roll() const;
        double pitch() const;
        double yaw() const;
        
        Velocity velocity() const;
        void setVelocity(const Velocity& v);
        double Vx() const;
        double Vy() const;
        double Vz() const;

        Rotation rotation() const;
        void setRotation(const Rotation& r);
        double rollRate() const;
        double pitchRate() const;
        double yawRate() const;
        
	private:
		Position _position;
		Orientation _orientation;
		Velocity _velocity;
		Rotation _rotation;
    };
}