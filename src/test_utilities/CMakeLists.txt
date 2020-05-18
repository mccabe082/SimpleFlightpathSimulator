add_library(TestUtilities STATIC)

target_sources(TestUtilities
PRIVATE
  ./angle_utils.cpp
  ./angle_utils.h
  ./division_utils.cpp
  ./division_utils.h
)