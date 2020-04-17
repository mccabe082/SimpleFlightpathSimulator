add_library(physics STATIC)

target_include_directories(physics
PUBLIC
  ../../include
)

target_sources(physics
PRIVATE
  ../../include/physics/environment.h
  ../../include/physics/sealevel.h
  sealevel.cpp
  
)