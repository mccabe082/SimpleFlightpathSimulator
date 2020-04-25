add_executable(scripted6DoFFlightTest)

target_sources(scripted6DoFFlightTest
PRIVATE
  cruiseTests.cpp
  follow_waypointsTest.cpp
  waypointTests.cpp
  waypointQueueTests.cpp
)

target_include_directories(scripted6DoFFlightTest
PRIVATE
  ${CMAKE_SOURCE_DIR}/include 
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(scripted6DoFFlightTest
PRIVATE
  $<TARGET_OBJECTS:scripted6DoFFlight>
  geometry3d
  ::Catch2
)

add_test("scripted6DoFFlightTest" ${CMAKE_BINARY_DIR}/src/scripted_6dof_flight_test/Debug/scripted6DoFFlightTest.exe)

message(AUTHOR_WARNING "Need to reconsider - look at target_compile_features and target_compile_options")
target_compile_features(scripted6DoFFlightTest
PUBLIC
  cxx_std_17
)
