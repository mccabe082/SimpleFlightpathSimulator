add_executable(scripted6DoFTargetTest)

target_sources(scripted6DoFTargetTest
PRIVATE
  cruiseTests.cpp
)

target_include_directories(scripted6DoFTargetTest
PRIVATE
  ${CMAKE_SOURCE_DIR}/include 
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(scripted6DoFTargetTest
PRIVATE
  $<TARGET_OBJECTS:scripted6DoFTarget>
  geometry3d
  ::Catch2
)

add_test("scripted6DoFTargetTest" ${CMAKE_BINARY_DIR}/src/scripted_6dof_flight_test/Debug/scripted6DoFTargetTest.exe)