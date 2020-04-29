add_executable(SimpleWaypointSimTest)

target_sources(SimpleWaypointSimTest
PRIVATE
  follow_waypoints.test.cpp
  waypoint.test.cpp
  waypoint_queue.test.cpp
)

target_include_directories(SimpleWaypointSimTest
INTERFACE
  ${CMAKE_SOURCE_DIR}/include 
PRIVATE
  ${CMAKE_SOURCE_DIR}/include 
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(SimpleWaypointSimTest
PRIVATE
  $<TARGET_OBJECTS:SimpleWaypointSim>
  geometry3d
  ::Catch2
)

add_test("SimpleWaypointSimTest" ${CMAKE_BINARY_DIR}/src/scripted_6dof_flight_test/Debug/SimpleWaypointSimTest.exe)

message(AUTHOR_WARNING "Need to reconsider - look at target_compile_features and target_compile_options")
target_compile_features(SimpleWaypointSimTest
PUBLIC
  cxx_std_17
)
