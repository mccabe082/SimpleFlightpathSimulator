#pragma once
#include <array>

namespace Geometry3D
{
class Quoternion
{
public:
    Quoternion(double i, double j, double k, double real = 0.);
    Quoternion conjugate() const;
    double norm() const;
    Quoternion inverse() const;
    bool hasUnityNorm() const;
    bool isPure() const;

    friend Quoternion& operator+(const Quoternion& a, const Quoternion& b);
    friend Quoternion& operator*(const Quoternion& a, const Quoternion& b);
private:
    double& real();
    double& i();
    double& j();
    double& k();
    std::array<double,4> data;
};

Quoternion& operator+(const Quoternion& a, const Quoternion& b);
Quoternion& operator*(const Quoternion& a, const Quoternion& b);

} // namespace Geometry3D