add_executable(geometry3dTest)

target_sources(geometry3dTest
PRIVATE
  velocityTests.cpp
)

target_link_libraries(geometry3dTest
PRIVATE
  geometry3d
  ::Catch2
)

add_test("geometry3d" ${CMAKE_BINARY_DIR}/test/rapidxml/Debug/geometry3dTest.exe)