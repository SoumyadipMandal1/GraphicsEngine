cmake_minimum_required(VERSION 3.28)
project(GraphicsEngine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML 3.0 COMPONENTS Graphics REQUIRED)

add_executable(main line.cpp)
target_compile_features(main PRIVATE cxx_std_23)
target_link_libraries(main PRIVATE SFML::Graphics)
