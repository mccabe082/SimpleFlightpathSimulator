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

	double clampBetweenPlusOrMinus180Degrees(double alpha)
	{
		alpha = fmod(alpha, 2. * pi);
		if (alpha > pi) alpha -= pi;
		return alpha;
	}

	double rad2deg(double alpha)
	{
		return 180. * alpha / pi;
	}
}

using namespace Geometry3D;
using namespace SimpleWaypointSim;

TEST_CASE("Testing Follow Waypoint code", "[follow waypoints]") {

	double xVelocity = 40.;
	double rollRate = pi / 8.;

	Geometry3D::Velocity vel(xVelocity, 0., 0.);
	Geometry3D::Rotation rot(0., rollRate, 0.);
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

		double time = 1.5;
		aircraft = barrelRoll.update(time, 0., aircraft);

		double xDist = xVelocity * time;
		double rollDist = clampBetweenPlusOrMinus180Degrees(rollRate * time);

		REQUIRE(aircraft.rollRate() == Approx(rollRate));

		REQUIRE(aircraft.x() == Approx(xDist));
		REQUIRE(aircraft.y() == Approx(0.));
		REQUIRE(aircraft.z() == Approx(0.));

		REQUIRE(aircraft.roll() == Approx(rollDist));
		REQUIRE(aircraft.pitch() == Approx(0.));
		REQUIRE(aircraft.yaw() == Approx(0.));
	}

	SECTION("Test going through a bunch of waypoints") {

		double time = 45.;
		aircraft = barrelRoll.update(time, 0., aircraft);

		double xDist = xVelocity * time;
		double rollDist = clampBetweenPlusOrMinus180Degrees(rollRate * time);


		REQUIRE(aircraft.x() == Approx(xDist));
		REQUIRE(aircraft.y() == Approx(0.));
		REQUIRE(aircraft.z() == Approx(0.));

		REQUIRE(aircraft.roll() == Approx(rollDist));
		REQUIRE(aircraft.pitch() == Approx(0.));
		REQUIRE(aircraft.yaw() == Approx(0.));
	}

	SECTION("Testing aircraft reaching final waypoint waypoints") {

		// TODO
		REQUIRE(false);
	}


}