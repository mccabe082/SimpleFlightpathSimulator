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

		const double deg45 = pi / 4.;

		Orientation qInF1(0., 0., 0.);
		Orientation F2(deg45, deg45, deg45);
		Orientation qInF2Expected(deg45, deg45, deg45);
		Orientation qInF2Actual = qInF1.inReferenceFrame(F2);

		REQUIRE(qInF2Actual.pitch() == Approx(qInF2Expected.pitch()));
		REQUIRE(qInF2Actual.roll() == Approx(qInF2Expected.roll()));
		REQUIRE(qInF2Actual.yaw() == Approx(qInF2Expected.yaw()));
	}

	SECTION("orientation components are correctly interpolated") {

		Orientation start(0., 0., 0.);
		Orientation middleExpected(0., pi / 2., 0.);
		Orientation end(0., pi, 0.);
		Orientation middleActual = Orientation::interpolate(start, end, 0.5);

		REQUIRE(middleActual.pitch() == Approx(middleExpected.pitch()));
		REQUIRE(middleActual.roll() == Approx(middleExpected.roll()));
		REQUIRE(middleActual.yaw() == Approx(middleExpected.yaw()));
	}
}