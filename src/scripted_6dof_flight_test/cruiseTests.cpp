#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "scripted_6dof_flight/enter_cruise.h"
#include <cmath>

namespace
{
	const double pi = std::acos(-1.);
}

using namespace Geometry3D;
using namespace Scripted6DoFFlight;

TEST_CASE("aircraft smoothly enters a cruise", "[enter_cruise]" ) {

    SECTION( "transition from climb to level flight" ) {
        
    }

    SECTION( "transition from turn to level flight" ) {
        
    }

    SECTION( "forward to backward cruise" ) {
        
    }

    
}