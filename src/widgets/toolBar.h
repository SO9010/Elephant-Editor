#pragma once

#include "includes.h"

class toolBar{
public:
    toolBar();
    ~toolBar();
    
    static SDL_Color    primaryColour;
    tools               toolCollection;
    void                renderToolBar(windowProperty wP, boardPorperties bP);
    void                updateTools();

private:
    void handlePresses(windowProperty wP, std::vector<button> toolIconRender);
    void                changeCursor(std::string cursor, int offSet);
    void                changeCursor(std::string cursor, int offSetX, int offSetY);
    void                changeCursor(std::string cursor);
};