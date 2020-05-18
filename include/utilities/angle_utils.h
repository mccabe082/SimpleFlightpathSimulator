#pragma once

namespace Utilities
{
	double rad2deg(double alpha);

	double deg2rad(double alpha);

	double clampBetweenPlusOrMinusHalfPiRadians(double alpha);

	double clampBetweenPlusOrMinusPiRadians(double alpha);

	double clampBetweenPlusOrMinus90Degrees(double alpha);

	double clampBetweenPlusOrMinus180Degrees(double alpha);
}
