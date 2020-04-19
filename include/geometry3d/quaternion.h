#pragma once
#include <array>

namespace Geometry3D
{
	class Quoternion
	{
	public:
		Quoternion(double i, double j, double k, double real = 0.);
		Quoternion conjugate() const;
		double norm() const;
		Quoternion inverse() const;
		bool hasUnityNorm() const;
		bool isPure() const;

		friend  bool operator==(Quoternion, Quoternion);
		friend  Quoternion operator+(Quoternion, Quoternion);
		friend  Quoternion operator*(Quoternion, Quoternion);
	private:
		double& real();
		double& i();
		double& j();
		double& k();
		std::array<double, 4> data;
	};

	bool operator==(Quoternion a, Quoternion b);
	Quoternion operator+(Quoternion a, Quoternion b);
	Quoternion operator*(Quoternion a, Quoternion b);

} // namespace Geometry3D