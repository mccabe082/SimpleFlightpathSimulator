add_executable(odeintTest)

target_sources(odeintTest
PRIVATE
  rk4.cpp
)

target_link_libraries(odeintTest
PRIVATE
  ::Boost
  ::Catch2
)

add_test("odeint_learning_tests" ${CMAKE_BINARY_DIR}/test/odeint/Debug/odeintTest.exe)