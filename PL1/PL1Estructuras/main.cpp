#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>


using namespace std;

int main()
{
    srand(time(NULL));
    int opcion;
    bool bucle = true;
    int nv;
    int nv2;
    string error = "Opcion no valida\n";

    while (bucle){
        cout<<"Seleccione una opcion: \n1-Generar numero aleatorio de automóviles\n2-Generar numero determinado de automoviles\n3-Mostrar automoviles en fabrica\n4-Borrar automoviles en fabrica\n5-Salen un numero aleatorio de automóviles de la fabrica y llega a un almacén\n6-Salen un numero determinado de automoviles de la fabrica y llegan a un almacen\n7-Mostrar datos de los almacenes de zona y registro\n8-Realizar simulacion hasta terminar los automoviles disponibles\n0-Salir\n";
        cin>>opcion;
        if (opcion==0){
            bucle=false;
        }
        else if (opcion==1){
            //Generar un numero de automoviles aleatorio
        }
        else if(opcion==2){
            //Generar un numero dado de automoviles
            cout<<"Cuantos automoviles generamos?\n";
            cin>>nv;
        }
        else if(opcion==3){
            //Mostrar automoviles en la fabrica
            std::string letras [6] = {"a","b","c","d","e","f"};
            int x = rand()%7;
            cout<<x<<" es el numero random\n";
            cout<<letras[x];
        }
        else if(opcion==4){
            //Borrar automoviles
        }
        else if(opcion==5){
            //Sale un numero aleatorio de automoviles de la fabrica y llegan a almacen
        }
        else if(opcion==6){
            //Sale un numero dado de automoviles de la fabrica y llegan a almacen
            cout<<"Cuantos automoviles salen de la fabrica?";
            cin>>nv2;
        }
        else if(opcion==7){
            //Mostrar datos de los almacenes de la zona y registros
        }
        else if(opcion==8){
            //Simular hasta terminar automoviles
        }
        else{
            cout<<error;
        }
    }
    return 0;
}
