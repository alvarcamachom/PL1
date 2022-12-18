#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"
#include "Cola.h"
#include "ZonaReparto.h"
#include "Pedido.h"
#include "ABB.h"

using namespace std;

int nv = 12;
int ns = 4 ;
int np = 7;
int nc = 10;



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

void Gestor::generarPedidos(int nc) //Generar aleatoriamente nc*2 pedidos, teniendo cada concesionario, 2 pedidos.
{
    for (int k=0; k<2; k++) //Dos vehiculos por concesionario
    {

        for (int i=1; i<nc+1; i++) //Para cada concesionario
        {
            Pedido ped = Pedido(i);
            cout<<"i: "<<i<<endl;
            if(ped.getTipo()=="P")
            {
                listaPedidos.insertar_prioridad(ped);
                cout<<"Pedido prioritario insertado: "<<ped.verPedido()<<endl;
            }
            else if(ped.getTipo()=="N")  //else if para asegurar que el tipo es solo N o P
            {
                listaPedidos.insertar_derecha(ped);
                cout<<"Pedido no prioritario insertado: "<<ped.verPedido()<<endl;
            }
            else
            {
                cout<<"Error en la prioridad del pedido"<<endl;
            }
        }

    }
    cout<<"Se han metido los pedidos a la lista"<<endl;
}

