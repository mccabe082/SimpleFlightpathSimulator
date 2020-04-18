#pragma once
#include <array>

namespace Geometry3D
{
class Velocity
{
public:
    Velocity(double x, double y, double z);
    double Vx() const;
    double Vy() const;
    double Vz() const;
    void set(const Velocity &v);
    double heading() const;
    double speed() const;
    double groundSpeed() const;
private:
    std::array<double, 3> data;
};
} // namespace Geometry3D