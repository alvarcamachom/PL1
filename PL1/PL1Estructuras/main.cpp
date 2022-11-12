#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Pila.h"
#include "Cola.h"
#include "Gestor.h"
#include "Vehiculo.h"
#include "ZonaReparto.h"



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
    int nv = 12; /*Gestor::generarNS(); //Genera el número de vehiculos a generar*/
    int nc = 5; /*Gestor::generarNC(); //Genera el numero maximo de concesionarios*/
    int np = 3; /*Gestor::generarNP(); //Genera el numero de vehiculos que caben en un camión (pila)*/
    int ns = 7 ;/*Gestor::generarNS(); //Genera el número de vehiculos a sacar de la fabrica*/

    //Instancias de las diferentes zonas
    ZonaReparto ZN = ZonaReparto("Zona Norte");
    ZonaReparto ZO = ZonaReparto ("Zona Oeste");
    ZonaReparto ZS = ZonaReparto ("Zona Sur");
    ZonaReparto ZE = ZonaReparto ("Zona Este");
    ZonaReparto zonas [4]= {ZN,ZO,ZS,ZE}; //Vector con las cuatro zonas, para elegir.

    Gestor g;
    Vehiculo v;


    while (bucle)
    {
        //Menu
        cout<<"Seleccione una opcion: \n1-Generar numero aleatorio de automóviles\n2-Generar numero determinado de automoviles\n"
            "3-Mostrar automoviles en fabrica\n4-Borrar automoviles en fabrica\n"
            "5-Salen un numero aleatorio de automóviles de la fabrica y llega a un almacén\n"
            "6-Salen un numero determinado de automoviles de la fabrica y llegan a un almacen\n"
            "7-Mostrar datos de los almacenes de zona y registro\n8-Realizar simulacion hasta terminar los automoviles disponibles\n"
            "\n0-Salir\n";
        cin>>opcion;

        if (opcion != 2 && opcion != 6)
        {
            system("cls");
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
            cout<<"Cuantos automoviles generamos?\n";
            cin>>nv;
            g.crearVehiculo(nv);
            cout<<endl<<"Se han generado "<<nv<<" vehiculos y se han metido al almacen"<<endl;
            cout<<""<<endl;
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
            //Sale un numero aleatorio de automoviles de la fabrica y llegan a almacen
            if (g.vehiculosFabrica.es_vacia())
            {
                cout<<"Almacen vacio"<<endl;
            }
            else
            {

                string zona = zonas[rand()%4].getNombre(); //elige la zona a la que van
                g.vehiculosAZona(ns, ZN);
                cout<<"Salen "<< ns <<" automoviles hacia la zona "<< zona <<endl;
            }
        }
        else if(opcion==6)
        {
            if (g.vehiculosFabrica.es_vacia())
            {
                cout<<"Almacen vacio"<<endl;
            }
            else
            {
                //Sale un numero dado de automoviles de la fabrica y llegan a almacen
                cout<<"Cuantos automoviles salen de la fabrica?";
                cin>>ns;
                string zona = zonas[rand()%4].getNombre();
                g.vehiculosAZona(ns, zona);//llamada a metodo de gestor que mete vehiculos en las zonas
                cout<<"Salen "<< ns <<" automoviles hacia la zona "<< zona <<endl;

            }
        }
        else if(opcion==7)
        {
            //Mostrar datos de los almacenes de la zona y registros

        }
        else if(opcion==8)
        {
            //Simular hasta terminar automoviles
        }
        else
        {
            cout<<error;
        }
    }
    return 0;
}
