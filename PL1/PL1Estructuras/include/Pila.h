#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Vehiculo.h"


class Pila
{
    private:
        pnodo cima;
    public:
        Pila();
        virtual~Pila();
        bool esVacia();
        void apilar(Vehiculo v);
        Vehiculo desapilar();

    protected:

};

#endif // PILA_H
