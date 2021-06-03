cmake_minimum_required(VERSION 3.19)
project(test)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES main.cpp)

add_executable(test ${SOURCE_FILES})

include_directories(pdc34dllw/inc)
link_directories(pdc34dllw/lib)
target_link_libraries(test pdc34dllw.lib)

