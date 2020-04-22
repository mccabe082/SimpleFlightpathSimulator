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
		Rotation r2(degPerSec4pt5, degPerSec4pt5, degPerSec4pt5);
		Rotation rExpected(degPerSec4pt5/2., degPerSec4pt5/2., degPerSec4pt5/2.);
		Rotation rActual = Rotation::interpolate(r1,r2,0.5);

		REQUIRE(r1.pitchRate() == Approx(r2.pitchRate()));
		REQUIRE(r1.rollRate() == Approx(r2.rollRate()));
		REQUIRE(r1.yawRate() == Approx(r2.yawRate()));
	}

		// static Rotation interpolate(const Rotation& start, const Rotation & final, double frac);
		// static Rotation from(const Orientation& oStart, const Orientation& oFinal, double time);
		// static Rotation average(const Rotation& start, const Rotation & final

}