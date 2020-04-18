#include "basic_target.h"

namespace target6Dof
{
ScriptedTarget::ScriptedTarget(Position p, Orientation o, Velocity v, Rotation r)
    : position(p), orientation(o), velocity(v), rotation(r)
{}

double ScriptedTarget::altitude() const { return position.altitude(); }
double ScriptedTarget::speed() const { return velocity.speed(); }
double ScriptedTarget::groundSpeed() const { return velocity.groundSpeed(); }

double ScriptedTarget::x() const { return position.x; }
double ScriptedTarget::y() const { return position.y; }
double ScriptedTarget::z() const { return position.z; }

double ScriptedTarget::roll() const { return orientation.roll(); }
double ScriptedTarget::pitch() const { return orientation.pitch(); }
double ScriptedTarget::yaw() const { return orientation.yaw(); }

double ScriptedTarget::Vx() const { return velocity.Vx; }
double ScriptedTarget::Vy() const { return velocity.Vy; }
double ScriptedTarget::Vz() const { return velocity.Vz; }

double ScriptedTarget::rollRate() const { return rotation.rollRate(); }
double ScriptedTarget::pitchRate() const { return rotation.pitchRate(); }
double ScriptedTarget::yawRate() const { return rotation.yawRate(); }

} // namespace target6Dof