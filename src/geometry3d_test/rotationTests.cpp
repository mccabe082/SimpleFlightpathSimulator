#include "catch.hpp"
#include <geometry3d/rotation.h>
#include <geometry3d/quaternion.h>
#include <cmath>

using namespace Geometry3D;

namespace
{
	const double pi = std::acos(-1.);
}

TEST_CASE("Rotation arithmetic is correct", "[rotation]") {

	SECTION("interpolation works correctly") {
		
        const double degPerSec4pt5 = pi / 40.;

		Rotation r1(0., 0., 0.);
		Rotation r2(0., degPerSec4pt5, 0.);
		Rotation rExpected(0., degPerSec4pt5/2., 0.);
		Rotation rActual = Rotation::interpolate(r1,r2,0.5);

		REQUIRE(rExpected.pitchRate() == Approx(rActual.pitchRate()));
		REQUIRE(rExpected.rollRate() == Approx(rActual.rollRate()));
		REQUIRE(rExpected.yawRate() == Approx(rActual.yawRate()));
	}


		// static Rotation from(const Orientation& oStart, const Orientation& oFinal, double time);
		// static Rotation average(const Rotation& start, const Rotation & final

}