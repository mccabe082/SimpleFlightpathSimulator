
#include "geometry3d/orientation.h"
#include "geometry3d/rotation.h"
#include "quaternion.h"

namespace
{
	const double pi = std::acos(-1.);

	double clampBetweenPlusOrMinus90Degrees(double alpha)
	{
		return fmod(alpha + .25 * pi, .5 * pi) - .25 * pi;
	}

	double clampBetweenPlusOrMinus180Degrees(double alpha)
	{
		return fmod(alpha + .5 * pi, pi) - .5 * pi;
	}


	void fixAttitude(double& pitch, double& roll, double& yaw)
	{
		yaw = clampBetweenPlusOrMinus180Degrees(yaw);
		roll = clampBetweenPlusOrMinus180Degrees(roll);
		pitch = clampBetweenPlusOrMinus90Degrees(pitch);

	}
}

namespace Geometry3D
{
	Orientation::Orientation(double pitch, double roll, double yaw)
	{
		fixAttitude(pitch, roll, yaw);
		data = { pitch, roll, yaw };
	}

	Orientation::Orientation(const Orientation& other)
		: data(other.data)
	{}

	double Orientation::pitch() const
	{
		return data[0];
	}

	double Orientation::roll() const
	{
		return data[1];
	}

	double Orientation::yaw() const
	{
		return data[2];
	}

	Orientation Orientation::inReferenceFrame(const Orientation& ref) const
	{
		Quoternion qFrame(ref);
		Quoternion q(*this);
		Quoternion qPrime = q * (qFrame * q.inverse());

		return Orientation(qPrime.pitch(), qPrime.roll(), qPrime.yaw());
	}

	Orientation Orientation::interpolate(const Orientation& start, const Orientation & final, double frac)
	{
		Quoternion q = Quoternion::slerp(Quoternion(start), Quoternion(final), frac);
		double pitch = clampBetweenPlusOrMinus90Degrees(q.pitch());
		double roll = clampBetweenPlusOrMinus180Degrees(q.roll());
		double yaw = clampBetweenPlusOrMinus180Degrees(q.yaw());
		return Orientation(pitch, roll, yaw);
	}

	Orientation Orientation::update(const Rotation& Vr, double time) const
	{
		return Orientation(
			Vr.pitchRate() * time + pitch(),
			Vr.rollRate() * time + roll(),
			Vr.yawRate() * time + yaw()
		);
	}

} // namespace Geometry3D