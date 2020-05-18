add_executable(geometry3dTest)

target_sources(geometry3dTest
PRIVATE
  orientation.test.cpp
  quoternion.test.cpp
  rotation.test.cpp
  velocity.test.cpp
)

target_include_directories(geometry3dTest
PRIVATE
  ${CMAKE_SOURCE_DIR}/include 
  ${CMAKE_SOURCE_DIR}/src 
)

target_link_libraries(geometry3dTest
PRIVATE
  $<TARGET_OBJECTS:geometry3d>
  ::Catch2
  Utilities
)

add_test("geometry3dTest" ${CMAKE_BINARY_DIR}/src/geometry3d_test/Debug/geometry3dTest.exe)