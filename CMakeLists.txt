cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(SimpleClockWidget VERSION 0.1 LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
link_libraries(${GTKMM_LIBRARIES})

include_directories(src)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    src/main.cpp
    src/window.cpp
    src/clock.cpp
    src/clockwidgetbase.cpp
    src/labelclockwidget.cpp
)

add_executable(simpleclockwidget ${SOURCE_FILES})
