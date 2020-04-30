add_library(geometry3d STATIC)

target_include_directories(geometry3d
PUBLIC
  ../../include
)

target_sources(geometry3d
PRIVATE
  ../../include/geometry3d/orientation.h
  ../../include/geometry3d/position.h
  ../../include/geometry3d/rotation.h
  ../../include/geometry3d/velocity.h
  ./orientation.cpp
  ./position.cpp
  ./quaternion.cpp
  ./quaternion.h
  ./rotation.cpp
  ./velocity.cpp
)

target_link_libraries(geometry3d
PRIVATE
  $<$<TARGET_EXISTS:Microsoft.GSL::GSL>:Microsoft.GSL::GSL>
)

target_compile_features(geometry3d
PUBLIC
  cxx_std_17
)

target_compile_options(geometry3d
PUBLIC
  "-std:c++17"
  "-fp:strict"
  "-fp:except"
)

set_target_properties(geometry3d PROPERTIES
  CXX_STANDARD 17
)
