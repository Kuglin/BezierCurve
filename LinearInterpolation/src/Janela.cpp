
#include "Janela.h"
#include <SDL2/SDL.h>
#include "Ponto.h"
#include "Curva.h"
#include <vector>
#include <iostream>
using namespace std;


// Construtor
Janela::Janela(char *titulo, int w, int h)
{
    sdl = Sdl::criar();

    title = title;
    width = w;
    height = h;

    sdlWindow = SDL_CreateWindow(titulo, 0, 0, w, h, SDL_WINDOW_SHOWN);
    renderer = new Renderer(sdlWindow);
    plano = new Plano(width, height, renderer);
}

// Destrutor
Janela::~Janela()
{

    SDL_DestroyWindow(sdlWindow);
}

// Retornar janela sdl
SDL_Window *Janela::get_sdlWindow()
{
    return sdlWindow;
}

int Janela::get_height()
{
    return height;
}

int Janela::get_width()
{
    return width;
}

void Janela::loop()
{   

    Ponto *p1 = new Ponto(1, 1);
    Ponto *p2 = new Ponto(2, 5);
    Ponto *p3 = new Ponto(7, 4);
    Ponto *p4 = new Ponto(1, 12);

    vector<Ponto*> pontos;

    Curva *c = new Curva(plano, renderer);
    // c->addPonto(p1);
    // c->addPonto(p2);
    // c->addPonto(p3);
    // c->addPonto(p4);

    bool running = 1;

    int mouseX, mouseY;

    while (running)
    {   
        
        
        plano->desenharPlano();
        renderer->clear();

        if( sdl->currentKeyStates[ SDL_SCANCODE_KP_PLUS ] )
        {
            plano->aproximar();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_KP_MINUS ] )
        {
            plano->afastar();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_UP] )
        {
            plano->moverCima();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_DOWN] )
        {
            plano->moverBaixo();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_LEFT] )
        {
            plano->moverDireita();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_RIGHT] )
        {
            plano->moverEsquerda();
        }
        if( sdl->currentKeyStates[ SDL_SCANCODE_R] )
        {
            c->clearPontosC();
        }

        switch (sdl->handleEvents())
        {
        case 0:
            running = 0;
            break;
        
        case 1:
            break;

        case 2:
            SDL_GetMouseState(&mouseX, &mouseY);
            c->addPonto(new Ponto(mouseX, mouseY));
            break;
        }

        plano->desenharPlano();

        for (int i = 0; i < 5; i++)  // Incrementando mais vezes para acelerar a velocidade de criação da curva sem aumentar frame rate
            c->incT();

        SDL_Delay(10);

        renderer->changeColor(255, 255, 255, 255);
        renderer->update();
        
    }

}