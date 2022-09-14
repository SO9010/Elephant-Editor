# Pix
:warning: VERY EARLY DEVELOPMENT :warning:\
This is a 2d pixel art editor/creator created using the SDL2 library.

---
**Rough design plan:**
![Screenshot](/future/design_1.png)

---
#### Roadmap

- [x] Fix canvas movement
- [ ] Canvas draw implementation
- [ ] Tool bar UI creation
- [ ] Export canvas (bitmap)
- [ ] Open photo (bitmap)

#### Compiling details

DEPENDENCIES:
##### Arch 
    sudo pacman -S sdl2 sdl2_image sdl2_ttf
Compiling:
All you now need to do is change directory into the build one and use the "make" command
#### Current ways to work

* Press "ctrl p" to add more cells evenly to every side
* Press "ctrl m" to remove cells evenly to every side untill only 1 or 4 is left 
* Press down the scroll button to move the canvas
* Scroll to zoom in/out
