#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

struct windowProperty{
    int w, h;
    bool running;
    SDL_Renderer *rend;
};

class window{
private: 
    SDL_Window         *wind;
    bool                running;
    int gridSizePlus = 0;
    bool first = true;
    int oX, oY, yF, xF;
public:
    window();
    ~window();
    windowProperty      windowProperties();
    static SDL_Renderer *rend;
    void                init();
    void                handleWindowEvent(int &boardX, int &boardY, int &cellSize, int &dispalceX, int &displaceY);
    void                render();
    void                update();
};
