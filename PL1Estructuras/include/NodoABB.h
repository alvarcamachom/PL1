#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include "Concesionario.h"
using namespace std;

class NodoABB
{
    friend class ABB;
    public:
        NodoABB();
        NodoABB(Concesionario c, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();

    protected:

    private:
        Concesionario c;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H
