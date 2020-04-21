#pragma once
#include <array>

namespace Geometry3D
{
	class Rotation
	{
	public:
		void set(const Rotation& p);

		double pitchRate() const;
		double rollRate() const;
		double yawRate() const;

	private:
		std::array<double, 3> data;
	};

} // namespace Geometry3D