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
)

target_link_libraries(scripted6DoFEntity
  geometry3d
)