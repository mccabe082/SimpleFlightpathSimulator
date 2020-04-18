#include "scripted_target.h"

namespace Scripted6DoFFlight
{
Target::Target(Position p, Orientation o, Velocity v, Rotation r)
    : _position(p), _orientation(o), _velocity(v), _rotation(r)
{
}

double Target::altitude() const { return _position.altitude(); }
double Target::speed() const { return _velocity.speed(); }
double Target::groundSpeed() const { return _velocity.groundSpeed(); }

Position Target::position() const { return _position; }
void Target::setPosition(const Position &p) { _position.set(p); }
double Target::x() const { return _position.x(); }
double Target::y() const { return _position.y(); }
double Target::z() const { return _position.z(); }

Orientation Target::orientation() const { return _orientation; }
void Target::setOrientation(const Orientation &o) { _orientation.set(o); }
double Target::roll() const { return _orientation.roll(); }
double Target::pitch() const { return _orientation.pitch(); }
double Target::yaw() const { return _orientation.yaw(); }

Velocity Target::velocity() const { return _velocity; }
void Target::setVelocity(const Velocity &v) { _velocity.set(v); }
double Target::Vx() const { return _velocity.Vx(); }
double Target::Vy() const { return _velocity.Vy(); }
double Target::Vz() const { return _velocity.Vz(); }

Rotation Target::rotation() const { return _rotation; }
void Target::setRotation(const Rotation &r) { _rotation.set(r); }
double Target::rollRate() const { return _rotation.rollRate(); }
double Target::pitchRate() const { return _rotation.pitchRate(); }
double Target::yawRate() const { return _rotation.yawRate(); }

} // namespace target6Dof