#pragma once 

#include "window.h"
#include <vector>

void createCanvas(int x, int y){
    
}

void drawGrid(int x, int y, int cellSize, int wW, int wH, int dsplX, int dsplY){
    x += 2;
    y += 2;
    float cwW, cwH;
    cwW = (wW/2) - ((x*cellSize)/2) + dsplX;
    cwH = (wH/2) - ((y*cellSize)/2) + dsplY;
    for(int i = 0, j = 0; i < 1+x*cellSize || j < 1+y*cellSize; i+=cellSize, j+=cellSize){
        SDL_SetRenderDrawColor(window::rend, 40, 40, 40, 255);
        SDL_RenderDrawLineF(window::rend, i+cwW, 0, i+cwW, wH);
        SDL_RenderDrawLineF(window::rend, 0, j+cwH, wW, j+cwH);
        // Draw White Outiline 
        if(i == cellSize*2 || i == (x*cellSize)-(cellSize*2)){
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, i+cwW, 0, i+cwW, wH);
        }
        if(j == cellSize*2 || j == (y*cellSize)-(cellSize*2)){ 
            SDL_SetRenderDrawColor(window::rend, 100, 100, 100, 255); 
            SDL_RenderDrawLineF(window::rend, 0, j+cwH, wW, j+cwH);
        }
    }
}