#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"
#include "Pedido.h"

using namespace std;

int nv = 12;
int ns = 4 ;
int np = 7;
int nc = 5;



Gestor::Gestor()
{
    //ctor
}


void Gestor::crearVehiculo(int nv) //Genera nv vehiuclos aleatorios
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

void Gestor::generarNVVehiculos(int nv) //Genera nv vehivulos aleatorios, de cada color y de cada modelo
{
    for (int i=1; i<=nv; i++)
    {

        vehiculosFabrica.encolar(Vehiculo("M1","C1"));//Meter vehiculo en cola
        vehiculosFabrica.encolar(Vehiculo("M2","C1"));
        vehiculosFabrica.encolar(Vehiculo("M3","C1"));
        vehiculosFabrica.encolar(Vehiculo("M4","C1"));
        vehiculosFabrica.encolar(Vehiculo("M5","C1"));
        vehiculosFabrica.encolar(Vehiculo("M1","C2"));
        vehiculosFabrica.encolar(Vehiculo("M2","C2"));
        vehiculosFabrica.encolar(Vehiculo("M3","C2"));
        vehiculosFabrica.encolar(Vehiculo("M4","C2"));
        vehiculosFabrica.encolar(Vehiculo("M5","C2"));
        vehiculosFabrica.encolar(Vehiculo("M1","C3"));
        vehiculosFabrica.encolar(Vehiculo("M2","C3"));
        vehiculosFabrica.encolar(Vehiculo("M3","C3"));
        vehiculosFabrica.encolar(Vehiculo("M4","C3"));
        vehiculosFabrica.encolar(Vehiculo("M5","C3"));

    }
}

void Gestor::generarPedidos(int nc) //Generar aleatoriamente nc*2 pedidos
{
    for (int i=0; i<nc*2; i++)
    {
        Pedido ped = Pedido();

        if(ped.getTipo()=="P")
        {
            listaPedidos.insertar_izquierda(ped);
        }
        else if(ped.getTipo()=="N")  //else if para asegurar que el tipo es solo N o P
        {
            listaPedidos.insertar_derecha(ped);
        }
        else
        {
            cout<<"Error en la prioridad del pedido"<<endl;
        }
    }
    cout<<"Se han metido los pedidos a la lista"<<endl;
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
    zonas[0].setNombre("N");
    zonas[1].setNombre("S");
    zonas[2].setNombre("E");
    zonas[3].setNombre("O");

    if (vehiculosFabrica.es_vacia())
    {
        cout<<"Almacen vacio"<<endl;
    }

    else if (ns>vehiculosFabrica.get_longitud())
    {
        cout<<"No hay suficientes automoviles para sacarlos"<< endl;
    }

    else if (ns <= np - zonas[zona].profundidadCamion1()+1)//miramos si los coches que se sacan caben en el primer camión
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

        if (zonas[zona].profundidadCamion1()>=np)  //El camion está lleno
        {
            //llevar a zona camion 1
            while(!zonas[zona].esCamion1Vacio())
            {
                Vehiculo v = zonas[zona].mostrarCamion1();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
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
            v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
            zonas[zona].meterRegistro(v);
            zonas[zona].sacarCamion1();
        }


        cout<<"Camion1 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";


        if (zonas[zona].profundidadCamion2()==np)  //El camion2 tambien está lleno
        {
            //llevar a zona camión 2
            while(!zonas[zona].esCamion2Vacio())
            {
                Vehiculo v = zonas[zona].mostrarCamion2();
                int conc = rand()%nc+1;
                v.set_concesionario(conc); //Asignamos un concesionario entre 1 y el máximo establecido (nc)
                zonas[zona].meterRegistro(v);
                zonas[zona].sacarCamion2();
            }
            cout<<"Camion2 lleno, saliendo para la "<< zonas[zona].getNombre()<<"\n";
        }

        else   //El camion 2 no está lleno asi que pasamos sus coches al 1 para que se puedan volver a llenar
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


}


void Gestor::mostrarZonas()
{

    cout<<"Registro de la zona N,"<<"\n";
    zonas[0].verRegistro();
    cout<<"Camion1 de la zona N,"<<"\n";
    zonas[0].verCamion1();
    cout<<"Camion2 de la zona N,"<<"\n";
    zonas[0].verCamion2();
    cout<<endl;

    cout<<"Registro de la zona S,"<< "\n";
    zonas[1].verRegistro();
    cout<<"Camion1 de la zona S,"<<"\n";
    zonas[1].verCamion1();
    cout<<"Camion2 de la zona S,"<<"\n";
    zonas[1].verCamion2();
    cout<<endl;

    cout<<"Registro de la zona E, "<< "\n";
    zonas[2].verRegistro();
    cout<<"Camion1 de la zona E,"<<"\n";
    zonas[2].verCamion1();
    cout<<"Camion2 de la zona E,"<<"\n";
    zonas[2].verCamion2();
    cout<<endl;

    cout<<"Registro de la zona O, "<< "\n";
    zonas[3].verRegistro();
    cout<<"Camion1 de la zona O,"<<"\n";
    zonas[3].verCamion1();
    cout<<"Camion2 de la zona O,"<<"\n";
    zonas[3].verCamion2();
    cout<<endl;




}

void Gestor::finSimulacion(int ns)
{

    while(!vehiculosFabrica.es_vacia())
    {

        int zona=rand()%4;

        if (ns>vehiculosFabrica.get_longitud())
        {

            vehiculosAZona(zona, vehiculosFabrica.get_longitud()); //Si queremos sacar más de los que quedan, sacamos todos los que queden

            cout<<"Vehiculos en el almacen de la fabrica: "<<endl;
            mostrarVehiculosFabrica();

            mostrarZonas();
        }
        else
        {

            vehiculosAZona(zona, ns);

            cout<<"Vehiculos en el almacen de la fabrica: "<<endl;
            mostrarVehiculosFabrica();

            mostrarZonas();
        }

    }

}

void Gestor::verPedidos(){
    listaPedidos.mostrar();
}

void Gestor::borrarPedidos(){
    listaPedidos.vaciar_lista();
    cout<<"Se ha borrado la lista de pedidos"<<endl;
}

void Gestor::pruebaLista()
{
    Lista listaPrueba;
    Pedido pedido1 = Pedido();
    Pedido pedido2 = Pedido();
    Pedido pedido3 = Pedido();
    listaPrueba.insertar_izquierda(pedido1);
    listaPrueba.insertar_izquierda(pedido2);
    listaPrueba.insertar_izquierda(pedido3);
    listaPrueba.mostrar();
    cout<<"Borro dato del medio"<<endl;
    listaPrueba.borrar_posicion(1);
    listaPrueba.mostrar();
    //Listas funciona bien con pedidos
}

void Gestor::buscarListaPedidos(){
    //un intento de buscar vehiculo de la cola de fabrica en la lista de pedidos, un desastre sin sentido jajaj
    for (int i=0; i<vehiculosFabrica.get_longitud(); i++){
        Vehiculo vehic = vehiculosFabrica.inicio();
        colaAux.encolar(vehic);
        string colorV = vehic.devolverColor();
        string modeloV = vehic.devolverModelo();
        Pedido pedid = listaPedidos.ver_posicion(i+1);
        string colorP = pedid.getColor();
        string modeloP = pedid.getModelo();
        if (colorV==colorP and modeloV==modeloP){
            cout<<"estatattyw4e5yw45tae"<<endl;
        }
    }
}

Gestor::~Gestor()
{
    //dtor
}
