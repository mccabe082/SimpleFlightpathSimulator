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

add_test(
NAME
  "odeint_learning_tests"
COMMAND
  odeintTest
)