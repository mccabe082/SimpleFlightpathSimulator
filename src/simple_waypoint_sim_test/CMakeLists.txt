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

#file(
#COPY
#  sample_waypoint_queue.xml
#DESTINATION
#  sample_waypoint_queue.xml
#)

add_test(
NAME
  "SimpleWaypointSimTest"
COMMAND
  SimpleWaypointSimTest
)

target_compile_features(SimpleWaypointSimTest
PUBLIC
  cxx_std_17
)
