#include "target_state.h"

namespace Scripted6DoFFlight
{
TargetState::TargetState(Position p, Orientation o, Velocity v, Rotation r)
    : _position(p), _orientation(o), _velocity(v), _rotation(r)
{
}

double TargetState::altitude() const { return _position.altitude(); }
double TargetState::speed() const { return _velocity.speed(); }
double TargetState::groundSpeed() const { return _velocity.groundSpeed(); }

Position TargetState::position() const { return _position; }
void TargetState::setPosition(const Position &p) { _position.set(p); }
double TargetState::x() const { return _position.x(); }
double TargetState::y() const { return _position.y(); }
double TargetState::z() const { return _position.z(); }

Orientation TargetState::orientation() const { return _orientation; }
void TargetState::setOrientation(const Orientation &o) { _orientation.set(o); }
double TargetState::roll() const { return _orientation.roll(); }
double TargetState::pitch() const { return _orientation.pitch(); }
double TargetState::yaw() const { return _orientation.yaw(); }

Velocity TargetState::velocity() const { return _velocity; }
void TargetState::setVelocity(const Velocity &v) { _velocity.set(v); }
double TargetState::Vx() const { return _velocity.Vx(); }
double TargetState::Vy() const { return _velocity.Vy(); }
double TargetState::Vz() const { return _velocity.Vz(); }

Rotation TargetState::rotation() const { return _rotation; }
void TargetState::setRotation(const Rotation &r) { _rotation.set(r); }
double TargetState::rollRate() const { return _rotation.rollRate(); }
double TargetState::pitchRate() const { return _rotation.pitchRate(); }
double TargetState::yawRate() const { return _rotation.yawRate(); }

} // namespace target6Dof