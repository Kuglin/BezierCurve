#ifndef CURVA_H
#define CURVA_H

#include <vector>
#include "Plano.h"
#include "Ponto.h"

class Curva {

    public:

        Curva(Plano *plano, Renderer *renderer); // Construtor Padrão
        
        void addPonto(Ponto *p); // Adiciona ponto no vetor

        void lerp(); // Exibe Linhas na tela
        void lerp(vector<Ponto*> ps);

        void incT();

    private:

        vector<Ponto*> pontos;
        Plano *plano;
        Renderer *renderer;

        vector<Ponto*> pCurva;

        double t;

};

#endif