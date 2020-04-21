#include "catch.hpp"
#include <geometry3d/orientation.h>
#include <cmath>

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;

TEST_CASE("Orientation interpolation is calulated correctly", "[orientation]") {

	SECTION("orientation components are correctly tranformed into a new frame of reference") {

		// https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation#Example
		Orientation qInF1(0., 0., 0.);
		Orientation F2(2. * pi / 3., 0., 0.);
		Orientation qInF2Expected(2. * pi / 3., 0., 0.);
		Orientation qInF2Actual = qInF1.inReferenceFrame(F2);

		REQUIRE(qInF2Actual.pitch() == Approx(qInF1.pitch()));
		REQUIRE(qInF2Actual.roll() == Approx(qInF1.roll()));
		REQUIRE(qInF2Actual.yaw() == Approx(qInF1.yaw()));
	}

	SECTION("orientation components are correctly interpolated") {

		Orientation start(0., 0., 0.);
		Orientation middleExpected(0., pi / 2., 0.);
		Orientation end(0., pi, 0.);
		Orientation middleActual = interpolate(start, end, 0.5);

		REQUIRE(middleActual.pitch() == Approx(middleExpected.pitch()));
		REQUIRE(middleActual.roll() == Approx(middleExpected.roll()));
		REQUIRE(middleActual.yaw() == Approx(middleExpected.yaw()));
	}
}