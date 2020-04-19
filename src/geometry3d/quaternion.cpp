#include "geometry3d/quaternion.h"
#include <numeric>
#include <limits>

namespace
{
	bool areEqual(double a, double b)
	{
		return abs(a - b) <= std::numeric_limits<double>::epsilon();
	}
}

namespace Geometry3D
{

	Quoternion::Quoternion(double real, double i, double j, double k)
		: data(std::array<double, 4>{real, i, j, k})
	{}

	Quoternion Quoternion::conjugate() const
	{
		Quoternion conj(*this);
		conj.i() *= -1.;
		conj.j() *= -1.;
		conj.k() *= -1.;
		return conj;
	}

	double Quoternion::norm() const
	{
		return std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0));
	}

	Quoternion Quoternion::inverse() const
	{
		Quoternion inv = conjugate();
		double nSquared = 1./std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
		inv.real() *= nSquared;
		inv.i() *= nSquared;
		inv.j() *= nSquared;
		inv.k() *= nSquared;
		return inv;
	}

	bool Quoternion::hasUnityNorm() const
	{
		return areEqual(1., norm());
	}

	bool Quoternion::isPure() const
	{
		return areEqual(0., data[0]/*real()*/);
	}


	double& Quoternion::real() { return data[0]; }
	double& Quoternion::i() { return data[1]; }
	double& Quoternion::j() { return data[2]; }
	double& Quoternion::k() { return data[3]; }


	bool operator==(Quoternion a, Quoternion b)
	{
		return areEqual(a.real(), b.real()) &&
			areEqual(a.i(), b.i()) &&
			areEqual(a.j(), b.j()) &&
			areEqual(a.k(), b.k());
	}

	Quoternion operator+(Quoternion a, Quoternion b)
	{
		Quoternion sum(0.,0.,0.,0.);
		sum.real() = a.real() + b.real();
		sum.i() = a.i() + b.i();
		sum.j() = a.j() + b.j();
		sum.k() = a.k() + b.k();
		return sum;
	};

	Quoternion operator*(Quoternion a, Quoternion b)
	{
		double ar = a.real(); double ai = a.i(); double aj = a.j(); double ak = a.k();
		double br = b.real(); double bi = b.i(); double bj = b.j(); double bk = b.k();

		Quoternion product(0., 0., 0., 0.);
		product.real() = ar * br - ai * bi - aj * bj - ak * bk;
		product.i() = ar * bi + ai * br + aj * bk - ak * bj;
		product.j() = ar * bj + aj * br - ai * bk + ak * bi;
		product.k() = ar * bk + ak * br + ai * bj + aj * bi;
		return product;
	};

} // namespace Geometry3D