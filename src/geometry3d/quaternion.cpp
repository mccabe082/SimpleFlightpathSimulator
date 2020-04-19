#include "geometry3d/quaternion.h"
#include <numeric>
#include <limits>

namespace Geometry3D
{

    Quoternion::Quoternion(double i, double j, double k, double real)
    : data(std::array<double,4>{i,j,k,real})
    {}

    Quoternion Quoternion::conjugate() const
    {
        Quoternion conj(*this);
        conj.i()*=-1.;
        conj.j()*=-1.;
        conj.k()*=-1.;
        return conj;
    }

    double Quoternion::norm() const
    {
        return std::sqrt(std::inner_product(data.begin(), data.end(), data.begin(), 0.0));
    }

    Quoternion Quoternion::inverse() const
    {
        Quoternion inv = conjugate();
        double nSquared = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
        inv.real()*=nSquared;
        inv.i()*=nSquared;
        inv.j()*=nSquared;
        inv.k()*=nSquared;
        return ;
    }

    bool Quoternion::hasUnityNorm() const
    {
        return abs(1.-norm()) <= std::numeric_limits<double>::epsilon();
    }

    bool Quoternion::isPure() const
    {
        return abs(data[3]/*real()*/) <= std::numeric_limits<double>::epsilon();
    }


    double& Quoternion::real(){return data[4];}
    double& Quoternion::i(){return data[0];}
    double& Quoternion::j(){return data[1];}
    double& Quoternion::k(){return data[2];}
    
};

Quoternion& operator+(const Quoternion& a, const Quoternion& b)
{
    Quoternion sum;
    sum.real() = a.real()+b.real();
    sum.x() = a.x()+b.x();
    sum.y() = a.y()+b.y();
    sum.z() = a.z()+b.z();
    return sum;
}

Quoternion& operator*(const Quoternion& a, const Quoternion& b)
{
    double ar = a.real(); double ai = a.i(); double aj = a.j();double ak = a.k();
    double br = b.real(); double bi = b.i(); double bj = b.j();double bk = b.k();

    Quoternion product;
    product.real() = ar*br-ai*bi-aj*bj-ak*bk;
    product.x()    = ar*bi+ai*br+aj*bk-ak*bj;
    product.y()    = ar*bj+aj*br-ai*bk+ak*bi;
    product.z()    = ar*bk+ak*br+ai*bj+aj*bi;
    return sum;
}

} // namespace Geometry3D