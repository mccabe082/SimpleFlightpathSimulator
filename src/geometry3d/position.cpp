
#include "geometry3d/position.h"

namespace Geometry3D
{
double Position::x() const
{
    return data[0];
}

double Position::y() const
{
    return data[1];
}

double Position::z() const
{
    return data[2];
}

double Position::altitude() const 
{
    return z();
}


} // namespace Geometry3D