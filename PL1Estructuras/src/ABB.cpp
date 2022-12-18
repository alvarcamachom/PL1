#include "ABB.h"


ABB::ABB(int nc) //crea árbol vacío
{
        int zon=rand()%4;
        Lista lis= Lista();
        c = Concesionario(nc/2, zon, lis);
}

ABB::ABB(NodoABB *r)
{
    raiz=r;
}

ABB::ABB(Concesionario c, NodoABB *hIz, NodoABB *hDer) //constructor que crea árbolBin con dato y dos subárboles
{
    raiz= new NodoABB(c, hIz, hDer);
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
        cout<< arb->c.verConcesionario()<<endl; //Mostrar nombre
        verInOrden(arb->hd); // Recursion para la rama derecha
    }
}

void ABB::insertar(Concesionario c)
{
    insertar(c, raiz);
}

void ABB::insertar(Concesionario c, NodoABB *nodo)//En este método insertamos un nombre en el ABB en orden
{

    if ((nodo->c.getNumero()>c.getNumero()) || (nodo->c.getNumero() == c.getNumero())) //Si el nombre es menor o igual al del nodo raíz
    {
        if (nodo->hi == NULL) //Si el nodo izquierdo está vacio entoces
        {
            NodoABB *nuevo=new NodoABB(c); //creo un objeto NodoABB para insertarlo en el ABB
            nodo->hi= nuevo;
        }
        else //En caso de que el nodo no estuviera vacio
        {
            insertar(c, nodo->hi); //insertamos en el nodo izquierdo
        }
    }
    else // Si el nombre es > que el nodo
    {
        if (nodo->hd == NULL) //Comprobamos si el derecho no existe
        {
            NodoABB *nuevo=new NodoABB(c); // Creamos un nuevo nodo en la rama derecha
            nodo->hd=nuevo;
        }
        else //si existe
        {
            insertar(c, nodo->hd);// insertamos el pasajero al nodo derecho
        }
    }
}

void ABB::insertarVehiculo(Vehiculo ve)
{

}
ABB::~ABB()
{
//dtor
}
