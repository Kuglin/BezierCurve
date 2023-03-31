#include "Ponto.h"

Ponto::Ponto(double x, double y) {

    this->x = x;
    this->y = y;

}

void Ponto::lerp(Ponto* p1, Ponto* p2, double t) {

    this->x = ( (1 - t) * (p1->x) ) + ( t * (p2->x) );
    this->y = ( (1 - t) * (p1->y) ) + ( t * (p2->y) );

}