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
    int np = 7; /*Gestor::generarNP(); //Genera el numero de vehiculos que caben en un camión (pila)*/
    int ns = 4 ;/*Gestor::generarNS(); //Genera el número de vehiculos a sacar de la fabrica*/
    //cambiar ns tmb al final opcion5&6 si se cambia

    //Instancias de las diferentes zonas
    ZonaReparto ZN = ZonaReparto("Zona Norte");
    ZonaReparto ZO = ZonaReparto ("Zona Oeste");
    ZonaReparto ZS = ZonaReparto ("Zona Sur");
    ZonaReparto ZE = ZonaReparto ("Zona Este");
    ZonaReparto zonas [4]= {ZN,ZO,ZS,ZE}; //Vector con las cuatro zonas, para elegir.

    Gestor g;
    Vehiculo v;
    ZonaReparto zona;
    Pila prueba;


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


        else if(opcion==6 || opcion==5)
        {

            if (opcion==6){
            cout<<"Cuantos automoviles salen de la fabrica?";
            cin>>ns;
            }

            int zona=rand()%4; //elige la zona a la que van, están en un vector las 4 al principio del main


            if (g.vehiculosFabrica.es_vacia())
            {
                cout<<"Almacen vacio"<<endl;
            }

            else if (ns>g.vehiculosFabrica.get_longitud())
            {
                cout<<"No hay suficientes automoviles para sacarlos"<< endl;
            }

            else if (ns <= np - zonas[zona].camion1.get_profundidad()+1)//miramos si los coches que se sacan caben en el primer camión
                {

                    for (int i=1; i<=ns ; i++){
                        zonas[zona].camion1.apilar(g.vehiculosFabrica.inicio());
                        g.vehiculosFabrica.desencolar();
                        cout<<"vehiculo metido \n";
                        }

                    cout<< "Se han cargado " << ns << " automoviles al camion 1. \n"<<endl;
                    cout<<"el camion 1 tiene "<<zonas[zona].camion1.get_profundidad() <<" automoviles \n";

                    if (zonas[zona].camion1.get_profundidad()>=np){ //El camion está lleno
                        //llevar a zona camion 1
                        while(!zonas[zona].camion1.esVacia()){
                            Vehiculo v = zonas[zona].camion1.mostrar();
                            int conc = rand()%nc+1;
                            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                            zonas[zona].vehiculosZona.encolar(v);
                            zonas[zona].camion1.desapilar();
                        }

                        cout<<"Camion 1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";

                    }

                }
            else{ //no hace falta mirar si caben en los dos camiones juntos ya que siempre vasn a caber; max(ns) < min (2*np); 8<14.

                    int contador=0;
                    while (zonas[zona].camion1.get_profundidad()<=np){//mientras haya hueco metemos al camion 1


                        zonas[zona].camion1.apilar(g.vehiculosFabrica.inicio());
                        g.vehiculosFabrica.desencolar();
                        cout<<"vehiculo metido \n";
                        contador+=1;
                        }

                        ns= ns-contador;
                        cout<< "Se han cargado " << contador << " automoviles al camion 1. \n"<<endl;
                        cout<<"el camion 1 tiene "<<zonas[zona].camion1.get_profundidad() <<" automoviles \n";



                    for (int i=1; i<=ns ; i++){ //Ahora metemos al camion 2 los que falten, ns-contador
                        zonas[zona].camion2.apilar(g.vehiculosFabrica.inicio());
                        g.vehiculosFabrica.desencolar();
                        cout<<"vehiculo metido \n";
                        }
                        cout<< "Se han cargado " << ns << " automoviles al camion 2. \n"<<endl;
                        cout<<"el camion 2 tiene "<<zonas[zona].camion2.get_profundidad() <<" automoviles \n";


                        //llevar a zona camion 1
                        while(!zonas[zona].camion1.esVacia()){
                            Vehiculo v = zonas[zona].camion1.mostrar();
                            int conc = rand()%nc+1;
                            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                            zonas[zona].vehiculosZona.encolar(v);
                            zonas[zona].camion1.desapilar();
                        }


                        cout<<"Camion1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";


                        if (zonas[zona].camion2.get_profundidad()==np){ //El camion2 tambien está lleno
                        //llevar a zona camión 2
                        while(!zonas[zona].camion2.esVacia()){
                            Vehiculo v = zonas[zona].camion2.mostrar();
                            int conc = rand()%nc+1;
                            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                            zonas[zona].vehiculosZona.encolar(v);
                            zonas[zona].camion2.desapilar();
                        }
                        cout<<"Camion2 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";
                        }

                        else { //El camion 2 no está lleno asi que pasamos sus coches al 1 para que se puedan volver a llenar
                                Pila aux=Pila();
                                while(!zonas[zona].camion2.esVacia()){
                                    aux.apilar(zonas[zona].camion2.mostrar());
                                    zonas[zona].camion1.apilar(aux.mostrar()); //Hace falta apilar por una pila intermedia aux para mantener el orden
                                    zonas[zona].camion2.desapilar();
                                }
                        }

                }

            ns = 4 ; //restauramos ns
            }

        else if(opcion==7)
        {
            //Mostrar datos de los camiones de las zonas y sus registros


            cout<<"Registro de la zona Norte,"<<"\n"; ZN.vehiculosZona.mostrar_cola();
            cout<<"Camion1 de la zona Norte,"<<"\n"; ZN.camion1.verPila();

            cout<<"Registro de la zona Este,"<< "\n"; ZE.vehiculosZona.mostrar_cola();
            cout<<"Camion1 de la zona Este,"<<"\n"; ZN.camion1.verPila();

            cout<<"Registro de la zona Sur, "<< "\n"; ZS.vehiculosZona.mostrar_cola();
            cout<<"Camion1 de la zona Sur,"<<"\n"; ZN.camion1.verPila();

            cout<<"Registro de la zona Oeste, "<<" \n"; ZO.vehiculosZona.mostrar_cola();
            cout<<"Camion1 de la zona Oeste,"<<"\n"; ZN.camion1.verPila();




        }
        else if(opcion==8)
        {
            //Simular hasta terminar automoviles
            while(!g.vehiculosFabrica.es_vacia()){
            int zona=rand()%4; //elige la zona a la que van, están en un vector las 4 al principio del main

            int contador=0;
                    while (zonas[zona].camion1.get_profundidad()<=np){//mientras haya hueco metemos al camion 1


                        zonas[zona].camion1.apilar(g.vehiculosFabrica.inicio());
                        g.vehiculosFabrica.desencolar();
                        cout<<"vehiculo metido \n";
                        contador+=1;
                        }

                        ns= ns-contador;
                        cout<< "Se han cargado " << contador << " automoviles al camion 1. \n"<<endl;
                        cout<<"el camion 1 tiene "<<zonas[zona].camion1.get_profundidad() <<" automoviles \n";



                    for (int i=1; i<=ns ; i++){ //Ahora metemos al camion 2 los que falten, ns-contador
                        zonas[zona].camion2.apilar(g.vehiculosFabrica.inicio());
                        g.vehiculosFabrica.desencolar();
                        cout<<"vehiculo metido \n";
                        }
                        cout<< "Se han cargado " << ns << " automoviles al camion 2. \n"<<endl;
                        cout<<"el camion 2 tiene "<<zonas[zona].camion2.get_profundidad() <<" automoviles \n";


                        //llevar a zona camion 1
                        while(!zonas[zona].camion1.esVacia()){
                            Vehiculo v = zonas[zona].camion1.mostrar();
                            int conc = rand()%nc+1;
                            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                            zonas[zona].vehiculosZona.encolar(v);
                            zonas[zona].camion1.desapilar();
                        }


                        cout<<"Camion1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";


                        if (zonas[zona].camion2.get_profundidad()==np){ //El camion2 tambien está lleno
                        //llevar a zona camión 2
                        while(!zonas[zona].camion2.esVacia()){
                            Vehiculo v = zonas[zona].camion2.mostrar();
                            int conc = rand()%nc+1;
                            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                            zonas[zona].vehiculosZona.encolar(v);
                            zonas[zona].camion2.desapilar();
                        }
                        cout<<"Camion2 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";
                        }

                        else { //El camion 2 no está lleno asi que pasamos sus coches al 1 para que se puedan volver a llenar
                                Pila aux=Pila();
                                while(!zonas[zona].camion2.esVacia()){
                                    aux.apilar(zonas[zona].camion2.mostrar());
                                    zonas[zona].camion1.apilar(aux.mostrar()); //Hace falta apilar por una pila intermedia aux para mantener el orden
                                    zonas[zona].camion2.desapilar();
                                }
                        }





            }

        }
        else
        {
            cout<<error;
        }
    }
    return 0;
}
