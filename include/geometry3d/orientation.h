#pragma once
#include <array>
#include <memory>

namespace Geometry3D
{
class Quoternion;

class Orientation
{
public:
    Orientation(double pitch, double roll, double yaw);
	Orientation(const Orientation& other);
    double pitch() const;
    double roll() const;
    double yaw() const;

private:
    std::unique_ptr<Quoternion> pData;
};
} // namespace Geometry3D