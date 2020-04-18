#pragma once

#include "basic_target.h"

namespace target6Dof
{
    double BasicTarget::altitude() const 
    {
        return z();
    }
}