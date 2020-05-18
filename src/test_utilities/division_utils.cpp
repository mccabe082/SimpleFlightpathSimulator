#include "division_utils.h"
#include <cmath>

namespace TestUtilities
{
	double truncatingDivide(double dividend, double divisor)
	{
		return trunc(dividend / divisor);
	}

	double truncatingModulo(double dividend, double divisor)
	{
		return fmod(dividend, divisor);
	}

	double flooringDivide(double dividend, double divisor)
	{
		return floor(dividend / divisor);
	}

	double flooringModulo(double dividend, double divisor)
	{
		return fmod(fmod(dividend, divisor) + divisor, divisor);
	}

	double euclideanDivide(double dividend, double divisor)
	{
		auto sign = [](double val) { return val > 0. ? 1. : val < 0 ? -1. : 0.; };
		return sign(divisor) * floor(dividend / abs(divisor));
	}

	double euclideanModulo(double dividend, double divisor)
	{
		double absD = abs(divisor);
		return fmod(fmod(dividend, absD) + absD, absD);
	}
}