
#include "geometry3d/position.h"
#include "geometry3d/velocity.h"

namespace Geometry3D
{
	Position::Position(double x, double y, double z)
		: data(std::array<double, 3>{x, y, z})
	{}

	double Position::x() const
	{
		return data[0];
	}

	double Position::y() const
	{
		return data[1];
	}

	double Position::z() const
	{
		return data[2];
	}

	double Position::altitude() const
	{
		return z();
	}

	Position Position::interpolate(const Position& start, const Position & final, double frac)
	{
		return Position(
			frac * final.x() + (1. - frac) * start.x(),
			frac * final.y() + (1. - frac) * start.y(),
			frac * final.z() + (1. - frac) * start.z()
		);
	}

	Position Position::update(const Velocity& v, double time) const
	{
		return Position(
			v.Vx() * time + x(),
			v.Vy() * time + y(),
			v.Vz() * time + z()
		);
	}


} // namespace Geometry3D