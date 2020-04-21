
#include "geometry3d/rotation.h"
#include "geometry3d/orientation.h"
#include "quaternion.h"

namespace Geometry3D
{
	Rotation::Rotation(double pitchRate, double rollRate, double yawRate)
		: data{ pitchRate, rollRate, yawRate }
	{}

	double Rotation::pitchRate() const
	{
		return data.at(0);
	}

	double Rotation::rollRate() const
	{
		return data.at(1);
	}

	double Rotation::yawRate() const
	{
		return data.at(2);
	}

	Rotation Rotation::interpolate(const Rotation& start, const Rotation & final, double frac)
	{
		Quoternion q = Quoternion::slerp(Quoternion(start), Quoternion(final), frac);
		return Rotation(q.pitch(), q.roll(), q.yaw()); // Todo test, check and fix
	}

	Rotation Rotation::from(const Orientation& oStart, const Orientation& oFinal, double time)
	{
		double tRecip = 1. / time;
		return Rotation(
			tRecip * (oFinal.pitch() - oStart.pitch()),
			tRecip * (oFinal.roll() - oStart.roll()),
			tRecip * (oFinal.yaw() - oStart.yaw())
		);
	}

	Rotation Rotation::average(const Rotation& v1, const Rotation& v2)
	{
		return  Rotation::interpolate(v1, v2, 0.5);
	}



} // namespace Geometry3D