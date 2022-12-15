#ifndef ABB_H
#define ABB_H
#include "NodoABB.h"
#include <iostream>


class ABB
{
    public:
        ABB();
        ABB(NodoABB *r);
        ABB(int conc, NodoABB *hIz=NULL, NodoABB *hDer=NULL);
        void verInOrden();
        void insertar(int conc);
        virtual ~ABB();

    protected:

    private:
        NodoABB *raiz;
        void verInOrden(NodoABB *arb);
        void insertar(int conc, NodoABB *nodo);
        int concesionario;
};

#endif // ABB_H
