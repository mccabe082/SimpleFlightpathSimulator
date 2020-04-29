add_library(SimpleWaypointSim STATIC)

target_include_directories(SimpleWaypointSim
PUBLIC
  ../../include
)

target_sources(SimpleWaypointSim
PRIVATE
  aircraft_state.cpp
  aircraft_state.h
  follow_waypoints.cpp
  follow_waypoints.h
  simple_waypoint_sim.cpp
  ../../include/simple_waypoint_sim/simple_waypoint_sim.h
  waypoint.cpp
  waypoint.h
  waypoint_queue.cpp
  waypoint_queue.h
)

target_link_libraries(SimpleWaypointSim
PRIVATE
  geometry3d
  ::RapidXML
)

# https://stackoverflow.com/questions/41308933/how-to-enable-c17-compiling-in-visual-studio
message(AUTHOR_WARNING "Need to reconsider - look at target_compile_features and target_compile_options")
target_compile_features(SimpleWaypointSim
PUBLIC
  cxx_std_17
)

target_compile_options(SimpleWaypointSim
PUBLIC
  "-std:c++17"
  "-fp:strict"
  "-fp:except"
)

set_target_properties(SimpleWaypointSim PROPERTIES
  CXX_STANDARD 17
)
