#include "catch.hpp"
#include "simple_waypoint_sim/waypoint.h"
#include <cmath>
#include <geometry3d/position.h>
#include <geometry3d/velocity.h>


namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;
using namespace SimpleWaypointSim;

TEST_CASE("Testing Waypoint code", "[waypoint]") {

	Position p(1., 1., 1.);
	Orientation o(pi / 4., pi / 4., pi / 4.);
	double t = 10.;

	SECTION("Testing Waypoint construction and basic accessors") {

		Waypoint wp(p, o, t);

		REQUIRE(p.x() == Approx(wp.position().x()));
		REQUIRE(p.y() == Approx(wp.position().y()));
		REQUIRE(p.z() == Approx(wp.position().z()));

		REQUIRE(o.pitch() == Approx(wp.orientation().pitch()));
		REQUIRE(o.roll() == Approx(wp.orientation().roll()));
		REQUIRE(o.yaw() == Approx(wp.orientation().yaw()));

		REQUIRE(t == Approx(wp.arrivalTime()));
	}


}