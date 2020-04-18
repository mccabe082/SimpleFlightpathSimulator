add_library(scripted6DoFTarget STATIC)

target_include_directories(scripted6DoFTarget
PUBLIC
  ../../include
)

target_sources(scripted6DoFTarget
PRIVATE
  scripted_target.cpp
  scripted_target.h
)

target_link_libraries(scripted6DoFTarget
  geometry3d
)