#include "catch.hpp"
#include "scripted_6dof_flight/waypoint_queue.h"
#include "scripted_6dof_flight/waypoint.h"
#include <cmath>
#include <array>
/*
	void addWaypoint(const Waypoint& newWP);
	std::optional<Waypoint> nextWaypoint(double simTime) const;
	unsigned waypointsRemaining(double simTime) const;
*/

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;
using namespace Scripted6DoFFlight;

TEST_CASE("Testing Waypoint_queue code", "[waypoint_queue]") {

	SECTION("Testing nominal cases") {

		WaypointQueue wpq;

		std::array<double, 4> vals = { .1,.2,.3,.4 };

		for (auto val : vals)
		{
			Position p(val, val, val);
			Orientation o(val, val, val);
			Waypoint wp(p, o, val);
			wpq.addWaypoint(wp);
		}

		unsigned int remainingWaypoints = 4;
		for (auto val : vals)
		{
			double tBefore = val - .05; // { .05,.15,.25,.35 };

			REQUIRE(wpq.nextWaypoint(tBefore).has_value());
			Waypoint wp = wpq.nextWaypoint(tBefore).value();

			REQUIRE(val == Approx(wp.position().x()));
			REQUIRE(val == Approx(wp.position().y()));
			REQUIRE(val == Approx(wp.position().z()));

			REQUIRE(val == Approx(wp.orientation().pitch()));
			REQUIRE(val == Approx(wp.orientation().roll()));
			REQUIRE(val == Approx(wp.orientation().yaw()));

			REQUIRE(val == Approx(wp.arrivalTime()));

			REQUIRE(remainingWaypoints == wpq.waypointsRemaining(tBefore));
			remainingWaypoints -= 1;
		}

	}

	SECTION("Testing edge cases") {

		WaypointQueue wpq;

		std::array<double, 4> vals = { .1,.2,.3,.4 };

		for (auto val : vals)
		{
			Position p(val, val, val);
			Orientation o(val, val, val);
			Waypoint wp(p, o, val);
			wpq.addWaypoint(wp);
		}

		unsigned int remainingWaypoints = 4;
		for (auto val : vals)
		{
			double tBefore = val - .1; // { .0,.1,.2,.3 };

			REQUIRE(wpq.nextWaypoint(tBefore).has_value());
			Waypoint wp = wpq.nextWaypoint(tBefore).value();

			REQUIRE(val == Approx(wp.position().x()));
			REQUIRE(val == Approx(wp.position().y()));
			REQUIRE(val == Approx(wp.position().z()));

			REQUIRE(val == Approx(wp.orientation().pitch()));
			REQUIRE(val == Approx(wp.orientation().roll()));
			REQUIRE(val == Approx(wp.orientation().yaw()));

			REQUIRE(val == Approx(wp.arrivalTime()));

			REQUIRE(remainingWaypoints == wpq.waypointsRemaining(tBefore));
			remainingWaypoints -= 1;
		}

	}

}