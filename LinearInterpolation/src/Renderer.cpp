#include "Renderer.h"
#include "Janela.h"

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

Renderer::Renderer(SDL_Window *sdlWindow)
{

    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
};

SDL_Renderer *Renderer::get_sdlRenderer() const
{
    return sdlRenderer;
}

void Renderer::changeColor(int r, int g, int b, int a)
{
    Renderer::r = r;
    Renderer::g = g;
    Renderer::b = b;
    Renderer::a = a;
    SDL_SetRenderDrawColor(sdlRenderer, r, g, b, a);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(sdlRenderer, x1, y1, x2, y2);
}

void Renderer::drawPoint(int x, int y)
{
    SDL_RenderDrawPoint(sdlRenderer, x, y);
}

void Renderer::update()
{
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_RenderPresent(sdlRenderer);
    SDL_SetRenderDrawColor(sdlRenderer, r, g, b, a);
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sdlRenderer);
}

void Renderer::mudarCor(int i) {
    
    switch (i)
    {
    case 0:
        changeColor(255, 255, 255, 255);
        break;
    
    case 1:
        changeColor(0, 0, 0, 0);
        break;

    case 2:
        changeColor(255, 51, 51, 255); 
        break;
    
    case 3:
        changeColor(255, 255, 51, 255);
        break;
    
    case 4:
        changeColor(51, 153, 255, 255);
        break;
    
    case 5:
        changeColor(51, 255, 51, 255);
        break;

    case 6:
        changeColor(51, 255, 153, 255);
        break;

    case 7:
        changeColor(153, 255, 51, 255);
        break;

    case 8:
        changeColor(51, 255, 255, 255);
        break;

    case 9:
        changeColor(255, 153, 51, 255);
        break;

    case 10:
        changeColor(51, 51, 255, 255);
        break;

    default:
        break;
    }



}
