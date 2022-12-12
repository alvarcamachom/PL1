#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"
#include <iostream>


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(string nom, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        void verInOrden();
        void insertar(string nom);
        virtual ~ABB();

    protected:

    private:
        NodoABB *raiz;
        void verInOrden(NodoABB *arb);
        void insertar(string nom, NodoABB *nodo);
};

#endif // ABB_H
