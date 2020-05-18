
#include "geometry3d/orientation.h"
#include "geometry3d/rotation.h"
#include "quaternion.h"
#include "utilities/angle_utils.h"

namespace
{
	void fixAttitude(double& pitch, double& roll, double& yaw)
	{
		yaw = Utilities::clampBetweenPlusOrMinusPiRadians(yaw);
		roll = Utilities::clampBetweenPlusOrMinusPiRadians(roll);
		pitch = Utilities::clampBetweenPlusOrMinusHalfPiRadians(pitch); // this is extremely dodgy

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
		return Orientation(q.pitch(), q.roll(), q.yaw());
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