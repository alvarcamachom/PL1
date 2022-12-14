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
int nc = 12;



Gestor::Gestor()
{
    //ctor
}


void Gestor::crearVehiculo(int nv) //Genera nv vehiuclos aleatorios
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
        Pedido ped = Pedido(nc);

        if(ped.getTipo()=="P")
        {
            listaPedidos.insertar_prioridad(ped);
            cout<<"Pedido"<<i<<" prioritario insertado: "<<ped.verPedido()<<endl;
        }
        else if(ped.getTipo()=="N")  //else if para asegurar que el tipo es solo N o P
        {
            listaPedidos.insertar_derecha(ped);
            cout<<"Pedido"<<i<<" no prioritario insertado: "<<ped.verPedido()<<endl;
        }
        else
        {
            cout<<"Error en la prioridad del pedido"<<endl;
        }
    }
    cout<<"Se han metido los pedidos a la lista"<<endl;
}

void Gestor::generarPedidosCustom(int n)
{
    for (int i=0; i<n; i++)
    {
        string col;
        string mod;
        string tipo;
        //int zona;
        cout<<"Color pedido "<<i+1<<": C1, C2, C3"<<endl;
        cin>>col;
        cout<<"Modelo pedido "<<i+1<<": M1, M2, M3, M4, M5"<<endl;
        cin>>mod;
        cout<<"Tipo pedido "<<i+1<<": 'P', 'N'"<<endl;
        cin>>tipo;
        //cout<<"Zona pedido "<<i+1<<": 1(N), 2(S), 3(E), 4(O)"<<endl;
        //cin>>zona;
        Pedido ped = Pedido(mod, col, tipo);

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


Cola Gestor::buscaPedidos(int ns) //metodo que toma el numero de pedidos a buscar. Itera la lista de pedidos y la cola de fabrica. Si coincide lo elimina de ambas y lo pasa a la nueva cola a devolver.
//Finalmente restauramos la cola de fabrica
{
    Cola aux1;
    Cola aux2;

    if(listaPedidos.get_longitud()<ns)
    {
        cout<<listaPedidos.get_longitud()<<endl;
        cout<<"No hay suficientes pedidos"<<endl;
    }
    else if (listaPedidos.get_longitud()>vehiculosFabrica.get_longitud())
    {
        cout<<"No hay suficientes coches"<<endl;
    }
    else
    {

        for (int i=1; i<=ns; i++)
        {

            Pedido ped = listaPedidos.ver_posicion(1);
            for (int j=0; j<vehiculosFabrica.get_longitud(); j++)
            {
                Vehiculo v = vehiculosFabrica.inicio();
                if (v.devolverColor()==ped.getColor() && v.devolverModelo()==ped.getModelo() )
                {
                    v.set_concesionario(ped.getConcesionario());
                    v.setZona(ped.getZona());
                    aux1.encolar(v);
                    listaPedidos.borrar_posicion(1);
                    vehiculosFabrica.desencolar();
                    break;
                }
                else
                {
                    aux2.encolar(vehiculosFabrica.inicio());
                    vehiculosFabrica.desencolar();
                }

            }
        }

        vehiculosFabrica=aux2;
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
        cout<<"No se han encontrado los pedidos"<<endl;
    }
    else
    {

        for (int k=1; k<= ns; k++)
        {
            int zona = peds.inicio().getZona();
            if (np - zonas[zona].profundidadCamion1()+1 > 0)//miramos si los coches que se sacan caben en el primer cami�n
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
        for (int j=0; j<4; j++)  //Miramos si alg�n cami�n est� lleno para vaciarlo (llevar a zona)
        {
            if (zonas[j].profundidadCamion1()>=np)
            {
                zonas[j].meterRegistro(zonas[j].mostrarCamion1());
            }
            if (zonas[j].profundidadCamion2()>=np)
            {
                zonas[j].meterRegistro(zonas[j].mostrarCamion2());
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

/*void Gestor::finSimulacion(int ns)
{

    while(!vehiculosFabrica.es_vacia())
    {

        int zona=rand()%4;

        if (ns>vehiculosFabrica.get_longitud())
        {

            vehiculosAZona(zona, vehiculosFabrica.get_longitud()); //Si queremos sacar m�s de los que quedan, sacamos todos los que queden

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

}*/

void Gestor::verPedidos()
{
    listaPedidos.mostrar();
}

void Gestor::borrarPedidos()
{
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
    cout<<"longitud: ";
    cout<<listaPrueba.get_longitud()<<endl;
    listaPrueba.mostrar();
    cout<<"Borro dato del medio"<<endl;
    listaPrueba.borrar_posicion(1);
    listaPrueba.mostrar();
    cout<<"longitud despues de borrar: ";
    cout<<listaPrueba.get_longitud()<<endl;
    //Listas funciona bien con pedidos
}

/*void Gestor::buscarListaPedidos(){
    //un intento de buscar vehiculo de la cola de fabrica en la lista de pedidos, mal todo
    //Aqui es donde hay que poner lo de que si se queda vacia la colaFabrica se hagan todos prioritarios, y en el de
    //hasta finalizar la simulacion no?

    for (int i=0; i<vehiculosFabrica.get_longitud(); i++){
        Vehiculo vehic = vehiculosFabrica.inicio(); //la idea era ir sacando cada coche de la cola de fabrica e ir buscandolo en pedidos
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
}*/

Gestor::~Gestor()
{
    //dtor
}
