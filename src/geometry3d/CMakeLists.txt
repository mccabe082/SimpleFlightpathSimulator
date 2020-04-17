add_library(geometry3d STATIC)

target_include_directories(geometry3d
PUBLIC
  ../../include
)

target_sources(geometry3d
PUBLIC
  orientation.h
  position.h
  rotation.h
  velocity.h
PRIVATE
  orientation.cpp
  position.cpp
  rotation.cpp
  velocity.cpp
)