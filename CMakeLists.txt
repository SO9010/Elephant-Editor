cmake_minimum_required(VERSION 3.24)

project(Elephant-Editor)

include_directories("/src" "/includes")

add_link_options(-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lstdc++)

add_executable(Elephant-Editor src/board.cpp src/main.cpp src/window.cpp src/ui/button.cpp src/ui/container.cpp src/widgets/toolBar.cpp)