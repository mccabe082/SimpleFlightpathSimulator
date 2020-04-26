
#include "geometry3d/orientation.h"
#include "geometry3d/rotation.h"
#include "quaternion.h"

namespace
{
	const double pi = std::acos(-1.);

	double normalisePlusOrMinus180Degrees(double alpha)
	{
		// reduce range to (-360, 360)
		alpha = fmod(alpha, 2. * pi);

		// reduce range to (0, 360)  
		alpha = fmod(alpha + 2. * pi, 2. * pi);

		// change range to between (-180,180)  
		return alpha >= pi ? alpha - 2. * pi : alpha;
	}

	void normalisePitchPlusOrMinus90Degrees(double& pitch, double& roll, double& yaw)
	{
		// change range to between (-180,180)  
		pitch = normalisePlusOrMinus180Degrees(pitch);

		// change range to between (-90,90)
		if (abs(pitch) > pi / 2.)
		{
			if (pitch > 0.)
			{
				// +ve obtuse
				roll += pi;
				yaw += pi;
				pitch = pi - pitch;
			}
			else
			{
				// -ve obtuse
				roll += pi;
				yaw += pi;
				pitch = -pi - pitch;
			}
			yaw = normalisePlusOrMinus180Degrees(yaw);
			roll = normalisePlusOrMinus180Degrees(roll);
		}
	}

	void fixAttitude(double& pitch, double& roll, double& yaw)
	{
		yaw = normalisePlusOrMinus180Degrees(yaw);
		roll = normalisePlusOrMinus180Degrees(roll);
		normalisePitchPlusOrMinus90Degrees(pitch, roll, yaw);
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