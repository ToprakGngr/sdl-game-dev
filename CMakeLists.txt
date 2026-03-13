# 1. THE SETUP
cmake_minimum_required(VERSION 3.20)

project(MyEngine VERSION 1.0 LANGUAGES CXX)

# Enforce Modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. DEPENDENCIES (Vendoring SDL3)
set(SDL_TEST OFF CACHE BOOL "Disable SDL tests" FORCE)
add_subdirectory(external/SDL)

# 3. THE TARGET (Your Engine)
add_executable(Engine src/main.cpp)

# 4. LINKING
# Link SDL3 to your Engine. 
target_link_libraries(Engine PRIVATE SDL3::SDL3)

# 5. COMPILER WARNINGS
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Engine PRIVATE -Wall -Wextra -Wpedantic -Werror=return-type)
endif()