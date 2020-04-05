add_executable(rapidxml-demo)

target_sources(rapidxml-demo
PRIVATE
  main.cpp
)

target_link_libraries(rapidxml-demo
PRIVATE
  ::Catch2
  ::RapidXML
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/NPTG-metadata.xml
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test("test" ${CMAKE_BINARY_DIR}/test/rapidxml/Debug/rapidxml-demo.exe)