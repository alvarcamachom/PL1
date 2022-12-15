#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
using namespace std;

class NodoABB
{
    friend class ABB;
    public:
        NodoABB();
        NodoABB(int conc, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();

    protected:

    private:
        int concesionario;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H
