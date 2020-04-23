#pragma once
#include <array>

namespace Geometry3D
{
	class Velocity;

	class Position
	{
	public:
		Position(double x, double y, double z);

		double x() const; // northward [m]
		double y() const; // eastward [m]
		double z() const; // upwards [m]
		double altitude() const;
		static Position interpolate(const Position& start, const Position & final, double frac);
		Position update(const Velocity& v, double time) const;
	private:
		std::array<double, 3> data;
	};

} // namespace Geometry3D