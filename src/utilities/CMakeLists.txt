add_library(Utilities STATIC)

target_include_directories(Utilities
PUBLIC
  ../../include
)

target_sources(Utilities
PRIVATE
  ../../include/utilities/angle_utils.h
  ./angle_utils.cpp
  ./division_utils.cpp
  ./division_utils.h
)