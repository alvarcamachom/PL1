#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"

using namespace std;

Gestor::Gestor()
{
    //ctor
}

void Gestor::crearVehiculo(int nv)
{
    for (int i=1; i<=nv; i++)
    {
        Vehiculo carro = Vehiculo();
        cout << carro.verVehiculo()<<endl; //Mostramos el vehículo antes de meterlo a la cola
        vehiculosFabrica.encolar(carro);//Meter vehiculo en cola
        cout<<"Vehiculo metido en almacen"<<endl;
        cout<<""<<endl;
    }
}


void Gestor::mostrarVehiculosFabrica() //Muestra los vehiculos en la cola de la fabrica
{
    vehiculosFabrica.mostrar_cola();
}


void Gestor::borrarVehiculosFabrica() //Borrar todos los vehiculos de la cola
{
    if (vehiculosFabrica.es_vacia())
    {
        cout<<"Almacen vacio"<<endl;
    }
    else
    {
        while (!vehiculosFabrica.es_vacia())
        {
            vehiculosFabrica.desencolar();
        }
    }
}


void Gestor::vehiculosAZona(int zona, int ns)
{
    zonas[0].setNombre("Zona Norte");
    zonas[1].setNombre("Zona Oeste");
    zonas[2].setNombre("Zona Sur");
    zonas[3].setNombre("Zona Este");
    if (vehiculosFabrica.es_vacia())
    {
        cout<<"Almacen vacio"<<endl;
    }

    else if (ns>vehiculosFabrica.get_longitud())
    {
        cout<<"No hay suficientes automoviles para sacarlos"<< endl;
    }

    else if (ns <= np - zonas[zona].camion1.get_profundidad()+1)//miramos si los coches que se sacan caben en el primer camión
    {

        for (int i=1; i<=ns ; i++)
        {
            zonas[zona].camion1.apilar(vehiculosFabrica.inicio());
            zonas[zona].camion1.verPila();
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido en la zona "<< zonas[zona].getNombre()<<"\n";
        }

        cout<< "Se han cargado " << ns << " automoviles al camion 1. \n"<<endl;
        cout<<"el camion 1 tiene "<<zonas[zona].camion1.get_profundidad() <<" automoviles \n";

        if (zonas[zona].camion1.get_profundidad()>=np)  //El camion está lleno
        {
            //llevar a zona camion 1
            while(!zonas[zona].camion1.esVacia())
            {
                Vehiculo v = zonas[zona].camion1.mostrar();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                zonas[zona].vehiculosZona.encolar(v);
                zonas[zona].camion1.desapilar();
            }

            cout<<"Camion 1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";

        }

    }
    else  //no hace falta mirar si caben en los dos camiones juntos ya que siempre vasn a caber; max(ns) < min (2*np); 8<14.
    {

        int contador=0;
        while (zonas[zona].camion1.get_profundidad()<=np) //mientras haya hueco metemos al camion 1
        {


            zonas[zona].camion1.apilar(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido \n";
            contador+=1;
        }

        ns= ns-contador;
        cout<< "Se han cargado " << contador << " automoviles al camion 1. \n"<<endl;
        cout<<"el camion 1 tiene "<<zonas[zona].camion1.get_profundidad() <<" automoviles \n";



        for (int i=1; i<=ns ; i++)  //Ahora metemos al camion 2 los que falten, ns-contador
        {
            zonas[zona].camion2.apilar(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido \n";
        }
        cout<< "Se han cargado " << ns << " automoviles al camion 2. \n"<<endl;
        cout<<"el camion 2 tiene "<<zonas[zona].camion2.get_profundidad() <<" automoviles \n";


        //llevar a zona camion 1
        while(!zonas[zona].camion1.esVacia())
        {
            Vehiculo v = zonas[zona].camion1.mostrar();
            int conc = rand()%nc+1;
            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
            zonas[zona].vehiculosZona.encolar(v);
            zonas[zona].camion1.desapilar();
        }


        cout<<"Camion1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";


        if (zonas[zona].camion2.get_profundidad()==np)  //El camion2 tambien está lleno
        {
            //llevar a zona camión 2
            while(!zonas[zona].camion2.esVacia())
            {
                Vehiculo v = zonas[zona].camion2.mostrar();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                zonas[zona].vehiculosZona.encolar(v);
                zonas[zona].camion2.desapilar();
            }
            cout<<"Camion2 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";
        }

        else   //El camion 2 no está lleno asi que pasamos sus coches al 1 para que se puedan volver a llenar
        {
            Pila aux=Pila();
            while(!zonas[zona].camion2.esVacia())
            {
                aux.apilar(zonas[zona].camion2.mostrar());
                zonas[zona].camion1.apilar(aux.mostrar()); //Hace falta apilar por una pila intermedia aux para mantener el orden
                zonas[zona].camion2.desapilar();
            }
        }

    }

    ns = 4 ; //restauramos ns
}


void Gestor::mostrarZonas()
{

    cout<<"Registro de la zona Norte,"<<"\n";
    zonas[0].vehiculosZona.mostrar_cola();
    cout<<"Camion1 de la zona Norte,"<<"\n";
    zonas[0].camion1.verPila();

    cout<<"Registro de la zona Oeste,"<< "\n";
    zonas[1].vehiculosZona.mostrar_cola();
    cout<<"Camion1 de la zona Oeste,"<<"\n";
    zonas[1].camion1.verPila();

    cout<<"Registro de la zona Sur, "<< "\n";
    zonas[2].vehiculosZona.mostrar_cola();
    cout<<"Camion1 de la zona Sur,"<<"\n";
    zonas[2].camion1.verPila();

    cout<<"Registro de la zona Este, "<<" \n";
    zonas[3].vehiculosZona.mostrar_cola();
    cout<<"Camion1 de la zona Este,"<<"\n";
    zonas[3].camion1.verPila();



}

void Gestor::finSimulacion(int ns)
{
    while(!vehiculosFabrica.es_vacia())
    {
        int zona=rand()%4; //elige la zona a la que van, están en un vector las 4 al principio del main

        int contador=0;
        while (zonas[zona].camion1.get_profundidad()<=np) //mientras haya hueco metemos al camion 1
        {


            zonas[zona].camion1.apilar(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido \n";
            contador+=1;
        }

        ns = ns-contador;
        cout<< "Se han cargado " << contador << " automoviles al camion 1. \n"<<endl;
        cout<<"el camion 1 tiene "<<zonas[zona].camion1.get_profundidad() <<" automoviles \n";



        for (int i=1; i<=ns ; i++)  //Ahora metemos al camion 2 los que falten, ns-contador
        {
            zonas[zona].camion2.apilar(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido \n";
        }
        cout<< "Se han cargado " << ns << " automoviles al camion 2. \n"<<endl;
        cout<<"el camion 2 tiene "<<zonas[zona].camion2.get_profundidad() <<" automoviles \n";


        //llevar a zona camion 1
        while(!zonas[zona].camion1.esVacia())
        {
            Vehiculo v = zonas[zona].camion1.mostrar();
            int conc = rand()%nc+1;
            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
            zonas[zona].vehiculosZona.encolar(v);
            zonas[zona].camion1.desapilar();
        }


        cout<<"Camion1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";


        if (zonas[zona].camion2.get_profundidad()==np)  //El camion2 tambien está lleno
        {
            //llevar a zona camión 2
            while(!zonas[zona].camion2.esVacia())
            {
                Vehiculo v = zonas[zona].camion2.mostrar();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                zonas[zona].vehiculosZona.encolar(v);
                zonas[zona].camion2.desapilar();
            }
            cout<<"Camion2 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";
        }

        else   //El camion 2 no está lleno asi que pasamos sus coches al 1 para que se puedan volver a llenar
        {
            Pila aux=Pila();
            while(!zonas[zona].camion2.esVacia())
            {
                aux.apilar(zonas[zona].camion2.mostrar());
                zonas[zona].camion1.apilar(aux.mostrar()); //Hace falta apilar por una pila intermedia aux para mantener el orden
                zonas[zona].camion2.desapilar();
            }
        }





    }
}

Gestor::~Gestor()
{
    //dtor
}
