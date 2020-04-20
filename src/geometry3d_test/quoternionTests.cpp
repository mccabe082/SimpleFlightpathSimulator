#include "catch.hpp"
#include <geometry3d/quaternion.h>
#include <geometry3d/orientation.h>
#include <cmath>

using namespace Geometry3D;

namespace
{
	const double pi = std::acos(-1.);
}

TEST_CASE("Quoternion arithmetic is correct", "[quoternion]") {

	SECTION("check eular angle to quaternion transform") {

		{
			double pitch = 0.;
			double roll = 0.;
			double yaw = 0.;

			//orientation vector points equally in all positive x,y,z directions [1/|q|, 1/|q|, 1/|q|]
			Quoternion qOrientation(pitch, roll, yaw);

			//associated quoternion is orthogonal so must point in the "extra" orthogonal direction
			Quoternion qExpected(1., 0., 0., 0.);

			REQUIRE(qOrientation == qExpected);
		}
	}

	SECTION("check quaternion to eular angle transform") {

		double pitch = pi / 5.;
		double roll = pi / 7.;
		double yaw = pi / 11.;

		Quoternion q(pitch, roll, yaw);

		REQUIRE(q.pitch() == Approx(pitch));
		REQUIRE(q.roll() == Approx(roll));
		REQUIRE(q.yaw() == Approx(yaw));
	}

	SECTION("check quaternion from Orientation constructor") {

		double pitch = pi / 5.;
		double roll = pi / 7.;
		double yaw = pi / 11.;

		Quoternion q(Orientation(pitch, roll, yaw));

		REQUIRE(q.pitch() == Approx(pitch));
		REQUIRE(q.roll() == Approx(roll));
		REQUIRE(q.yaw() == Approx(yaw));
	}

	SECTION("conjugate calculation is correct") {
		Quoternion q(1., 2., 3., 4.);
		Quoternion qExpectedConj(1., -2., -3., -4.);
		REQUIRE(q.conjugate() == qExpectedConj);
	}

	SECTION("norm calculation is correct is correct") {
		Quoternion q(1., 1., 1., 1.);
		REQUIRE(q.norm() == std::sqrt(4.));
	}

	SECTION("inverse calculation is correct is correct") {
		// https://uk.mathworks.com/help/aerotbx/ug/quatinv.html
		Quoternion q(1., 0., 1., 0.);
		Quoternion qExpectedInv(0.5, 0., -0.5, 0.);
		REQUIRE(q.inverse() == qExpectedInv);
	}

	SECTION("has unity norm check") {
		double c = std::sqrt(0.25);
		Quoternion qNormEq1(c, c, c, c);
		REQUIRE(qNormEq1.hasUnityNorm());

		Quoternion qNormGt1(1., 2., 3., 4.);
		REQUIRE(!qNormGt1.hasUnityNorm());
	}

	SECTION("is a pure quoternion") {
		Quoternion qPure(0., 1., 1., 1.);
		REQUIRE(qPure.isPure());

		Quoternion qNonPure(1., 0., 0., 0.);
		REQUIRE(!qNonPure.isPure());
	}

	SECTION("equivalence check is correct") {
		Quoternion q1(1., 2., 3., 4.);
		Quoternion q2(4., 3., 2., 1.);

		REQUIRE(q1 == q1);
		REQUIRE(!(q1 == q2));
	}

	SECTION("quoternian addition is correct") {
		Quoternion q1(1., 2., 3., 4.);
		Quoternion q2(4., 3., 2., 1.);
		Quoternion q3(5., 5., 5., 5.);

		REQUIRE(q1 + q2 == q3);
	}

	SECTION("quoternian subtration is correct") {
		Quoternion q1(1., 2., 3., 4.);
		Quoternion q2(4., 3., 2., 1.);
		Quoternion q3(-3., -1., 1., 3.);

		REQUIRE(q1 - q2 == q3);
	}

	SECTION("quoternian multiplication is correct") {
		// https://uk.mathworks.com/help/aerotbx/ug/quatmultiply.html
		Quoternion q1(1., 0., 1., 0.);
		Quoternion q2(1., 0.5, 0.5, 0.75);
		Quoternion q3(0.5, 1.25, 1.5, 0.25);

		REQUIRE(q1 * q2 == q3);
	}

	SECTION("quoternian scalar multiplication is correct") {
		// https://uk.mathworks.com/help/aerotbx/ug/quatmultiply.html
		Quoternion q1(1., 2., 3., 4.);
		Quoternion q2(10., 20., 30., 40.);

		REQUIRE(q1 * 10. == q2);
		REQUIRE(10. * q1 == q2);
	}

}