#include "catch.hpp"
#include "simple_waypoint_sim/waypoint_queue.h"
#include "simple_waypoint_sim/waypoint.h"
#include <cmath>
#include <array>
#include <filesystem>

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;
using namespace SimpleWaypointSim;


TEST_CASE("Testing Waypoint_queue code", "[waypoint_queue]") {

	SECTION("Testing adding waypoints") {


		double x = 1.;

		double t1 = 10.;
		double t0 = 5.; // 5 needs to be added b4 10

		Position p(x, x, x);
		Orientation o(x, x, x);
		Waypoint wp1(p, o, t1);
		Waypoint wp0(p, o, t0);

		// Add the waypoints in the correct order
		{
			WaypointQueue wpq;

			REQUIRE(wpq.addWaypoint(wp0));
			REQUIRE(wpq.addWaypoint(wp1));
		}

		// Add the waypoints in the wrong order
		{
			WaypointQueue wpq;

			REQUIRE(wpq.addWaypoint(wp1));
			REQUIRE(!wpq.addWaypoint(wp0));
		}

	}

	SECTION("Reading waypoints from XML") {

		WaypointQueue wpq;
		std::filesystem::path temp = std::filesystem::current_path();
		WaypointQueue::readFromXML(wpq, "D:\\simple-flightpath-simulator\\src\\simple_waypoint_sim_test\\sample_waypoint_queue.xml");

		REQUIRE(wpq.nextWaypoint(0.9).has_value());
		Waypoint wp = wpq.nextWaypoint(0.9).value();
		REQUIRE(1.5 == Approx(wp.position().y()));
		REQUIRE(0.2 == Approx(wp.orientation().roll()));
	}

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