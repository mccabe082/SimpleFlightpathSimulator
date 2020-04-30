#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <flightpath.h>

TEST_CASE("Provisional end-to-end tests", "[end-to-end]" ) {

	void* iSim = loadFlightpathSim("example_waypoint_queue.xml");

    SECTION( "basic check to ensure library runs end-to-end" ) {

        REQUIRE(iSim);

    	double x, y, z;
	    double pitch, roll, yaw;

		bool status_ok = true;
		
		status_ok = advanceWaypointSim(iSim, 0.5, x, y, z, pitch, roll, yaw);

		REQUIRE(x == Approx(1.));
		REQUIRE(y == Approx(1.5));
		REQUIRE(z == Approx(.0));
		REQUIRE(roll == Approx(.15));
		REQUIRE(pitch == Approx(.0));
		REQUIRE(yaw == Approx(.0));

		status_ok = advanceWaypointSim(iSim, 0.5, x, y, z, pitch, roll, yaw);

		REQUIRE(x == Approx(1.5));
		REQUIRE(y == Approx(1.5));
		REQUIRE(z == Approx(.0));
		REQUIRE(roll == Approx(.2));
		REQUIRE(pitch == Approx(.0));
		REQUIRE(yaw == Approx(.0));

		status_ok = advanceWaypointSim(iSim, 0.5, x, y, z, pitch, roll, yaw);

		REQUIRE(x == Approx(2.));
		REQUIRE(y == Approx(1.5));
		REQUIRE(z == Approx(.0));
		REQUIRE(roll == Approx(.25));
		REQUIRE(pitch == Approx(.0));
		REQUIRE(yaw == Approx(.0));

    }

}