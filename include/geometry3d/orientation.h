#pragma once
#include <array>

namespace Geometry3D
{
	class Rotation;

	class Orientation
	{
	public:
		Orientation(double pitch, double roll, double yaw);
		Orientation(const Orientation& other);

		double pitch() const;
		double roll() const;
		double yaw() const;

		Orientation inReferenceFrame(const Orientation& ref) const;
		static Orientation interpolate(const Orientation& start, const Orientation & final, double frac);
		Orientation update(const Rotation& Vr, double time) const;

	private:
		std::array<double, 3> data;
	};

	

} // namespace Geometry3D