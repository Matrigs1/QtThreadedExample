cmake_minimum_required(VERSION 3.14)

project(ThreadedExample LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Concurrent)

add_executable(ThreadedExample
  main.cpp
  worker.h
  worker.cpp
  manager.h
  manager.cpp
)
target_link_libraries(ThreadedExample Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Concurrent)

install(TARGETS ThreadedExample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
