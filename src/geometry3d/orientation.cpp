
#include "geometry3d/orientation.h"
#include "geometry3d/quaternion.h"

namespace Geometry3D
{
Orientation::Orientation(double pitch, double roll, double yaw)
: pData(std::make_unique<Quoternion>(pitch,roll,yaw))
{}


Orientation::Orientation(const Orientation& other)
: pData(std::make_unique<Quoternion>(other.pitch(), other.roll(), other.yaw()))
{}


double Orientation::pitch() const
{
    return pData->pitch();
}

double Orientation::roll() const
{
    return pData->roll();
}

double Orientation::yaw() const
{
    return pData.get()->yaw();
}

} // namespace Geometry3D