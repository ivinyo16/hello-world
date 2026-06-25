cmake_minimum_required(VERSION 3.10.0)
project(Project  VERSION 0.1.0 LANGUAGES C)

# 1. Global configurations
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_STANDARD_REQUIRED ON)


# 2. Create a shared configuration target (INTERFACE library)
# This target holds the common include directories but compiles no code itself
add_library(common_includes INTERFACE)

target_include_directories(common_includes INTERFACE 
    include
)

# Tell CMake to look into the src directory
add_subdirectory(src)




