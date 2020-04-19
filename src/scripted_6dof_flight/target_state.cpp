#include "target_state.h"

#include <geometry3d/quaternion.h> // WHY?!
namespace Scripted6DoFFlight
{
TargetState::TargetState(Position p, Orientation o, Velocity v, Rotation r)
    : Position(p), Orientation(o), Velocity(v), Rotation(r)
{}

} // namespace target6Dof