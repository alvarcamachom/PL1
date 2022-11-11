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

    //Variables simulación
    int nv; //Número de vehiculos a generar
    int nc = Gestor::generarNC(); //Genera el numero maximo de concesionarios
    int np = Gestor::generarNP(); //Genera el numero de vehiculos que caben en un camión (pila)
    int ns ;//Número de vehiculos a sacar de la fabrica
    /*ZonaReparto ZN = ZonaReparto("Zona Norte");
    ZonaReparto ZO = ZonaReparto ("Zona Oeste");
    ZonaReparto ZS = ZonaReparto ("Zona Sur");
    ZonaReparto ZE = ZonaReparto ("Zona Este");
    ZonaReparto zonas [4]= {ZN,ZO,ZS,ZE}; he quitado esto porque se supone que no hace falta*/
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
            nv = g.generarNV();
            g.crearVehiculo(nv);
            cout<<endl<<"Se han generado "<<nv<<" vehiculos y se han metido al almacen"<<endl;
        }
        else if (opcion==2)
        {
            //Generar un numero dado de automoviles
            cout<<"Cuantos automoviles generamos?\n";
            cin>>nv;
            g.crearVehiculo(nv);
            cout<<endl<<"Se han generado "<<nv<<" vehiculos y se han metido al almacen"<<endl;
        }
        else if(opcion==3)
        {
            //Mostrar automoviles en la fabrica
            g.mostrarVehiculosFabrica();

        }
        else if(opcion==4)
        {
            //Borrar automoviles
            //g.borrarVehiculosFabrica();
            g.vehiculosFabrica.desencolar();
        }
        else if(opcion==5)
        {
            //Sale un numero aleatorio de automoviles de la fabrica y llegan a almacen
            ns = Gestor::generarNS(); //Genera el numero de vehiculos a sacar de la fabrica
            //string zona = zonas[rand()%4].getNombre();




            //cout<<"Salen "<< ns <<" automoviles hacia la zona "<< zona <<endl;


        }
        else if(opcion==6)
        {
            /*
            //Sale un numero dado de automoviles de la fabrica y llegan a almacen
            cout<<"Cuantos automoviles salen de la fabrica?";
            cin>>ns;
            string zona = zonas[rand()%4].getNombre();
            cout<<"Salen "<< ns <<" automoviles hacia la zona "<< zona <<endl;*/

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
