﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)



project (TMP)

include(Functions.cmake)
set(CMAKE_CXX_STANDARD 17)
set(PYBIND11_FINDPYTHON True)
set(PYBIND11_PYTHON_VERSION "3.9.2")
# If not found use:
#set (PYBIND11_PYTHON_VERSION "abs:path/to/python")
#set (Python_ADDITIONAL_VERSIONS, "...")

set(PROJECT ${CMAKE_PROJECT_NAME}_CPP)
set(PROJECT_PYTHON ${CMAKE_PROJECT_NAME})
set(PROJECT_TEST ${CMAKE_PROJECT_NAME}_TEST)

set(PROJECT_SDIR "${CMAKE_PROJECT_NAME}_lib")
set(PROJECT_PYTHON_SDIR "${CMAKE_PROJECT_NAME}_pybind")
set(PROJECT_TEST_SDIR "${CMAKE_PROJECT_NAME}_test")

# Include sub-project directories.
add_subdirectory (${PROJECT_SDIR})
add_subdirectory (${PROJECT_PYTHON_SDIR})
add_subdirectory (${PROJECT_TEST_SDIR})
