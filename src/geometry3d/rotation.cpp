
#include "orientation3d.h"

namespace Geometry3D
{
double Rotation::pitch() const
{
    return data.at(0);
}

double Rotation::roll() const
{
    return data.at(1);
}

double Rotation::yaw() const
{
    return data.at(2);
}
} // namespace Geometry3D