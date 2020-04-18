#pragma once

#include "sealevel.h"

namespace physics
{   
	double SeaLevel::gravity(double /*altitude*/) const
    {
        return 9.81; // acceleration due to gravity [m/s/s]
    };
}