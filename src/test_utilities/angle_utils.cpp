#include "angle_utils.h"
#include "division_utils.h"
#include <cmath>

namespace
{
	const double pi = std::acos(-1.);
}

namespace TestUtilities
{
	double rad2deg(double alpha)
	{
		return 180. * alpha / pi;
	}

	double deg2rad(double alpha)
	{
		return pi * alpha / 180.;
	}

	double clampBetweenPlusOrMinusHalfPiRadians(double alpha)
	{
		return .5 * pi - euclideanModulo(.5 * pi - alpha, pi);
	}

	double clampBetweenPlusOrMinusPiRadians(double alpha)
	{
		return pi - euclideanModulo(pi - alpha, 2. * pi);
	}

	double clampBetweenPlusOrMinus90Degrees(double alpha)
	{
		return rad2deg(clampBetweenPlusOrMinusHalfPiRadians(deg2rad(alpha)));
	}

	double clampBetweenPlusOrMinus180Degrees(double alpha)
	{
		return rad2deg(clampBetweenPlusOrMinusPiRadians(deg2rad(alpha)));
	}
}