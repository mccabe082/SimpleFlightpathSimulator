#include "catch.hpp"
#include <geometry3d/orientation.h>
#include <geometry3d/rotation.h>
#include <cmath>

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;

TEST_CASE("Orientations are always valid", "[attitude constraints]") {

	const double deg360 = 2. * pi;
	const double deg180 = pi;
	const double deg90 = pi / 2.;
	const double deg45 = pi / 4.;

	SECTION("Roll constraint") {
		{
			double expected = deg45;
			double input = deg45 + deg360;
			Orientation attitude(0., input, 0.);

			REQUIRE(expected == Approx(attitude.roll()));
		}
		{
			double expected = -deg45;
			double input = -deg45 - deg360;
			Orientation attitude(0., input, 0.);

			REQUIRE(expected == Approx(attitude.roll()));
		}
	}

	SECTION("pitch constraint") {
		{
			// Use the following applet to view the input and expected
			// http://www.ctralie.com.s3-website-us-east-1.amazonaws.com/Teaching/COMPSCI290/Materials/EulerAnglesViz/

			double expectedPitch = -deg45;
			double expectedRoll = -deg180;
			double expectedYaw = -deg180;
			double input = deg45 + deg180;
			Orientation attitude(input, 0., 0.);

			REQUIRE(expectedPitch == Approx(attitude.pitch()));
			REQUIRE(expectedRoll == Approx(attitude.roll()));
			REQUIRE(expectedYaw == Approx(attitude.yaw()));
		}
		{
			double inputPitch = -deg45 + deg180;
			double expectedPitch = deg45;
			double inputRoll = deg45;
			double expectedRoll = -deg180 + deg45/*deg45 + deg180*/;
			double inputYaw = deg45;
			double expectedYaw = -deg180 + deg45/*deg45 + deg180*/;

			Orientation attitude(inputPitch, inputRoll, inputYaw);

			REQUIRE(expectedPitch == Approx(attitude.pitch()));
			REQUIRE(expectedRoll == Approx(attitude.roll()));
			REQUIRE(expectedYaw == Approx(attitude.yaw()));
		}
	}

	SECTION("yaw constraint") {
		double expected = deg45;
		double input = deg45 + deg180;
		Orientation attitude(0., 0., 0.);


		REQUIRE(attitude.yaw() == Approx(attitude.yaw()));
	}
}

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
		Orientation middleExpected(0., pi / 4., 0.);
		Orientation end(0., pi / 2., 0.);
		Orientation middleActual = Orientation::interpolate(start, end, 0.5);

		REQUIRE(middleActual.pitch() == Approx(middleExpected.pitch()));
		REQUIRE(middleActual.roll() == Approx(middleExpected.roll()));
		REQUIRE(middleActual.yaw() == Approx(middleExpected.yaw()));
	}

	SECTION("rotational velocity calculation is correct") {

		Orientation before(0., 0., 0.);
		Rotation omega(0., pi / 2., 0.);
		Orientation afterExpected(0., pi / 2., 0.);
		Orientation afterActual = before.update(omega, 1.0);

		REQUIRE(afterExpected.pitch() == Approx(afterActual.pitch()));
		REQUIRE(afterExpected.roll() == Approx(afterActual.roll()));
		REQUIRE(afterExpected.yaw() == Approx(afterActual.yaw()));
	}

}