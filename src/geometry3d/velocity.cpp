
#include "geometry3d/velocity.h"

namespace Geometry3D
{

double Velocity::Vx() const
{
    return data.at(0);
}

double Velocity::Vy() const
{
    return data.at(1);
}

double Velocity::Vz() const
{
    return data.at(2);
}

void Velocity::set(const Velocity &v)
{
    data = v.data;
}

} // namespace Geometry3D