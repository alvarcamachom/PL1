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
        cout << carro.verVehiculo()<<endl; //Mostramos el veh�culo antes de meterlo a la cola
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

    else if (ns <= np - zonas[zona].profundidadCamion1()+1)//miramos si los coches que se sacan caben en el primer cami�n
    {

        for (int i=1; i<=ns ; i++)
        {
            zonas[zona].meterCamion1(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido en el camion de la zona "<< zonas[zona].getNombre()<<"\n";
            zonas[zona].verCamion1();
        }

        cout<< "Se han cargado " << ns << " automoviles al camion 1. \n"<<endl;
        cout<<"el camion 1 tiene "<<zonas[zona].profundidadCamion1() <<" automoviles \n";

        if (zonas[zona].profundidadCamion1()>=np)  //El camion est� lleno
        {
            //llevar a zona camion 1
            while(!zonas[zona].esCamion1Vacio())
            {
                Vehiculo v = zonas[zona].mostrarCamion1();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el m�ximo establecido (nc)
                zonas[zona].meterRegistro(v);
                zonas[zona].sacarCamion1();
            }

            cout<<"Camion 1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";

        }

    }
    else  //no hace falta mirar si caben en los dos camiones juntos ya que siempre vasn a caber; max(ns) < min (2*np); 8<14.
    {

        int contador=0;
        while (zonas[zona].profundidadCamion1()<=np) //mientras haya hueco metemos al camion 1
        {


            zonas[zona].meterCamion1(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido \n";
            contador+=1;
        }

        ns= ns-contador;
        cout<< "Se han cargado " << contador << " automoviles al camion 1. \n"<<endl;
        cout<<"el camion 1 tiene "<<zonas[zona].profundidadCamion1() <<" automoviles \n";



        for (int i=1; i<=ns ; i++)  //Ahora metemos al camion 2 los que falten, ns-contador
        {
            zonas[zona].meterCamion2(vehiculosFabrica.inicio());
            vehiculosFabrica.desencolar();
            cout<<"vehiculo metido \n";
        }
        cout<< "Se han cargado " << ns << " automoviles al camion 2. \n"<<endl;
        cout<<"el camion 2 tiene "<<zonas[zona].profundidadCamion2() <<" automoviles \n";


        //llevar a zona camion 1
        while(!zonas[zona].esCamion1Vacio())
        {
            Vehiculo v = zonas[zona].mostrarCamion1();
            int conc = rand()%nc+1;
            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el m�ximo establecido (nc)
            zonas[zona].meterRegistro(v);
            zonas[zona].sacarCamion1();
        }


        cout<<"Camion1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";


        if (zonas[zona].profundidadCamion2()==np)  //El camion2 tambien est� lleno
        {
            //llevar a zona cami�n 2
            while(!zonas[zona].esCamion2Vacio())
            {
                Vehiculo v = zonas[zona].mostrarCamion2();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el m�ximo establecido (nc)
                zonas[zona].meterRegistro(v);
                zonas[zona].sacarCamion2();
            }
            cout<<"Camion2 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";
        }

        else   //El camion 2 no est� lleno asi que pasamos sus coches al 1 para que se puedan volver a llenar
        {
            Pila aux=Pila();
            while(!zonas[zona].esCamion2Vacio())
            {
                aux.apilar(zonas[zona].mostrarCamion2());
                zonas[zona].meterCamion1(aux.mostrar()); //Hace falta apilar por una pila intermedia aux para mantener el orden
                zonas[zona].sacarCamion2();
            }
        }

    }

    ns = 4 ; //restauramos ns
}


void Gestor::mostrarZonas()
{

    cout<<"Registro de la zona Norte,"<<"\n";
    zonas[0].verRegistro();
    cout<<"Camion1 de la zona Norte,"<<"\n";
    zonas[0].verCamion1();
    cout<<"Camion2 de la zona Norte,"<<"\n";
    zonas[0].verCamion2();

    cout<<"Registro de la zona Oeste,"<< "\n";
    zonas[1].verRegistro();
    cout<<"Camion1 de la zona Oeste,"<<"\n";
    zonas[1].verCamion1();
    cout<<"Camion2 de la zona Oeste,"<<"\n";
    zonas[1].verCamion2();

    cout<<"Registro de la zona Sur, "<< "\n";
    zonas[2].verRegistro();
    cout<<"Camion1 de la zona Sur,"<<"\n";
    zonas[2].verCamion1();
    cout<<"Camion2 de la zona Sur,"<<"\n";
    zonas[2].verCamion2();

    cout<<"Registro de la zona Este, "<<" \n";
    zonas[3].verRegistro();
    cout<<"Camion1 de la zona Este,"<<"\n";
    zonas[3].verCamion1();
    cout<<"Camion2 de la zona Este,"<<"\n";
    zonas[3].verCamion2();



}

void Gestor::finSimulacion(int ns)
{

}

Gestor::~Gestor()
{
    //dtor
}
