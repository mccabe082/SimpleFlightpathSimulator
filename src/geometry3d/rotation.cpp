
#include "geometry3d/rotation.h"

namespace Geometry3D
{
double Rotation::pitchRate() const
{
    return data.at(0);
}

double Rotation::rollRate() const
{
    return data.at(1);
}

double Rotation::yawRate() const
{
    return data.at(2);
}
} // namespace Geometry3D