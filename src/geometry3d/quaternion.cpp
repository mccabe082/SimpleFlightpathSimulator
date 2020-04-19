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
		conj.set(Component::i, -1. * get(Component::i));
		conj.set(Component::j, -1. * get(Component::j));
		conj.set(Component::k, -1. * get(Component::k));
		return conj;
	}

	double Quoternion::norm() const
	{
		return std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0));
	}

	Quoternion Quoternion::inverse() const
	{
		Quoternion inv = conjugate();
		double nSquared = 1. / std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
		inv.set(Component::i, nSquared * inv.get(Component::i));
		inv.set(Component::j, nSquared * inv.get(Component::j));
		inv.set(Component::k, nSquared * inv.get(Component::k));
		return inv;
	}

	bool Quoternion::hasUnityNorm() const
	{
		return areEqual(1., norm());
	}

	bool Quoternion::isPure() const
	{
		return areEqual(0., get(Component::real));
	}

	double Quoternion::get(Component index) const
	{
		return data[int(index)];
	}
	void Quoternion::set(Component index, double value)
	{
		data[int(index)] = value;
	}

	bool operator==(const Quoternion& a, const Quoternion& b)
	{
		return std::equal(a.data.begin(), a.data.end(), b.data.begin(),
			[](double a, double b) {return areEqual(a, b);});
	}

	Quoternion operator+(const Quoternion& a, const Quoternion& b)
	{
		Quoternion sum(0., 0., 0., 0.);
		std::transform(a.data.begin(), a.data.end(), a.data.begin(),
			sum.data.begin(), std::plus<double>());
		return sum;
	};

	Quoternion operator*(const Quoternion& a, const Quoternion& b)
	{
		double ar = a.get(Quoternion::Component::real);
		double ai = a.get(Quoternion::Component::i);
		double aj = a.get(Quoternion::Component::j);
		double ak = a.get(Quoternion::Component::k);

		double br = b.get(Quoternion::Component::real);
		double bi = b.get(Quoternion::Component::i);
		double bj = b.get(Quoternion::Component::j);
		double bk = b.get(Quoternion::Component::k);

		Quoternion product(0., 0., 0., 0.);
		product.set(Quoternion::Component::real, ar * br - ai * bi - aj * bj - ak * bk);
		product.set(Quoternion::Component::i, ar * bi + ai * br + aj * bk - ak * bj);
		product.set(Quoternion::Component::j, ar * bj + aj * br - ai * bk + ak * bi);
		product.set(Quoternion::Component::k, ar * bk + ak * br + ai * bj + aj * bi);
		return product;
	};

	Quoternion operator*(const Quoternion& q, double v)
	{
		Quoternion result(0., 0., 0., 0.);
		std::transform(q.data.begin(), q.data.end(), result.data.begin(),
			[&v](double element) {return v * element; });
		return result;
	}

} // namespace Geometry3D