# CMakeList.txt : CMake project for DTW, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Static library output: DTW
add_library(${PROJECT} STATIC "")

# Preprocessor options
target_compile_options(${PROJECT} PRIVATE -openmp)
target_compile_options(${PROJECT} PRIVATE -O2)

# Preprocessor defines
target_compile_definitions(${PROJECT} PRIVATE "EIGEN_DEFAULT_TO_ROW_MAJOR")
 
# Header libs
target_include_directories(${PROJECT} PRIVATE "../../../external/eigen")
target_include_directories(${PROJECT} PRIVATE "../../../pybind11/pybind11_tensor/include")

# Subdirectories
add_subdirectory("include")
add_subdirectory("src")

# Inlude directories
target_include_directories(${PROJECT} PRIVATE "include")
