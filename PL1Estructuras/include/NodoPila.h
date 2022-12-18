#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include  "Vehiculo.h"

class NodoPila
{
    private:
        Vehiculo vehiculo;
        NodoPila *siguiente;
        friend class Pila;

    public:
        NodoPila();
        //virtual ~NodoPila();
        NodoPila(Vehiculo v, NodoPila *sig = NULL);
    ~NodoPila();

    protected:

};
typedef NodoPila *pnodo;
#endif // NODOPILA_H
