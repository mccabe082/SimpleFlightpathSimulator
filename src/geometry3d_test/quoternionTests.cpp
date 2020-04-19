#include "catch.hpp"
#include <geometry3d/quaternion.h>
#include <cmath>

using namespace Geometry3D;

namespace
{
	const double pi = std::acos(-1.);
}


TEST_CASE("Quoternion arithmetic is correct", "[quoternion]") {

    SECTION("check quaternion eular angle transforms") {

		double pitch = pi/5.;
		double roll = pi/7.;
		double yaw = pi/11.;

		Quoternion q(pitch,roll,yaw);
	
		REQUIRE(q.pitch() == Approx(pitch));
        REQUIRE(q.roll() == Approx(roll));
		REQUIRE(q.yaw() == Approx(yaw));
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
	
		REQUIRE(q1+q2 == q3);
	}
	
    SECTION("quoternian multiplication is correct") {
        // https://uk.mathworks.com/help/aerotbx/ug/quatmultiply.html
		Quoternion q1(1., 0., 1., 0.);
        Quoternion q2(1., 0.5, 0.5, 0.75);
        Quoternion q3(0.5, 1.25, 1.5, 0.25);

		REQUIRE(q1*q2 == q3);
	}
	
    SECTION("quoternian scalar multiplication is correct") {
        // https://uk.mathworks.com/help/aerotbx/ug/quatmultiply.html
		Quoternion q1(1., 2., 3., 4.);
        Quoternion q2(10., 20., 30., 40.);
	
		REQUIRE(q1*10. == q2);
        REQUIRE(q2 == q1*10.);
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

	SECTION("has Norm") {
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


}