
#include "geometry3d/orientation.h"

namespace Geometry3D
{

double Orientation::pitch() const
{
    return data.at(0);
}

double Orientation::roll() const
{
    return data.at(1);
}

double Orientation::yaw() const
{
    return data.at(2);
}

void Orientation::set(const Orientation& o)
{
    data=o.data;
}

} // namespace Geometry3D