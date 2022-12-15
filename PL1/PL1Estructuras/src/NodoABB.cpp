#include "NodoABB.h"

NodoABB::NodoABB()
{
    //ctor
}

NodoABB::NodoABB(int conc, NodoABB *izq, NodoABB *der)
{
    //ctor
    concesionario=conc;
    hi=izq;
    hd=der;
}

NodoABB::~NodoABB()
{
    //dtor
}
