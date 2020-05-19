cmake_minimum_required(VERSION 3.1.0)

project(TETRIS)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)

add_executable(TETRIS
   main.cc
   gestionnaire.cc
   database.cc
   music.cc
   patternwidget.cc
   engine.cc
   game.cc
   powerUp.cc
   powerbutton.cc
   menu.cc
   helper.cc
   endscreen.cc
   mode.cc
   tetrimino.cc
   baton.cc
   carre.cc
   te.cc
   lambda.cc
   gamma.cc
   biais.cc
   biaisinv.cc
   tetriminobombe.cc
)

target_link_libraries(TETRIS Qt5::Widgets Qt5::Multimedia)
