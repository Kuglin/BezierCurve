/**
 * @author Guilherme Eduardo Kuglin
 * @date 2023, March 30
 * @version 2023, March 30
**/

#ifndef PONTO_H
#define PONTO_H

class Ponto {

    public:

        double x;
        double y;
        
        Ponto(double x, double y);

        void lerp(Ponto* p1, Ponto* p2, double t); // Interpolação Linear
};



#endif