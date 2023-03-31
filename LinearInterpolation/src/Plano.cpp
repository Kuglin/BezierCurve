#include "Plano.h"
#include <SDL2/SDL.h>

using namespace std;

Plano::Plano(int width, int height, Renderer *renderer) {

    this->width = width;
    this->height = height;
    this->renderer = renderer;

}

void Plano::desenharPlano ()
{       
    // Grid pontilhado
    renderer->changeColor(60, 60, 60, 255);

    for (int i = width/2 + deslocamento_x; i < width; i += escala)
    {   
        for (int j = 0; j < height; j += 4)
        {   
            
            renderer->drawPoint(i, j);
        }
    }

    for (int i = width/2 + deslocamento_x; i > 0; i -= escala)
    {
        for (int j = 0; j < width; j += 5)
        {
            renderer->drawPoint(i, j);
        }
    }

    for (int i = height/2 + deslocamento_y; i < height ; i += escala)
    {
        for (int j = 0; j < width; j += 5)
        {
            renderer->drawPoint(j, i);
        }
    }

    for (int i = height/2 + deslocamento_y; i > 0; i -= escala)
    {
        for (int j = 0; j < width; j += 4)
        {
            renderer->drawPoint(j, i);
        }
    }

    //Linha Vertical
    renderer->changeColor(255, 255, 255, 255);
    renderer->drawLine(0, height / 2 + deslocamento_y, width, height / 2 + deslocamento_y);

    // Linha Horizontal
    renderer->changeColor(255, 255, 255, 255);
    renderer->drawLine(width / 2 + deslocamento_x, 0, width / 2 + deslocamento_x, height);


}

void Plano::aproximar() {
    if (escala < 100) {
        escala += 5;
    }
}

void Plano::afastar() {
    if (escala > 20) {
        escala -= 5;
    }
}

void Plano::moverDireita() {
    if (deslocamento_x < expansao)
    {
        deslocamento_x += escala;
    }
}

void Plano::moverEsquerda() {
    if (deslocamento_x > -expansao) 
    {
        deslocamento_x -= escala;
    }
}

void Plano::moverBaixo() {
    if (deslocamento_y > -expansao) 
    {
        deslocamento_y -= escala;
    }
}

void Plano::moverCima() {
    if (deslocamento_y < expansao) 
    {
        deslocamento_y += escala;
    }
}

void Plano::desenharLinha(Ponto *p1, Ponto *p2) {

    renderer->drawLine(
    p1->x * escala + width/2 + deslocamento_x,
    p1->y * -escala + height/2 + deslocamento_y,
    p2->x * escala + width/2 + deslocamento_x,
    p2->y * -escala + height/2 + deslocamento_y);

}

void Plano::desenharPonto(Ponto *p) {
    
    renderer->drawPoint(
    p->x * escala + width/2 + deslocamento_x,
    p->y * -escala + height/2 + deslocamento_y
    );

};

void Plano::normalizarPonto(Ponto *p) {

    p->x = (p->x - width/2 - deslocamento_x)/escala;
    p->y = (p->y - height/2 - deslocamento_y)/-escala;

};
