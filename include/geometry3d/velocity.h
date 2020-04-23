#pragma once
#include <array>

namespace Geometry3D
{
	class Position;

	class Velocity
	{
	public:
		Velocity(double x, double y, double z);

		double Vx() const;
		double Vy() const;
		double Vz() const;
		double heading() const;
		double speed() const;
		double groundSpeed() const;
		Velocity groundVector() const;
		static Velocity interpolate(const Velocity& start, const Velocity & final, double frac);
		static Velocity from(const Position& pStart, const Position& pFinal, double time);
		static Velocity average(const Velocity& start, const Velocity & final);

	private:
		std::array<double, 3> data;
	};

} // namespace Geometry3D