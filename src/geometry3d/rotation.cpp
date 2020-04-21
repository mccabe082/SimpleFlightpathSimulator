
#include "geometry3d/rotation.h"
#include "quaternion.h"

namespace Geometry3D
{
	void Rotation::set(const Rotation& p)
	{
		data = p.data;
	}

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

} // namespace Geometry3D