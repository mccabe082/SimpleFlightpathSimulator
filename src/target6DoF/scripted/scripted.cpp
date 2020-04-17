#pragma once

#include "scripted.h"

namespace target6Dof
{
    double scripted::altitude() const 
    {
        return z();
    }
}