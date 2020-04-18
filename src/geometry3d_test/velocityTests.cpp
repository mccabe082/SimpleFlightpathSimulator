#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <geometry3d/velocity.h>

TEST_CASE( "Speeds are calulated correctly", "[Speed]" ) {

    SECTION( "velocity components can be set and accessed" ) {
        Geometry3D::Velocity target(0.0,0.0,0.0);
        target.set(Geometry3D::Velocity(1.,2.,3.));
        REQUIRE( target.Vx() == Approx(1.) );
        REQUIRE( target.Vy() == Approx(2.) );
        REQUIRE( target.Vz() == Approx(3.) );
    }
    SECTION( "true air speed calculation is correct" ) {
        Geometry3D::Velocity targetV(1.,1.,1.);
        REQUIRE( targetV.speed() == Approx(std::sqrt(3)));
    }
    SECTION( "ground speed calulation is correct" ) {
        Geometry3D::Velocity triangle_3_4_5(3.,4.,1.);
        REQUIRE( triangle_3_4_5.groundSpeed() == Approx(5.) );
    }
}