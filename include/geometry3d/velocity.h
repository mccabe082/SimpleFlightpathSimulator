#pragma once
#include <array>

namespace Geometry3D
{
class Velocity
{
private:
    double Vx() const;
    double Vy() const;
    double Vz() const;
    void Velocity::set(const Velocity &v);
public:
    std::array<double, 3> data;
};
} // namespace Geometry3D