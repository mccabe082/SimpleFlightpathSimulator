#pragma once

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace SimpleWaypointSim
{
    class AircraftState : public Position, public Orientation, public Velocity, public Rotation
    {
    public:
        AircraftState(Position p, Orientation o, Velocity v, Rotation r);
		Position approach(const Position& target, double relaxationRatio) const;
		Orientation approach(const Orientation& target, double relaxationRatio) const;
		Velocity approach(const Velocity& target, double relaxationRatio) const;
		Rotation approach(const Rotation& target, double relaxationRatio) const;
    };
}