add_library(scripted6DoFFlight SHARED)

target_include_directories(scripted6DoFFlight
PUBLIC
  ../../include
)

target_sources(scripted6DoFFlight
PRIVATE
  ../../include/scripted_6dof_flight/flightpath.h
  aircraft_state.cpp
  aircraft_state.h
  enter_cruise.h
  enter_cruise.cpp
  follow_waypoints.cpp
  follow_waypoints.h
  maneuover.h
  waypoint.cpp
  waypoint.h
  waypoint_queue.cpp
  waypoint_queue.h
  flightpath.cpp
)

target_link_libraries(scripted6DoFFlight
  geometry3d
)

# https://stackoverflow.com/questions/41308933/how-to-enable-c17-compiling-in-visual-studio
message(AUTHOR_WARNING "Need to reconsider - look at target_compile_features and target_compile_options")
target_compile_features(scripted6DoFFlight
PUBLIC
  cxx_std_17
)

target_compile_options(scripted6DoFFlight
PUBLIC
  "-std:c++17"
  "-fp:strict"
  "-fp:except"
)

set_target_properties(scripted6DoFFlight PROPERTIES
  CXX_STANDARD 17
)
