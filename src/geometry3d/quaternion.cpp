#include "geometry3d/quaternion.h"
#include <numeric>
#include <limits>

namespace
{
	bool areEqual(double a, double b)
	{
		return abs(a - b) <= std::numeric_limits<double>::epsilon();
	}

	double clamp(double& val, double min, double max)
	{
		return val<min ? min : val>max ? max : val;
	}
}

namespace Geometry3D
{
	Quoternion::Quoternion(double pitch, double yaw, double roll)
	{
    	double pHalf = 0.5*roll;
		double rHalf = 0.5*roll;
    	double yHalf = 0.5*roll;

    	set(Component::i, std::sin(rHalf) * std::cos(pHalf) * std::cos(yaw/2) - std::cos(rHalf) * std::sin(pHalf) * std::sin(yHalf));
    	set(Component::j, std::cos(rHalf) * std::sin(pHalf) * std::cos(yaw/2) + std::sin(rHalf) * std::cos(pHalf) * std::sin(yHalf));
    	set(Component::k, std::cos(rHalf) * std::cos(pHalf) * std::sin(yaw/2) - std::sin(rHalf) * std::sin(pHalf) * std::cos(yHalf));
		set(Component::real, std::cos(rHalf) * std::cos(pHalf) * std::cos(yaw/2) + std::sin(rHalf) * std::sin(pHalf) * std::sin(yHalf));
	}

	Quoternion::Quoternion(double real, double i, double j, double k)
		: data(std::array<double, 4>{real, i, j, k})
	{}

	double Quoternion::pitch() const
	{
		double w = get(Component::real);
		double x = get(Component::i);
		double y = get(Component::j);
		double z = get(Component::real);

		double t0 = 2. * (w * x + y * z);
        double t1 = 1. - 2. * (x * x + y * y);
        
		return std::atan2(t0, t1);
	}

	double Quoternion::roll() const
	{	
		double w = get(Component::real);
		double x = get(Component::i);
		double y = get(Component::j);
		double z = get(Component::real);

        double t = 2. * (w * y - z * x);
		clamp( t, -1., 1. );

        return std::asin(t);
	}

	double Quoternion::yaw() const
	{
		double w = get(Component::real);
		double x = get(Component::i);
		double y = get(Component::j);
		double z = get(Component::real);

		double t1 = 2. * (w * z + x * y);
        double t2 = 1. - 2. * (y * y + z * z);
        
		return std::atan2(t1, t2);
	}

	Quoternion Quoternion::conjugate() const
	{
		Quoternion conj(*this);
		std::transform(data.begin()+1, data.end(), conj.data.begin()+1,
			[](double element) {return -1. * element; });
		return conj;
	}

	double Quoternion::norm() const
	{
		return std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0));
	}

	Quoternion Quoternion::inverse() const
	{
		Quoternion inv = conjugate();
		double denominator = 1. / std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
		std::transform(inv.data.begin() , inv.data.end(), inv.data.begin(),
			[denominator](double element) {return denominator * element; });
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
		std::transform(a.data.begin(), a.data.end(), b.data.begin(),
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
		product.set(Quoternion::Component::k, ar * bk + ak * br + ai * bj - aj * bi);
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