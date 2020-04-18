#pragma once
#include <array>

namespace Geometry3D
{
class Position
{
public:
    double x() const; // northward
    double y() const; // eastward
    double z() const;
    double altitude() const;
    void set(const Position& p);

private:
    std::array<double, 3> data;
};
} // namespace Geometry3D