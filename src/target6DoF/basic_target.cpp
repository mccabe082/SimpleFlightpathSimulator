#include "basic_target.h"

namespace target6Dof
{
    BasicTarget::BasicTarget(Position p, Orientation o, Velocity v, Rotation r)
    : position(p), orientation(o),velocity(v),rotation(r)
    {}
    
    double BasicTarget::altitude() const
    {
        return position.altitude();
    }
    
    double BasicTarget::speed() const
    {
        return velocity.speed();
    }
    
    double BasicTarget::groundSpeed() const
    {
        return velocity.groundSpeed();
    }
}