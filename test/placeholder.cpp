#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <simple_flightpath_sim/flightpath.h>

TEST_CASE("Provisional end-to-end tests", "[placeholder]" ) {

	void* handle = loadFlightpath("waypoints.xml");

    SECTION( "report project existance" ) {
        bool projectExists = true;
        REQUIRE(projectExists);
    }

}