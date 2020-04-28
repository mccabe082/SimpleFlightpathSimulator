#include "aircraft_state.h"

namespace SimpleWaypointSim
{
	AircraftState::AircraftState(Position p, Orientation o, Velocity v, Rotation r) :
		Position(p), Orientation(o), Velocity(v), Rotation(r)
	{}

	Position AircraftState::approach(const Position& target, double relaxationRatio) const
	{
		return Position::interpolate(*this, target, relaxationRatio);
	}

	Orientation AircraftState::approach(const Orientation& target, double relaxationRatio) const
	{
		return Orientation::interpolate(*this, target, relaxationRatio);
	}

	Velocity AircraftState::approach(const Velocity& target, double relaxationRatio) const
	{
		return Velocity::interpolate(*this, target, relaxationRatio);
	}

	Rotation AircraftState::approach(const Rotation& target, double relaxationRatio) const
	{
		return Rotation::interpolate(*this, target, relaxationRatio);
	}

} // namespace target6Dof