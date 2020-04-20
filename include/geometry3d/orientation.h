#pragma once
#include <array>

namespace Geometry3D
{
	class Orientation
	{
	public:
		Orientation(double pitch, double roll, double yaw);
		Orientation(const Orientation& other);
		double pitch() const;
		double roll() const;
		double yaw() const;

		friend Orientation interpolate(const Orientation&, const Orientation&, double frac);

	private:
		std::array<double, 3> data;
	};

	Orientation interpolate(const Orientation&, const Orientation&, double frac);

} // namespace Geometry3D