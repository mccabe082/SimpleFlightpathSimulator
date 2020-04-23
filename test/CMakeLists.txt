add_executable(simpleFlightPathSimulatorTest)

target_sources(simpleFlightPathSimulatorTest
PRIVATE
  placeholder.cpp
)

target_link_libraries(simpleFlightPathSimulatorTest
PRIVATE
  ::Catch2
)

add_test("odeint_learning_tests" ${CMAKE_BINARY_DIR}/test/simpleFlightPathSimulatorTest.exe)