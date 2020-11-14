add_executable(UtilitiesTest)

target_sources(UtilitiesTest
PRIVATE
  division_utils.test.cpp
)

target_include_directories(UtilitiesTest
PRIVATE
  ${CMAKE_SOURCE_DIR}/include 
  ${CMAKE_SOURCE_DIR}/src 
)

target_link_libraries(UtilitiesTest
PRIVATE
  $<TARGET_OBJECTS:Utilities>
  ::Catch2
)

add_test(
NAME
  "UtilitiesTest"
COMMAND
  UtilitiesTest
)