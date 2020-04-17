add_library(geometry3d STATIC)

target_include_directories(geometry3d
PUBLIC
  ../../include
)

target_sources(geometry3d
PRIVATE
  orientation.cpp
  orientation.h
  position.cpp
  position.h
  rotation.cpp
  rotation.h
  velocity.cpp
  velocity.h
)