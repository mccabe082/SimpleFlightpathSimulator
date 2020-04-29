#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "simple_waypoint_sim/follow_waypoints.h"
#include "simple_waypoint_sim/waypoint_queue.h"
#include <cmath>

#include <geometry3d/position.h>
#include <geometry3d/velocity.h>
#include <geometry3d/orientation.h>
#include <geometry3d/rotation.h>

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;
using namespace SimpleWaypointSim;

TEST_CASE("Testing Follow Waypoint code", "[follow waypoints]") {

	Geometry3D::Velocity vel(40., 0., 0.);
	Geometry3D::Rotation rot(0., pi / 8., 0.);
	Geometry3D::Position pos(0., 0., 0.);
	Geometry3D::Orientation ori(0., 0., 0.);

	AircraftState aircraft(pos, ori, vel, rot);

	WaypointQueue CorkScrew;
	{
		double tSim = 0.;
		double tWaypoint = 3.;

		// prepare waypoints
		for (auto i = 0; i <= 20; ++i)
		{
			tSim += tWaypoint;
			pos = pos.update(vel, tWaypoint);
			ori = ori.update(rot, tWaypoint);
			CorkScrew.addWaypoint(Waypoint(pos, ori, tSim));
		}
	}

	FollowWaypoints barrelRoll(CorkScrew);

	SECTION("Test midpoint between first two waypoints") {

		aircraft = barrelRoll.update(1.5, 0., aircraft);

		REQUIRE(aircraft.x() == Approx(40. * 1.5));
		REQUIRE(aircraft.y() == Approx(0.));
		REQUIRE(aircraft.z() == Approx(0.));

		REQUIRE(aircraft.roll() == Approx(pi / 8. * 1.5).epsilon(0.1));
		REQUIRE(aircraft.pitch() == Approx(0.));
		REQUIRE(aircraft.yaw() == Approx(0.));
	}

	SECTION("Test going through a bunch of waypoints") {

		aircraft = barrelRoll.update(3.*15., 0., aircraft);

		REQUIRE(aircraft.x() == Approx(40. * 15.));
		REQUIRE(aircraft.y() == Approx(0.));
		REQUIRE(aircraft.z() == Approx(0.));

		REQUIRE(aircraft.roll() == Approx(pi / 8. * 15.));
		REQUIRE(aircraft.pitch() == Approx(0.));
		REQUIRE(aircraft.yaw() == Approx(0.));
	}

	SECTION("Testing aircraft reaching final waypoint waypoints") {

		//Waypoint wp(p, o, t);
		//
		//REQUIRE(p.x() == Approx(wp.position().x()));
		//REQUIRE(p.y() == Approx(wp.position().y()));
		//REQUIRE(p.z() == Approx(wp.position().z()));
		//
		//REQUIRE(o.pitch() == Approx(wp.orientation().pitch()));
		//REQUIRE(o.roll() == Approx(wp.orientation().roll()));
		//REQUIRE(o.yaw() == Approx(wp.orientation().yaw()));
		//
		//REQUIRE(t == Approx(wp.arrivalTime()));
	}


}