#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Pila.h"
#include "Cola.h"
#include "Gestor.h"
#include "Vehiculo.h"
#include "ZonaReparto.h"
#include "Lista.h"
#include "Pedido.h"
#include "ABB.h"
#include "NodoABB.h"


//y pedir concesionario y zona hay q hacerlo
//apunte: he metido la implementacion de arbol de la profe, pero habria que cambiar la implementacion para que en cada nodo haya un concesionario,
//porque ahora tiene algo raro, nombre o algo asi.

using namespace std;

int main()
{
    Cola cola;
    //Variables menú
    srand(time(NULL));
    int opcion;
    bool bucle = true;
    string error = "Opcion no valida\n";

    //Variables simulación, se pueden establecer manualmente desde aquí.
    int nv = 12;
    int ns = 4 ;
    int np = 7;
    int nc = 10;

    Gestor g ;
    Vehiculo v;


    while (bucle)
    {
        //Menu
        cout<<"Seleccione una opcion: \n1-Generar "<<nv<<" automóviles en la fabrica\n2-Generar numero pedido de automoviles, de cada modelo y color\n"
            "3-Mostrar automoviles en la fabrica\n4-Borrar automoviles en fabrica\n"
            "5-Generar aleatoriamente 2 pedidos para cada concesionario e insertarlos en la lista de pedidos\n"
            "6-Meter en la lista de pedidos los pedidos que se deseen\n"
            "7-Mostrar datos de la lista de pedidos\n8-Borrar lista de pedidos\n"
            "9-Salen "<<ns<<" automóviles de la fabrica y llegan a naves de reparto\n10-Salen un numero pedido de automoviles de la fabrica y llegan a las naves de reparto\n"
            "11-Realizar la simulacion hasta terminar los automoviles disponibles\n12-Mostrar en pantalla los datos de las naves de reparto\n"
            "13-Almacenar en el arbol binario un automovil cuyos datos son leidos de teclado\n"
            "14-Almacenar en el arbol binario los datos de los automoviles de una de las colas de zona\n"
            "15-Almacenar en el arbol binario los datos de los automoviles de todas las colas de zona\n"
            "16-Visualizar los datos de todos los automoviles entregados ordenados por numero de concesionario\n"
            "17-Eliminar del árbol binario los datos de todos los automoviles de un modelo dado\n"
            "18-Visualizar los automoviles entregados en un concesionario cuyo numero es leido de teclado\n"
            "19-Visualizar el concesionario y zona en que se ha entregado un automovil, leyendo de teclado su numero de bastidor\n"

            "\n99-Pruebas\n"
            "\n0-Salir\n";
        cin>>opcion;

        if (opcion != 2 && opcion != 6 && opcion != 10) //no se borran si se elige una de estas opciones porque exigen una entrada de datos
        {
            system("clS"); //Para borrar la consola despues de cada accion
        }

        if (opcion==0)
        {
            bucle=false; //salir del menu
        }

        else if (opcion==1)
        {
            //Generar un numero de automoviles aleatorio y meterlos en el almacen
            g.crearVehiculo(nv);
            cout<<endl<<"Se han generado "<<nv<<" vehiculos y se han metido al almacen"<<endl;
            cout<<""<<endl;
        }
        else if (opcion==2)
        {
            //Generar un numero dado de automoviles
            int nvORIGINAL = nv;
            cout<<"Cuantos automoviles (de cada modelo y color) generamos?\n";
            cin>>nv;
            g.generarNVVehiculos(nv);
            cout<<endl<<"Se han generado "<<nv*15<<" vehiculos y se han metido al almacen"<<endl; //3 colores, 5 modelos --> 15 posibilidades
            cout<<""<<endl;
            nv = nvORIGINAL;
        }
        else if(opcion==3)
        {
            //Mostrar automoviles en la fabrica
            cout<<"Vehiculos en el almacen de la fabrica: "<<endl;
            g.mostrarVehiculosFabrica();

        }
        else if(opcion==4)
        {
            //Borrar automoviles
            g.borrarVehiculosFabrica();
            cout<<"Se han eliminado los vehiculos del almacen"<<endl;
        }


        else if(opcion==5)
        {
            //Generar aleatoriamente NC*2 pedidos de los concesionarios e insertarlos en la lista de pedidos
            g.generarPedidos(nc);

        }
        else if(opcion==6)
        {
            //Meter en la lista de pedidos los pedidos que se deseen
            int nPedidos;
            cout<<"Cuantos pedidos se van a generar?"<<endl;
            cin>>nPedidos;
            g.generarPedidosCustom(nPedidos);

        }
        else if(opcion==7){
            //Ver lista de pedidos
            g.verPedidos();
        }
        else if(opcion==8)
        {
            //Borrar lista de pedidos
            g.borrarPedidos();

        }
        else if(opcion==9)
        {
            /*salen NS automóviles de la cola de fábrica y llegan a una de las
            naves de reparto (buscando una solicitud en la lista de pedidos)

            ir sacando coches de la cola fabrica y buscando si estan en la lista pedidos. si estan, se le asigna concesionario,
            se elimina de la lista y se lleva a zona*/

            g.vehiculosAZona(g.buscaPedidos(ns));
            g.mostrarZonas();
            }

        else if(opcion==10){
            //Igual que el 9 pero solicitando NS
            int nsORIGINAL = ns;
            cout<<"Cuantos automoviles sacamos?\n";
            cin>>ns;
            g.vehiculosAZona(g.buscaPedidos(ns));
            cout<<endl<<"Se han sacado "<<ns<<" vehiculos y se han llevado a las zonas"<<endl;
            cout<<""<<endl;
            ns = nsORIGINAL;

        }
        else if(opcion==11){
            //Hacer simulacion hasta finalizar automoviles
            g.finSimulacion(ns);
        }
        else if(opcion==12){
            //Mostrar datos zonas y camiones
            g.mostrarZonas();
        }
        else if(opcion==13){
            //Almacenar en ABB automovil con datos pedidos

            string col = v.pedirColor();
            string mod = v.pedirModelo();
            int conc = v.pedirConcesionario(nc);
            string bast = v.pedirBastidor();
            //g.insertAutomovilABB(col, mod, conc, bast);

        }
        else if(opcion==14){
            //Almacenar en ABB los datos de los automoviles de una de las zonas

        }
        else if(opcion==15){
            //Almacenar en ABB los datos de los automoviles de todas las zonas

        }
        else if(opcion==16){
            //Ver los datos de los automóviles entregados ordenados por numero de concesionario

        }
        else if(opcion==17){
            //Eliminar del arbol binario los datos de los automoviles de un modelo dado
            string modelo;
            cout<<"Que modelo eliminamos?"<<endl;
            cin>>modelo;
        }
        else if(opcion==18){
            //Ver los automoviles entregados en un concesionario pedido
            int numc;
            cout<<"Seleccionar concesionario"<<endl;
            cin>>numc;
        }
        else if(opcion==19){
            //Ver el concesionario y zona en que se ha entregado un automovil pidiendo numero de bastidor
            string bastidor;
            cout<<"Introduce el bastidor: "<<endl;
            cin>>bastidor;
        }


        else if(opcion==99)
        {
            //g.pruebaLista();
            //g.pruebaArbol();
            /*Pedido ped = Pedido();
            cout<<ped.verPedido()<<endl;
            if(ped.getZona() == "N"){
                g.vehiculosAZona(1,1);*/
                int g = 3;
                cout<<"int g";
                cin>>g;
                cout<<g;
        }
        else
        {
            cout<<error;
        }
    }
    return 0;
}


