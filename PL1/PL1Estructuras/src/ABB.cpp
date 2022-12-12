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

ABB::ABB(string nom, NodoABB *hIz, NodoABB *hDer) //constructor que crea árbolBin con dato y dos subárboles
{
    raiz= new NodoABB(nom, hIz, hDer);
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
        cout<< arb->nombre<<endl; //Mostrar nombre
        verInOrden(arb->hd); // Recursion para la rama derecha
    }
}

void ABB::insertar(string nombre)
{
    insertar(nombre, raiz);
}

void ABB::insertar(string nombre, NodoABB *nodo)//En este método insertamos un nombre en el ABB en orden
{
    if ((nodo->nombre>nombre) || (nodo->nombre ==nombre)) //Si el nombre es menor o igual al del nodo raíz
    {
        if (nodo->hi == NULL) //Si el nodo izquierdo está vacio entoces
        {
            NodoABB *nuevo=new NodoABB(nombre); //creo un objeto NodoABB para insertarlo en el ABB
            nodo->hi= nuevo;
        }
        else //En caso de que el nodo no estuviera vacio
        {
            insertar(nombre, nodo->hi); //insertamos en el nodo izquierdo
        }
    }
    else // Si el nombre es > que el nodo
    {
        if (nodo->hd == NULL) //Comprobamos si el derecho no existe
        {
            NodoABB *nuevo=new NodoABB(nombre); // Creamos un nuevo nodo en la rama derecha
            nodo->hd=nuevo;
        }
        else //si existe
        {
            insertar(nombre, nodo->hd);// insertamos el pasajero al nodo derecho
        }
    }
}
ABB::~ABB()
{
//dtor
}
