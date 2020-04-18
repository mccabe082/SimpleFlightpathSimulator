#include "scripted_target.h"

namespace target6Dof
{
ScriptedTarget::ScriptedTarget(Position p, Orientation o, Velocity v, Rotation r)
    : _position(p), _orientation(o), _velocity(v), _rotation(r)
{
}

double ScriptedTarget::altitude() const { return _position.altitude(); }
double ScriptedTarget::speed() const { return _velocity.speed(); }
double ScriptedTarget::groundSpeed() const { return _velocity.groundSpeed(); }

Position ScriptedTarget::position() const { return _position; }
void ScriptedTarget::setPosition(const Position &p) { _position.set(p); }
double ScriptedTarget::x() const { return _position.x(); }
double ScriptedTarget::y() const { return _position.y(); }
double ScriptedTarget::z() const { return _position.z(); }

Orientation ScriptedTarget::orientation() const { return _orientation; }
void ScriptedTarget::setOrientation(const Orientation &o) { _orientation.set(o); }
double ScriptedTarget::roll() const { return _orientation.roll(); }
double ScriptedTarget::pitch() const { return _orientation.pitch(); }
double ScriptedTarget::yaw() const { return _orientation.yaw(); }

Velocity ScriptedTarget::velocity() const { return _velocity; }
void ScriptedTarget::setVelocity(const Velocity &v) { _velocity.set(v); }
double ScriptedTarget::Vx() const { return _velocity.Vx(); }
double ScriptedTarget::Vy() const { return _velocity.Vy(); }
double ScriptedTarget::Vz() const { return _velocity.Vz(); }

Rotation ScriptedTarget::rotation() const { return _rotation; }
void ScriptedTarget::setRotation(const Rotation &r) { _rotation.set(r); }
double ScriptedTarget::rollRate() const { return _rotation.rollRate(); }
double ScriptedTarget::pitchRate() const { return _rotation.pitchRate(); }
double ScriptedTarget::yawRate() const { return _rotation.yawRate(); }

} // namespace target6Dof