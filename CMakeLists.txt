cmake_minimum_required(VERSION 3.10)
project(GeometryDashRemake)

set(CMAKE_CXX_STANDARD 17)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(GeometryDashRemake main.cpp)

target_link_libraries(GeometryDashRemake sfml-graphics sfml-window sfml-system)
