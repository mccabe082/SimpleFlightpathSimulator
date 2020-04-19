#include "catch.hpp"
#include <geometry3d/quaternion.h>
#include <cmath>

using namespace Geometry3D;

namespace
{
	const double pi = std::acos(-1.);
}


TEST_CASE("Quoternion basic arithmetic is correct", "[quoternion_basics]") {

	SECTION("conjugate calculation is correct") {
		Quoternion q(1., 2., 3., 4.);
		Quoternion qExpectedConj(-1., -2., -3., 4.);
		REQUIRE(q.conjugate() == qExpectedConj);
	}

	SECTION("norm calculation is correct is correct") {
		Quoternion q(1., 1., 1., 1.);
		REQUIRE(q.norm() == std::sqrt(4.));
	}

	SECTION("inverse calculation is correct is correct") {
		// https://uk.mathworks.com/help/aerotbx/ug/quatinv.html
		Quoternion q(0., 1., 0., 1.);
		Quoternion qExpectedInv(0., -0.5, 0., 0.5);
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
		Quoternion qPure(1., 2., 3.);
		REQUIRE(qPure.isPure());

		Quoternion qNonPure(0.1, 1., 2., 3.);
		REQUIRE(!qNonPure.isPure());
	}


}