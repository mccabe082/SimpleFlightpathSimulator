#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <geometry3d/velocity.h>
#include <geometry3d/position.h>
#include <cmath>

namespace
{
	const double pi = std::acos(-1.);
}

TEST_CASE("Speeds are calulated correctly", "[velocity]") {

	SECTION("velocity components can be set and accessed") {
		Geometry3D::Velocity target(1., 2.0, 3.0);
		REQUIRE(target.Vx() == Approx(1.));
		REQUIRE(target.Vy() == Approx(2.));
		REQUIRE(target.Vz() == Approx(3.));
	}

	SECTION("fixed (earth) reference speed calculation is correct") {
		Geometry3D::Velocity targetV(1., 1., 1.);
		REQUIRE(targetV.speed() == Approx(std::sqrt(3)));
	}

	SECTION("ground speed calulation is correct") {
		Geometry3D::Velocity triangle_3_4_5(3., 4., 1.);
		REQUIRE(triangle_3_4_5.groundSpeed() == Approx(5.));
	}

	SECTION("heading calulation is correct") {
		const double bearingNE = 0.25 * pi;
		Geometry3D::Velocity boundNorthEast(1., 1., 0.);
		REQUIRE(boundNorthEast.heading() == Approx(bearingNE));

		const double bearingSE = 0.75 * pi;
		Geometry3D::Velocity boundSouthEast(1., -1., 0.);
		REQUIRE(boundSouthEast.heading() == Approx(bearingSE));

		const double bearingSW = -0.75 * pi;
		Geometry3D::Velocity boundSouthWest(-1., -1., 0.);
		REQUIRE(boundSouthWest.heading() == Approx(bearingSW));

		const double bearingNW = -0.25 * pi;
		Geometry3D::Velocity boundNorthWest(-1., 1., 0.);
		REQUIRE(boundNorthWest.heading() == Approx(bearingNW));
	}

	SECTION("ground vector calulation is correct") {
		Geometry3D::Velocity v(1., 1., 1.);
		Geometry3D::Velocity vGroundExpected(1., 1., 0.);
		Geometry3D::Velocity vGroundEActual = v.groundVector();

		REQUIRE(v.Vx() == Approx(v.Vx()));
		REQUIRE(v.Vy() == Approx(v.Vy()));
		REQUIRE(v.Vz() == Approx(v.Vz()));
	}

	SECTION("interpolation calulation is correct") {
		Geometry3D::Velocity v0(0., 0., 0.);
		Geometry3D::Velocity v1(1., 1., 1.);
		Geometry3D::Velocity vMidExpected(.5, .5, .5);
		Geometry3D::Velocity vMidEActual = Geometry3D::Velocity::interpolate(v1, v0, 0.5);

		REQUIRE(vMidExpected.Vx() == Approx(vMidEActual.Vx()));
		REQUIRE(vMidExpected.Vy() == Approx(vMidEActual.Vy()));
		REQUIRE(vMidExpected.Vz() == Approx(vMidEActual.Vz()));
	}

	SECTION("distance/time calulation is correct") {
		Geometry3D::Position p0(0., 0., 0.);
		Geometry3D::Position p1(1., 1., 1.);
		Geometry3D::Velocity vExpected(2., 2., 0.);
		Geometry3D::Velocity vEActual = Geometry3D::Velocity::from(p0, p1, 0.5);

		REQUIRE(vExpected.Vx() == Approx(vEActual.Vx()));
		REQUIRE(vExpected.Vy() == Approx(vEActual.Vy()));
		REQUIRE(vExpected.Vz() == Approx(vEActual.Vz()));
	}

}