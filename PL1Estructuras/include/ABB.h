#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"
#include <iostream>


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(Concesionario c, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        void verInOrden();
        void insertar(Concesionario c);
        virtual ~ABB();

    protected:

    private:
        NodoABB *raiz;
        void verInOrden(NodoABB *arb);
        void insertar(Concesionario c, NodoABB *nodo);
        Concesionario c;
};

#endif // ABB_H
