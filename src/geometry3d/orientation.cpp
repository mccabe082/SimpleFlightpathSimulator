
#include "geometry3d/orientation.h"
#include "quaternion.h"

namespace Geometry3D
{
	Orientation::Orientation(double pitch, double roll, double yaw)
		: data{ pitch, roll, yaw }
	{}

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
		Quoternion qPrime = q*(qPrime*q.inverse());

		return Orientation(qPrime.pitch(), qPrime.roll(), qPrime.yaw());
	}

	Orientation interpolate(const Orientation& start, const Orientation & final, double frac)
	{
		Quoternion q = slerp(Quoternion(start), Quoternion(final), frac);
		return Orientation(q.pitch(), q.roll(), q.yaw());
	}

} // namespace Geometry3D