add_library(scripted6DoFTarget STATIC)

target_include_directories(scripted6DoFTarget
PUBLIC
  ../../include
)

target_sources(scripted6DoFTarget
PRIVATE
  maneuover.h
  target_state.cpp
  target_state.h
)

target_link_libraries(scripted6DoFTarget
  geometry3d
)