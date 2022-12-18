#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Vehiculo.h"


class Pila
{
    private:
        pnodo cima;
        int profundidad;
    public:
        Pila();
        virtual~Pila();
        bool esVacia();
        void apilar(Vehiculo v);
        void desapilar();
        Vehiculo mostrar();
        int get_profundidad();
        void verPila();

    protected:

};

#endif // PILA_H
