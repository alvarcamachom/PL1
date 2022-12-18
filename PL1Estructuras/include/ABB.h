#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"
#include <iostream>


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(Vehiculo v, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        void verInOrden();
        void insertar(Vehiculo v);
        virtual ~ABB();

    protected:

    private:
        NodoABB *raiz;
        void verInOrden(NodoABB *arb);
        void insertar(Vehiculo v, NodoABB *nodo);
        Vehiculo v;
};

#endif // ABB_H
