# CMakeList.txt : CMake project for DTW_test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8) 

# Python dll output: ${PROJECT}_test
include_directories("../${PROJECT_PYTHON_SDIR}/pybind11")
# Project modules
pybind11_add_module(${PROJECT_TEST} "")
# Project name definition
target_compile_definitions(${PROJECT_TEST} PRIVATE PROJECT_NAME_DEF=${PROJECT_TEST})

# Include & link static library DTW
target_include_directories(${PROJECT_TEST} PRIVATE "../${PROJECT_SDIR}/include")
target_link_libraries(${PROJECT_TEST} PRIVATE ${PROJECT})
# Header libs
target_include_directories(${PROJECT_TEST} PRIVATE "../../../pybind11/pybind11_tensor/include")
target_include_directories(${PROJECT_TEST} PRIVATE "../../../external/eigen")

# Preprocessor defines
target_compile_definitions(${PROJECT_TEST} PRIVATE "")
# Debug
#target_compile_definitions(${PROJECT_TEST} PRIVATE DEBUG_OUT)

# Preprocessor options
#target_compile_options(DTW PRIVATE -openmp)
#target_compile_options(DTW PRIVATE -O2)
#target_compile_options(DTW PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Sources
target_sources(${PROJECT_TEST} 
	PRIVATE 
	   "main.cpp")