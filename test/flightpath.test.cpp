#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <flightpath.h>

TEST_CASE("Provisional end-to-end tests", "[placeholder]" ) {

	void* handle = loadFlightpathSim("sillyTest.xml");

    SECTION( "report project existance" ) {
        bool projectExists = true;
        REQUIRE(projectExists);
    }

}