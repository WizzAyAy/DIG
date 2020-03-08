cmake_minimum_required(VERSION 2.8)

project(tp1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
add_compile_options(-Wall -Wpedantic)
endif()

add_executable(${PROJECT_NAME} main.cc window.cc traducteur.cc moteur.cc)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
