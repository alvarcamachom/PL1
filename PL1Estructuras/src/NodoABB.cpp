#include "NodoABB.h"

NodoABB::NodoABB()
{
    //ctor
}

NodoABB::NodoABB(Concesionario c, NodoABB *izq, NodoABB *der)
{

    //ctor
    c=c;
    hi=izq;
    hd=der;
}

NodoABB::~NodoABB()
{
    //dtor
}
