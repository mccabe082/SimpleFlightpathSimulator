#pragma once
#include <array>

namespace Geometry3D
{
class Position
{
public:
    double x() const;
    double y() const;
    double z() const;

private:
    std::array<double, 3> data;
};
} // namespace Geometry3D