#include "target_state.h"

namespace Scripted6DoFFlight
{
TargetState::TargetState(Position p, Orientation o, Velocity v, Rotation r)
    : Position(p), Orientation(o), Velocity(v), Rotation(r)
{
}

} // namespace target6Dof