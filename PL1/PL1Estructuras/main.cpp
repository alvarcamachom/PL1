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
    //Variables menú
    srand(time(NULL));
    int opcion;
    bool bucle = true;
    string error = "Opcion no valida\n";

    //Variables simulación
    int nc = Gestor::generarNC(); //Genera el numero maximo de concesionarios
    int nv = Gestor::generarNV(); //Genera el numero de vehiculos a fabricar
    int ns = Gestor::generarNS(); //Genera el numero de vehiculos a sacar de la fabrica
    int np = Gestor::generarNP(); //Genera el numero de vehiculos que caben en un camión (pila)
    ZonaReparto ZN,ZS,ZE,ZO;
    Vehiculo v;

    while (bucle){
        //Menu
        cout<<"Seleccione una opcion: \n1-Generar numero aleatorio de automóviles\n2-Generar numero determinado de automoviles\n"
        "3-Mostrar automoviles en fabrica\n4-Borrar automoviles en fabrica\n"
        "5-Salen un numero aleatorio de automóviles de la fabrica y llega a un almacén\n"
        "6-Salen un numero determinado de automoviles de la fabrica y llegan a un almacen\n"
        "7-Mostrar datos de los almacenes de zona y registro\n8-Realizar simulacion hasta terminar los automoviles disponibles\n"
        "9-Pueba generador\n0-Salir\n";
        cin>>opcion;

        if (opcion != 2 && opcion != 6){
            system("clear");/*Esto se supone que limpia el terminal despues de cada opción,
            no se si funcionará en tu ordenador. Si no funciona cambia "clear" por "cls" y deberia ir*/
        }

        if (opcion==0){
            bucle=false;
        }

        else if (opcion==1){
            //Generar un numero de automoviles aleatorio
            int nv = rand()%10; //numero de automoviles aleatorio
            for (int i=1; i<=nv; i++){
                Vehiculo v = Vehiculo(); //Cargar vehiculo con datos
                cout<<v.verVehiculo()<<endl;/*MAL (se carga en todas las iteraciones el mismo coche) no se como solucionarlo,
                he estado haciendo un intento de crear NV coches y cargarlos y no he llegado a mas jeje*/
            }

        }
        else if(opcion==2){
            //Generar un numero dado de automoviles
            cout<<"Cuantos automoviles generamos?\n";
            cin>>nv;
        }
        else if(opcion==3){
            //Mostrar automoviles en la fabrica
        }
        else if(opcion==4){
            //Borrar automoviles
        }
        else if(opcion==5){
            //Sale un numero aleatorio de automoviles de la fabrica y llegan a almacen
            int nv2 = rand()%10; //numero de automoviles aleatorio
        }
        else if(opcion==6){
            //Sale un numero dado de automoviles de la fabrica y llegan a almacen
            cout<<"Cuantos automoviles salen de la fabrica?";
            cin>>nv;
        }
        else if(opcion==7){
            //Mostrar datos de los almacenes de la zona y registros
        }
        else if(opcion==8){
            //Simular hasta terminar automoviles
        }
        else if(opcion==9){//Esta opcion es solo para probar el generador de cosas aleatorias de gestor luego se quita
            cout<<Gestor::generarBastidorRand()<<"\n";
            cout<<Gestor::modeloRand()<<"\n";
            cout<<Gestor::colorRand()<<"\n";
            cout<<Gestor::concesionarioRand()<<"\n";
        }
        else{
            cout<<error;
        }
    }
    return 0;
}
