#pragma once
#include <array>

namespace Geometry3D
{
	class Quoternion
	{
	public:
		Quoternion(double real, double i, double j, double k);
		Quoternion conjugate() const;
		double norm() const;
		Quoternion inverse() const;
		bool hasUnityNorm() const;
		bool isPure() const;
		friend bool operator==(const Quoternion&, const Quoternion&);
		friend Quoternion operator+(const Quoternion&, const Quoternion&);
		friend Quoternion operator*(const Quoternion&, const Quoternion&);
        friend Quoternion operator*(const Quoternion& q, double v);

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
	Quoternion operator*(const Quoternion& a, const Quoternion& b);
    Quoternion operator*(const Quoternion& q, double v);

} // namespace Geometry3D