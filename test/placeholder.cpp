#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Provisional end-to-end tests", "[placeholder]" ) {

    SECTION( "report project existance" ) {
        bool projectExists = true;
        REQUIRE(projectExists);
    }

}