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

        void incT(); // Incrementar Delta t
        void clearPontosC(); // Limpa lista de pontos da curva

    private:

        vector<Ponto*> pontos; // Pontos que criam a curva
        Plano *plano; // ponteiro para o plano que a curva se localiza
        Renderer *renderer; // ponteiro para o renderer da curva

        vector<Ponto*> pCurva; // Pontos da Curva

        double t; // Delta t

};

#endif