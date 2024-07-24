cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(parsing)

include_directories(include)

add_subdirectory(deps/pugixml)

add_executable(parsing src/main.cpp src/file.cpp src/help.cpp src/parse.cpp src/trail.cpp src/marker.cpp)
target_link_libraries(parsing pugixml)
