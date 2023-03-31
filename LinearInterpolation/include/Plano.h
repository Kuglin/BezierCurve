
#ifndef PLANO_H
#define PLANO_H

#include <SDL2/SDL.h>
#include <string>
#include "Renderer.h"
#include "Ponto.h"

using namespace std;

class Plano
{
private:

    int escala = 40;
    int expansao = 4000;
    int deslocamento_x = 0;
    int deslocamento_y = 0;
    int height;
    int width;
    Renderer *renderer;
    
public:

    Plano(int height, int widht, Renderer *renderer);

    void desenharPlano();

    void aproximar();

    void afastar();

    void moverEsquerda();

    void moverDireita();

    void moverCima();

    void moverBaixo();

    void desenharLinha(Ponto *p1, Ponto *p2);

    void desenharPonto(Ponto *p);

    void normalizarPonto(Ponto *p);

};

#endif
