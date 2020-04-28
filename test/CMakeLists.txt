cmake_minimum_required(VERSION 3.5)
enable_language(CXX)
project(simple-flightpath-simulator-testing)

set(FindModuleDir ${CMAKE_SOURCE_DIR}/../bin/cmake
CACHE STRING "path to directory containing the Find<Module>.cmake modules"
)
mark_as_advanced(FindModuleDir)
add_executable(SimpleFlightpathSimTest)
find_package(SimpleFlightpathSim REQUIRED)

target_sources(SimpleFlightpathSimTest
PRIVATE
  placeholder.cpp
)

target_link_libraries(SimpleFlightpathSimTest
PRIVATE
  RRA::SimpleFlightpathSim
  ::Catch2
)

add_test("Simple flightpath sim - end to end testing" ${CMAKE_BINARY_DIR}/test/SimpleFlightpathSimTest.exe)