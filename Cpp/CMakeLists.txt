cmake_minimum_required(VERSION 3.10)
project(FEM_Solver)

# Find Eigen and MPI packages
find_package(Eigen3 REQUIRED)
find_package(MPI REQUIRED)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

# Include Eigen's header files
include_directories(${EIGEN3_INCLUDE_DIR})

# Automatically find all .cpp and .h files in the src directory
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Add the executable
add_executable(fem_solver ${SOURCES} ${HEADERS})

# Link the MPI library
target_link_libraries(fem_solver MPI::MPI_CXX)