#pragma once
#include <array>

namespace Geometry3D
{
	class Orientation;

	class Quoternion
	{
	public:
		Quoternion(double pitch, double roll, double yaw);
		Quoternion(double real, double i, double j, double k);
		Quoternion(const Orientation& o);

		double pitch() const;
		double roll() const;
		double yaw() const;

		Quoternion conjugate() const;
		double norm() const;
		Quoternion inverse() const;
		bool hasUnityNorm() const;
		bool isPure() const;

		friend bool operator==(const Quoternion&, const Quoternion&);
		friend Quoternion operator+(const Quoternion&, const Quoternion&);
		friend Quoternion operator-(const Quoternion&, const Quoternion&);
		friend Quoternion operator*(const Quoternion&, const Quoternion&);
		friend Quoternion operator*(const Quoternion&, double);
		friend Quoternion operator*(double, const Quoternion&);
		friend Quoternion slerp(const Quoternion&, const Quoternion&, double);

	private:
		enum class Component
		{
			real = 0,
			i = 1,
			j = 2,
			k = 3,
		};
		double get(Component index) const;
		void set(Component index, double value);
		std::array<double, 4> data;
	};

	bool operator==(const Quoternion& a, const Quoternion& b);
	Quoternion operator+(const Quoternion& a, const Quoternion& b);
	Quoternion operator-(const Quoternion& a, const Quoternion& b);
	Quoternion operator*(const Quoternion& a, const Quoternion& b);
	Quoternion operator*(const Quoternion& q, double v);
	Quoternion operator*(double v, const Quoternion& q);
	Quoternion slerp(const Quoternion& qStart, const Quoternion& qEnd, double frac);

} // namespace Geometry3D