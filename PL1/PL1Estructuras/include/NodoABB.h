#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class NodoABB
{
    friend class ABB;
    public:
        NodoABB();
        NodoABB(Vehiculo v, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();

    protected:

    private:
        Vehiculo v;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H
