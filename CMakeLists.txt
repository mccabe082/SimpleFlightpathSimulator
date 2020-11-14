cmake_minimum_required(VERSION 3.5)
enable_language(CXX)
project(simple-flightpath-simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # https://wiki.gentoo.org/wiki/Project:AMD64/Fixing_-fPIC_Errors_Guide

### Installation ####################

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/bin CACHE PATH "..." FORCE)
endif()

### External Libraries ##############

set(FindModuleDir ${CMAKE_SOURCE_DIR}/CMake
CACHE STRING "path to directory containing the Find<Module>.cmake modules"
)
mark_as_advanced(FindModuleDir)

list(APPEND CMAKE_MODULE_PATH ${FindModuleDir})
find_package(Boost REQUIRED MODULE)
find_package(Catch2 REQUIRED MODULE)
find_package(RapidXML REQUIRED MODULE)
find_package(Microsoft.GSL QUIET CONFIG PATHS ../GSL/build)

### Testing #########################
ENABLE_TESTING()
include(CTest)

### Main Body #######################
add_subdirectory(src)
add_subdirectory(external)
