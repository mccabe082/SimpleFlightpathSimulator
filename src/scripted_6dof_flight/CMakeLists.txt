add_library(scripted6DoFEntity STATIC)

target_include_directories(scripted6DoFEntity
PUBLIC
  ../../include
)

target_sources(scripted6DoFEntity
PRIVATE
  enter_cruise.h
  enter_cruise.cpp
  maneuover.h
  aircraft_state.cpp
  aircraft_state.h
)

target_link_libraries(scripted6DoFEntity
  geometry3d
)