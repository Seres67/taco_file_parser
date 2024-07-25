cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(parsing)

include_directories(include)

find_package(pugixml CONFIG REQUIRED)
find_package(libzip CONFIG REQUIRED)

add_executable(parsing src/main.cpp src/file.cpp src/help.cpp src/parse.cpp src/trail.cpp src/marker.cpp)
set_property(TARGET parsing PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_property(TARGET parsing PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:>")
target_link_libraries(parsing libzip::zip pugixml::static pugixml::pugixml)