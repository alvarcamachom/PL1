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
    int nv = 12;
    int ns = 4 ;
    int np = 7;
    int nc = 5;

    Gestor g ;
    Vehiculo v;


    while (bucle)
    {
        //Menu
        cout<<"Seleccione una opcion: \n1-Generar "<<nv<<" automóviles\n2-Generar numero pedido de automoviles\n"
            "3-Mostrar automoviles en fabrica\n4-Borrar automoviles en fabrica\n"
            "5-Salen "<<ns<<" automóviles de la fabrica y llega a un almacén\n"
            "6-Salen un numero pedido de automoviles de la fabrica y llegan a un almacen\n"
            "7-Mostrar datos de los almacenes de zona y registro\n8-Realizar simulacion hasta terminar los automoviles disponibles\n"
            "\n0-Salir\n";
        cin>>opcion;

        if (opcion != 2 && opcion != 6)
        {
            system("cls"); //Para borrar la consola despues de cada accion
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
            cout<<"Cuantos automoviles generamos?\n";
            cin>>nv;
            g.crearVehiculo(nv);
            cout<<endl<<"Se han generado "<<nv<<" vehiculos y se han metido al almacen"<<endl;
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


        else if(opcion==6 || opcion==5)
        {
            int nsORIGINAL=ns;
            //Vehiculos a la zona
            if (opcion==6)
            {

                cout<<"Cuantos automoviles salen de la fabrica?";
                cin>>ns;
            }

            int zona=rand()%4; //elige la zona a la que van, están en un vector las 4
            g.vehiculosAZona(zona, ns);
            ns=nsORIGINAL;
        }
        else if(opcion==7)
        {
            //Mostrar datos de los camiones de las zonas y sus registros
            g.mostrarZonas();

        }
        else if(opcion==8)
        {
            //Simular hasta terminar automoviles
            g.finSimulacion(ns);
        }
        else
        {
            cout<<error;
        }
    }
    return 0;
}
