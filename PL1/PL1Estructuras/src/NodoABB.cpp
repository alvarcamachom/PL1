#include "NodoABB.h"

NodoABB::NodoABB()
{
    //ctor
}

NodoABB::NodoABB(Vehiculo ve, NodoABB *izq, NodoABB *der)
{

    //ctor
    v=ve;
    hi=izq;
    hd=der;
}

NodoABB::~NodoABB()
{
    //dtor
}
