#include "Gestor.h"
#include <time.h>
#include "Vehiculo.h"
#include "Pila.h"

using namespace std;

Gestor::Gestor()
{
    //ctor
}


string Gestor::generarBastidorRand(){
    string bastidor = "";
    string letras="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i<5; i++){ //generamos las 5 letras aleatorias
        int r = rand()%26;
        bastidor+=letras[r];
    }
    int numeros = rand()%100 +100; //Generamos los 3 numeros aleatorios
    bastidor+=to_string(numeros); //Pasamos los numeros a string y los concatenamos

    return bastidor;
}

string Gestor::modeloRand(){
    string modelos[6] = {"Zafira","Octavia","Golf","Astra","Insignia","Polo"};
    int s = rand()%6;
    string modelo = modelos[s]; //elegimos elemento aleatorio s de la lista
    return modelo;
}

string Gestor::colorRand(){
    string colores[6] ={"Azul","Verde","Amarillo","Gris","Negro","Blanco"};
    int t = rand()%6;
    string color = colores[t];
    return color;
}


int Gestor::generarNC(){
    rand()%7 +4; //numero aleatorio entre 4 y 10 (numero concesionarios)
}
int Gestor::generarNV(){
    return rand()%21 + 10; //numero aleatorio entre 10 y 30 (numero vehiculos)
}
int Gestor::generarNS(){
    return rand()%6 +3; //numero aleatorio entre 3 y 8 (vehiculos que salen de fabrica)
}
int Gestor::generarNP(){
    return rand()%6 +7; //numero aleatorio entre 7 y 12 (numero vehiculos que entran en camion)
}

void encolarVehiculo(int nv){
    Cola vehiculosFabrica;
    for (int i=1; i<=nv; i++){
                Vehiculo vh = Vehiculo(); //Generar vehiculo datos aleatorios
                vehiculosFabrica.encolar(vh);//Meter vehiculo en cola (posiblemente mal porque en apartado 3 no se ve nada)
                cout<<vh.verVehiculo()<<endl;
}
}
void Gestor::mostrarVehiculosFabrica(){//Muestra los vehiculos en la cola de la fabrica
    Cola colaAux;
    Vehiculo vAux;
    while ((!vehiculosFabrica.es_vacia()) && (vehiculosFabrica.get_longitud() > 0)) {
        cout<<"vehiculosFabrica longitud  = "+to_string(vehiculosFabrica.get_longitud()) + "\n";
        vAux=vehiculosFabrica.desencolar();
        cout<<vAux.verVehiculo();
        colaAux.encolar(vAux);
    }
    while ((!colaAux.es_vacia()) && (colaAux.get_longitud() > 0 )){
        cout<<"longitud  = "+to_string(colaAux.get_longitud()) + "\n";
        vAux=colaAux.desencolar();
        vehiculosFabrica.encolar(vAux);
    }
}

Gestor::~Gestor()
{
    //dtor
}