void Gestor::generarPedidosCustom(int n)
{
    for (int i=0; i<n; i++)
    {
        string color;
        string modelo;
        string tipo;
        Vehiculo ve;
        color = ve.pedirColor();
        modelo = ve.pedirModelo();
        tipo = ve.pedirTipo();

        Pedido ped = Pedido(modelo, color, tipo);

        if(ped.getTipo()=="P")
        {
            listaPedidos.insertar_prioridad(ped);
            cout<<"Pedido "<<i+1<<" prioritario insertado: "<<ped.verPedido()<<endl;
        }
        else if(ped.getTipo()=="N")  //else if para asegurar que el tipo es solo N o P
        {
            listaPedidos.insertar_derecha(ped);
            cout<<"Pedido "<<i+1<<" no prioritario insertado: "<<ped.verPedido()<<endl;
        }
        else
        {
            cout<<"Error en la prioridad del pedido"<<endl;
        }

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


Cola Gestor::buscaPedidos(int ns) //metodo que toma el numero de pedidos a buscar. Itera la lista de pedidos y la cola de fabrica.
//Si coincide lo elimina de ambas y lo pasa a la nueva cola a devolver.
//Finalmente restauramos la cola de fabrica

//SI SE DESCOMENTA LO COMENTADO, LOS VEHICULOS QUE NO COINCIDAN SE MANTENDRÁN EL LA FABRICA
{
    Cola aux1;
    Cola aux2;

    if(listaPedidos.get_longitud()<ns)
    {
        cout<<"No hay suficientes pedidos"<<endl;
    }
    /*else if (listaPedidos.get_longitud()>vehiculosFabrica.get_longitud())
    {
        cout<<"No hay suficientes coches"<<endl;
    }*/
    else
    {

        for (int i=1; i<=ns; i++)
        {

            Pedido ped = listaPedidos.ver_posicion(1);
            int lo=vehiculosFabrica.get_longitud();
            for (int j=0; j<lo; j++)
            {
                Vehiculo v = vehiculosFabrica.inicio();
                if (v.devolverColor()==ped.getColor() && v.devolverModelo()==ped.getModelo() )
                {
                    v.set_concesionario(ped.getConcesionario());
                    v.setZona(ped.getZona());
                    aux1.encolar(v);
                    listaPedidos.borrar_posicion(1);
                    vehiculosFabrica.desencolar();
                    cout<<"Pedido encontrado"<<endl;
                    /*if(i==4)
                    {   int longit= vehiculosFabrica.get_longitud();
                        for(int p=0; p<longit; p++ ) //Si es la ultima iteracion metemos los ultimos vehiculos sin revisar para que no se pierdan
                        {
                            aux2.encolar(vehiculosFabrica.inicio());
                            vehiculosFabrica.desencolar();
                        }
                    }*/
                    break;
                }
                else
                {
                    //aux2.encolar(vehiculosFabrica.inicio());
                    vehiculosFabrica.desencolar();
                    cout<<"Coche no coincide con pedido. Borrando..."<<endl;
                }
            }
        }
        //vehiculosFabrica=aux2;
        return aux1;
    }
}

void Gestor::vehiculosAZona(Cola peds)
{
    zonas[0].setNombre("N");
    zonas[1].setNombre("S");
    zonas[2].setNombre("E");
    zonas[3].setNombre("O");

    if (peds.es_vacia())
    {
        if(vehiculosFabrica.es_vacia())
        {
            cout<<"No quedan vehiculos."<<endl;
        }
        else
        {
            cout<<"No se han encontrado los pedidos"<<endl;
        }
    }
    else
    {
        int longi=peds.get_longitud();
        for (int k=1; k<= longi; k++)
        {
            int zona = peds.inicio().getZona();
            if (np - zonas[zona].profundidadCamion1()+1 > 0)//miramos si los coches que se sacan caben en el primer camión
            {
                zonas[zona].meterCamion1(peds.inicio());
                peds.desencolar();
                cout<<"vehiculo metido en el camion 1 de la zona "<< zonas[zona].getNombre()<<"\n";
                zonas[zona].verCamion1();
            }
            else   //sino los metemos al segundo
            {
                zonas[zona].meterCamion2(peds.inicio());
                peds.desencolar();
                cout<<"vehiculo metido en el camion 2 de la zona "<< zonas[zona].getNombre()<<"\n";
                zonas[zona].verCamion2();
            }
        }
        for (int j=0; j<4; j++)  //Miramos si algún camión está lleno para vaciarlo (llevar a zona)
        {
            if (zonas[j].profundidadCamion1()>=np)
            {
                for(int k=1; k<=8; k++)  //movemos los ocho oches del camion a la cola de zona
                {
                    zonas[j].meterRegistro(zonas[j].mostrarCamion1());
                    zonas[j].sacarCamion1();
                }
            }
            if (zonas[j].profundidadCamion2()>=np)
            {
                for(int h=1; h<=8; h++)  //movemos los ocho oches del camion a la cola de zona
                {
                    zonas[j].meterRegistro(zonas[j].mostrarCamion2());
                    zonas[j].sacarCamion2();
                }
            }
        }
    }
}





void Gestor::mostrarZonas()
{
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"********************REGISTROS********************"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;



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


        if (listaPedidos.es_vacia())
        {
            cout<<"No hay más pedidos. Aun quedan coches"<<endl;
            cout<<"Fabrica: "<<vehiculosFabrica.get_longitud()<<endl;
            cout<<"Pedidos: "<<listaPedidos.get_longitud()<<endl;
            break;
        }
        else
        {

            vehiculosAZona(buscaPedidos(ns));

            //cout<<"Vehiculos en el almacen de la fabrica: "<<endl;
            //mostrarVehiculosFabrica();
            cout<<"Fabrica: "<<vehiculosFabrica.get_longitud()<<endl;
            cout<<"Pedidos: "<<listaPedidos.get_longitud()<<endl;

            mostrarZonas();
        }

    }
    cout<<"#####################"<<endl;

    cout<<"Fin de la simulacion."<<endl;

    cout<<"#####################"<<endl;

}

void Gestor::verPedidos()
{
    listaPedidos.mostrar();
}

void Gestor::borrarPedidos()
{
    listaPedidos.vaciar_lista();
    cout<<"Se ha borrado la lista de pedidos"<<endl;
}

void Gestor::insertAutomovilABB(string col, string mod, int concesionario, string bastidor)
{
    //meter en el arbol el automovil con esos datos
    Vehiculo vehic = Vehiculo(mod, col, bastidor, concesionario);
    //Concesionario c = Concesionario(concesionario, "zona?", )
    }

void Gestor::verConcZona(string bastidor){
    //Ver el concesionario y zona del vehiculo que tiene el bastidor introducido

}

void Gestor::verVehiculosConcesionario(int numc){
    //Ver los vehiculos que hay en el concesionario dado

}

void Gestor::eliminarModelo(string modelo){
    //eliminar el modelo del arbol
}

void Gestor::pruebaABB()
{
    zonas[0].setNombre("N");
    zonas[1].setNombre("S");
    zonas[2].setNombre("E");
    zonas[3].setNombre("O");
    Lista listaPrueba;
    Vehiculo v1 = Vehiculo();
    Vehiculo v2 = Vehiculo();
    Vehiculo v3 = Vehiculo();
    //Aqui estaba haciendo las pruebas del arbol y me he dado cuenta que concesionario
    //tiene que tener una lista de vehiculos... pero la implementacion de listas
    //la tenemos con pedido, entonces da error, habria que crear otra clase listaVehiculos??
    //o meter los vehiculos en una lista normal de c? esta parte me esta rayando
    /*listaPrueba.insertar_izquierda(v1);
    listaPrueba.insertar_izquierda(v2);
    listaPrueba.insertar_izquierda(v3);
    Concesionario cagd = Concesionario(3, zonas[2], listaPrueba);
    ABB arbolPrueba = ABB(cagd, NodoABB *hIz, NodoABB *hDer);
    arbolPrueba.verInOrden();*/
}

Gestor::~Gestor()
{
    //dtor
}
