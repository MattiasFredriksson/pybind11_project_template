# CMakeList.txt : CMake project for DTW_python, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Python dll output: ${PROJECT}_python
add_subdirectory ("pybind11")
pybind11_add_module(${PROJECT_PYTHON} "")
# Project name definition
target_compile_definitions(${PROJECT_PYTHON} PRIVATE PROJECT_NAME_DEF=${PROJECT_PYTHON})

# Include & link static library DTW
target_include_directories(${PROJECT_PYTHON} PRIVATE "../${PROJECT_SDIR}/include")
target_link_libraries(${PROJECT_PYTHON} PRIVATE ${PROJECT})

# Header libs
target_include_directories(${PROJECT_PYTHON} PRIVATE "../../../pybind11/pybind11_tensor/include")
target_include_directories(${PROJECT_PYTHON} PRIVATE "../../../external/eigen")

# Preprocessor defines
target_compile_definitions(${PROJECT_PYTHON} PRIVATE "")
# Debug
#target_compile_definitions(${PROJECT_PYTHON} PRIVATE DEBUG_OUT)

# Preprocessor options
#target_compile_options(DTW PRIVATE -openmp)
#target_compile_options(DTW PRIVATE -O2)

# Compilation options
add_compile_options($<$<CXX_COMPILER_ID:MSVC>:/MP>)

# Sources
target_sources(${PROJECT_PYTHON} 
	PRIVATE 
	   "main.cpp")