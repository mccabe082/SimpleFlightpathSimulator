add_library(physics STATIC)

target_include_directories(physics
PUBLIC
  ../../include
)

target_sources(physics
PRIVATE
  environment.h
  sealevel.h
  sealevel.cpp
)