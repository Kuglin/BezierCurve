#include "Curva.h"
#include "Plano.h"
#include "Renderer.h"

#include <random>
#include <vector>

#include <iostream>
using namespace std;

Curva::Curva(Plano *plano, Renderer *renderer) {

    this->plano = plano;
    this->renderer = renderer;
    t = 0.001;
    pontos.clear();

}

void Curva::addPonto(Ponto *p) {
    plano->normalizarPonto(p);
    pontos.push_back(p);
    t = 0.001;
    clearPontosC();

}

void Curva::lerp() {

    if (pontos.size() < 2)
        return;

    vector<Ponto*> nP = pontos;

    while (nP.size() > 2) {


        
        for (int i = 0; i < (nP.size() - 1); i++) {
            if (nP.size() == pontos.size())
                renderer->mudarCor(10);
            else
                renderer->mudarCor(nP.size());

            if (t < 1)
                plano->desenharLinha(nP[i], nP[i+1]);

            double x = ( (1 - t) * (nP[i]->x) ) + ( t * (nP[i+1]->x) );
            double y = ( (1 - t) * (nP[i]->y) ) + ( t * (nP[i+1]->y) );
            
            nP[i] = new Ponto(x, y);
        }
        nP.pop_back();
    }


    renderer->mudarCor(2);

    if (t < 1.0)
        plano->desenharLinha(nP[0], nP[1]);

    double x = ( (1 - t) * (nP[0]->x) ) + ( t * (nP[1]->x) );
    double y = ( (1 - t) * (nP[0]->y) ) + ( t * (nP[1]->y) );

    pCurva.push_back(new Ponto(x, y));

    renderer->mudarCor(0);

    for (int i = 0; i < (pCurva.size() - 1); i++) 
        plano->desenharPonto(pCurva[i]);

}

void Curva::incT() {

    if (t < 1) {

        t += 0.001;
        lerp();
    }
    
    else {
        
        lerp();

    }

}

void Curva::clearPontosC() {

    t = 0.001;
    pCurva.clear();

}