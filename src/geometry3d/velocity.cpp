
#include "geometry3d/velocity.h"
#include <numeric>
#include <cmath>

namespace Geometry3D
{
Velocity::Velocity(double x, double y, double z)
: data{x,y,z}
{}

double Velocity::Vx() const
{
    return data.at(0);
}

double Velocity::Vy() const
{
    return data.at(1);
}

double Velocity::Vz() const
{
    return data.at(2);
}

double Velocity::heading() const
{
    return atan2(Vx(), Vy());
}

double Velocity::speed() const
{
	return std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0));
}

double Velocity::groundSpeed() const
{
	return std::sqrt(pow(Vx(),2)+ pow(Vy(), 2));
}

} // namespace Geometry3D