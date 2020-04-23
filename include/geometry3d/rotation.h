#pragma once
#include <array>

namespace Geometry3D
{
	class Orientation;

	class Rotation
	{
	public:
		Rotation(double pitchRate, double rollRate, double yawRate);

		double pitchRate() const;
		double rollRate() const;
		double yawRate() const;

		static Rotation interpolate(const Rotation& start, const Rotation & final, double frac);
		static Rotation from(const Orientation& oStart, const Orientation& oFinal, double time);
		static Rotation average(const Rotation& start, const Rotation & final);

	private:
		std::array<double, 3> data;
	};

} // namespace Geometry3D