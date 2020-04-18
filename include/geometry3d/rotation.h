#pragma once
#include <array>

namespace Geometry3D
{
class Rotation
{
public:
    double pitchRate() const;
    double rollRate() const;
    double yawRate() const;
    void set(const Rotation& omega);
private:
    std::array<double, 3> data;
};
} // namespace Geometry3D