add_executable(simpleFlightPathSimulatorTests)

target_sources(simpleFlightPathSimulatorTests
PRIVATE
  placeholder.cpp
)

target_link_libraries(simpleFlightPathSimulatorTests
PRIVATE
  ::Catch2
)

add_test("odeint_learning_tests" ${CMAKE_BINARY_DIR}/test/simpleFlightPathSimulatorTests.exe)