#include "aircraft_state.h"

namespace Scripted6DoFFlight
{
AircraftState::AircraftState(Position p, Orientation o, Velocity v, Rotation r) :
Position(p), Orientation(o), Velocity(v), Rotation(r)
{}

} // namespace target6Dof