add_executable(odeint-demo)

target_sources(odeint-demo
PRIVATE
  rk4.cpp
)

target_link_libraries(odeint-demo
PRIVATE
  ::BoostConfig
  ::Catch2
  ::Odeint
)

add_test("odeint_learning_tests" ${CMAKE_BINARY_DIR}/test/odeint/Debug/odeint-demo.exe)