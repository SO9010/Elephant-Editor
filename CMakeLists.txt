cmake_minimum_required(VERSION 3.24)

project(Pix)

include_directories("/src" "/includes")

add_link_options(-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lstdc++)

add_executable(pix src/board.cpp src/main.cpp src/window.cpp src/toolBar.cpp)