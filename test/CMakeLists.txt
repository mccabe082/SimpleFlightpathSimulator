add_executable(SimpleFlightpathSimTest)
find_package(SimpleFlightpathSim 1.0 REQUIRED)

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