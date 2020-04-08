cmake_minimum_required(VERSION 3.1.0)

project(TETRIS)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TETRIS
   main.cc
   gestionnaire.cc
   patternwidget.cc
   engine.cc
   game.cc
   menu.cc
   mode.cc
   tetrimino.cc
   baton.cc
   carre.cc
   te.cc
   lambda.cc
   gamma.cc
   biais.cc
   biaisinv.cc
)

target_link_libraries(TETRIS Qt5::Widgets)
