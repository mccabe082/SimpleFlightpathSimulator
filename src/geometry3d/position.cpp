
#include "position3d.h"

namespace Geometry3D
{
double Position::x() const
{
    return data.at(0);
}

double Position::y() const
{
    return data.at(1);
}

double Position::z() const
{
    return data.at(2);
}

} // namespace Geometry3D