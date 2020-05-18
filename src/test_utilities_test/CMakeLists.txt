add_executable(TestUtilitiesTest)

target_sources(TestUtilitiesTest
PRIVATE
  division_utils.test.cpp
)

target_include_directories(TestUtilitiesTest
PRIVATE
  ${CMAKE_SOURCE_DIR}/include 
  ${CMAKE_SOURCE_DIR}/src 
)

target_link_libraries(TestUtilitiesTest
PRIVATE
  $<TARGET_OBJECTS:TestUtilities>
  ::Catch2
)

add_test("TestUtilitiesTest" ${CMAKE_BINARY_DIR}/src/geometry3d_test/Debug/TestUtilitiesTest.exe)