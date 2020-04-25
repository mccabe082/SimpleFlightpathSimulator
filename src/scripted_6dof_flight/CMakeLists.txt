add_library(scripted6DoFEntity STATIC)

target_include_directories(scripted6DoFEntity
PUBLIC
  ../../include
)

target_sources(scripted6DoFEntity
PRIVATE
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
)

target_link_libraries(scripted6DoFEntity
  geometry3d
)

message(AUTHOR_WARNING "Need to reconsider - look at target_compile_features and target_compile_options")
set_target_properties(scripted6DoFEntity PROPERTIES
  CXX_STANDARD 17
)
