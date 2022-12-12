#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
using namespace std;

class NodoABB
{
    friend class ABB;
    public:
        NodoABB();
        NodoABB(string nom, NodoABB *izq=NULL, NodoABB *der=NULL);
        virtual ~NodoABB();

    protected:

    private:
        string nombre;
        NodoABB *hi, *hd;
};

#endif // NODOABB_H
