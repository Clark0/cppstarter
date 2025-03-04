cmake_minimum_required(VERSION 3.13)

project(CppStarter LANGUAGES CXX)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify Clang++ as the compiler
set(CMAKE_CXX_COMPILER clang++)

# Enable generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile flags
set(SANITIZER_FLAGS "-fsanitize=address" "-fno-omit-frame-pointer")
add_compile_options(${SANITIZER_FLAGS})
add_link_options(${SANITIZER_FLAGS})

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

