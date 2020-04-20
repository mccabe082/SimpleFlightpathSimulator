#include "catch.hpp"
#include <geometry3d/orientation.h>
#include <cmath>

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;

TEST_CASE( "Orientation interpolation is calulated correctly", "[orientation]" ) {

    SECTION( "orientation components are correctly interpolated" ) {
        
        Orientation start(0.,0.,0.);
        Orientation middleExpected(0.,pi/2.,0.);
        Orientation end(0.,pi,0.);
        Orientation middleActual = interpolate(start,end,0.5);

        REQUIRE( middleActual.pitch() == Approx(middleExpected.pitch())) ;
        REQUIRE( middleActual.roll() == Approx(middleExpected.roll())) ;
        REQUIRE( middleActual.yaw() == Approx(middleExpected.yaw())) ;
    }
}