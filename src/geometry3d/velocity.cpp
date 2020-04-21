
#include "geometry3d/velocity.h"
#include "geometry3d/position.h"
#include <numeric>
#include <cmath>

namespace Geometry3D
{
	Velocity::Velocity(double x, double y, double z)
		: data{ x,y,z }
	{}

	double Velocity::Vx() const
	{
		return data.at(0);
	}

	double Velocity::Vy() const
	{
		return data.at(1);
	}

	double Velocity::Vz() const
	{
		return data.at(2);
	}

	double Velocity::heading() const
	{
		return atan2(Vx(), Vy());
	}

	double Velocity::speed() const
	{
		return std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0));
	}

	double Velocity::groundSpeed() const
	{
		return std::sqrt(pow(Vx(), 2) + pow(Vy(), 2));
	}

	Velocity Velocity::groundVector() const
	{
		return Velocity(Vx(), Vy(), 0.);
	}

	Velocity Velocity::interpolate(const Velocity& start, const Velocity & final, double frac)
	{
		return Velocity(
			frac * final.Vx() + (1. - frac) * start.Vx(),
			frac * final.Vy() + (1. - frac) * start.Vy(),
			frac * final.Vz() + (1. - frac) * start.Vz()
		);
	}

	Velocity Velocity::from(const Position& pStart, const Position& pFinal, double time)
	{
		double tRecip = 1. / time;
		return Velocity(
			tRecip * (pFinal.x() - pStart.x()),
			tRecip * (pFinal.y() - pStart.y()),
			tRecip * (pFinal.z() - pStart.z())
		);
	}

	Velocity Velocity::average(const Velocity& v1, const Velocity & v2)
	{
		return  Velocity::interpolate(v1, v2, 0.5);
	}

} // namespace Geometry3D