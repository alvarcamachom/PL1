#include "ABB.h"

ABB::ABB() //crea árbol vacío
{
    //ctor
    raiz=NULL;
}

ABB::ABB(NodoABB *r)
{
    raiz=r;
}

ABB::ABB(int conc, string zona, Lista vehiculosConc, NodoABB *hIz, NodoABB *hDer) //constructor que crea árbolBin con dato y dos subárboles
{
    raiz= new NodoABB(conc, zona, vehiculosConc, hIz, hDer);
}

void ABB::verInOrden()
{
    verInOrden(raiz);
}

void ABB::verInOrden(NodoABB *arb) //Ver ABB en inorden
{
    if (arb)
    {
        verInOrden(arb->hi); //Recursion para la rama izquierda
        cout<< arb->conc, zona, vehiculosConc.mostrar()<<endl; //Mostrar nombre
        verInOrden(arb->hd); // Recursion para la rama derecha
    }
}

void ABB::insertar(int conc, string zona, Lista vehiculosConc)
{
    insertar(int conc, string zona, Lista vehiculosConc, raiz);
}

void ABB::insertar(int conc, string zona, Lista vehiculosConc, NodoABB *nodo)//En este método insertamos un nombre en el ABB en orden
{

    if ((nodo->conc>conc) || (nodo->conc == conc)) //Si el nombre es menor o igual al del nodo raíz
    {
        if (nodo->hi == NULL) //Si el nodo izquierdo está vacio entoces
        {
            NodoABB *nuevo=new NodoABB(v); //creo un objeto NodoABB para insertarlo en el ABB
            nodo->hi= nuevo;
        }
        else //En caso de que el nodo no estuviera vacio
        {
            insertar(v, nodo->hi); //insertamos en el nodo izquierdo
        }
    }
    else // Si el nombre es > que el nodo
    {
        if (nodo->hd == NULL) //Comprobamos si el derecho no existe
        {
            NodoABB *nuevo=new NodoABB(v); // Creamos un nuevo nodo en la rama derecha
            nodo->hd=nuevo;
        }
        else //si existe
        {
            insertar(v, nodo->hd);// insertamos el pasajero al nodo derecho
        }
    }
}
ABB::~ABB()
{
//dtor
}
