#include "geometry3d/orientation.h"
#include "geometry3d/rotation.h"
#include <numeric>
#include <limits>
#include "quaternion.h"

namespace
{
	const double pi = std::acos(-1.);

	bool areEqual(double a, double b)
	{
		return abs(a - b) <= std::numeric_limits<double>::epsilon();
	}

	Geometry3D::Quoternion normalise(const Geometry3D::Quoternion& q)
	{
		return q * (1. / q.norm());
	}

}

namespace Geometry3D
{
	Quoternion::Quoternion(double pitch, double roll, double yaw)
	{
		// https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles#Source_Code

		double cy = cos(yaw * 0.5);
		double sy = sin(yaw * 0.5);
		double cp = cos(pitch * 0.5);
		double sp = sin(pitch * 0.5);
		double cr = cos(roll * 0.5);
		double sr = sin(roll * 0.5);

		set(Component::real, cr * cp * cy + sr * sp * sy);
		set(Component::i, sr * cp * cy - cr * sp * sy);
		set(Component::j, cr * sp * cy + sr * cp * sy);
		set(Component::k, cr * cp * sy - sr * sp * cy);
	}

	Quoternion::Quoternion(double real, double i, double j, double k)
		: data(std::array<double, 4>{real, i, j, k})
	{}

	Quoternion::Quoternion(const Orientation& o)
		: Quoternion(o.pitch(), o.roll(), o.yaw())
	{}

	Quoternion::Quoternion(const Rotation& r)
		: Quoternion(r.pitchRate(), r.rollRate(), r.yawRate())
	{}

	double Quoternion::pitch() const
	{
		double w = get(Component::real);
		double x = get(Component::i);
		double y = get(Component::j);
		double z = get(Component::k);

		double sinp = 2. * (w * y - z * x);

		return std::abs(sinp) >= 1. ? std::copysign(0.5 * pi, sinp) : std::asin(sinp);
	}

	double Quoternion::roll() const
	{
		double w = get(Component::real);
		double x = get(Component::i);
		double y = get(Component::j);
		double z = get(Component::k);

		double sinr_cosp = 2. * (w * x + y * z);
		double cosr_cosp = 1. - 2. * (x * x + y * y);

		return std::atan2(sinr_cosp, cosr_cosp);
	}

	double Quoternion::yaw() const
	{
		double w = get(Component::real);
		double x = get(Component::i);
		double y = get(Component::j);
		double z = get(Component::k);

		double siny_cosp = 2. * (w * z + x * y);
		double cosy_cosp = 1. - 2. * (y * y + z * z);
		return std::atan2(siny_cosp, cosy_cosp);
	}

	Quoternion Quoternion::conjugate() const
	{
		Quoternion conj(*this);
		std::transform(data.begin() + 1, data.end(), conj.data.begin() + 1,
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
		std::transform(inv.data.begin(), inv.data.end(), inv.data.begin(),
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
			[](double a, double b) {return areEqual(a, b); });
	}

	Quoternion operator+(const Quoternion& a, const Quoternion& b)
	{
		Quoternion sum(0., 0., 0., 0.);
		std::transform(a.data.begin(), a.data.end(), b.data.begin(),
			sum.data.begin(), std::plus<double>());
		return sum;
	};

	Quoternion operator-(const Quoternion& a, const Quoternion& b)
	{
		Quoternion difference(0., 0., 0., 0.);
		std::transform(a.data.begin(), a.data.end(), b.data.begin(),
			difference.data.begin(), std::minus<double>());
		return difference;
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

	Quoternion operator*(double v, const Quoternion& q)
	{
		return q * v;
	}

	Quoternion Quoternion::slerp(const Quoternion& qStart, const Quoternion& qEnd, double frac)
	{
		// https://en.wikipedia.org/wiki/Slerp

		// Only unit quaternions are valid rotations.
		// Normalize to avoid undefined behavior.
		Quoternion q0 = normalise(qStart);
		Quoternion q1 = normalise(qEnd);

		// Compute the cosine of the angle between the two vectors.
		double dot = std::sqrt(std::inner_product(q0.data.begin(), q0.data.end(), q1.data.begin(), 0.0));

		// If the dot product is negative, slerp won't take
		// the shorter path. Note that v1 and -v1 are equivalent when
		// the negation is applied to all four components. Fix by 
		// reversing one quaternion.
		if (dot < 0.0f) {
			q1 = q1 * -1.;
			dot = -dot;
		}

		const double DOT_THRESHOLD = 0.9995;
		if (dot > DOT_THRESHOLD) {
			// If the inputs are too close for comfort, linearly interpolate
			// and normalize the result.

			Quoternion result = q0 + frac * (q1 - q0);
			result = normalise(result);
			return result;
		}

		// Since dot is in range [0, DOT_THRESHOLD], acos is safe
		double theta_0 = acos(dot);        // theta_0 = angle between input vectors
		double theta = theta_0 * frac;     // theta = angle between v0 and result
		double sin_theta = sin(theta);     // compute this value only once
		double sin_theta_0 = sin(theta_0); // compute this value only once

		double s0 = cos(theta) - dot * sin_theta / sin_theta_0;  // == sin(theta_0 - theta) / sin(theta_0)
		double s1 = sin_theta / sin_theta_0;

		return (s0 * qStart) + (s1 * qEnd);
	}

} // namespace Geometry3D