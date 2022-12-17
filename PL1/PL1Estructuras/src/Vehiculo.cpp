#include "Vehiculo.h"
#include "Gestor.h"
#include <string>
#include <cstddef>

using namespace std;

Vehiculo::Vehiculo()
{
    modelo = Vehiculo::modeloRand();
    color = Vehiculo::colorRand();
    bastidor = Vehiculo::generarBastidorRand();
    concesionario = 0;
}

Vehiculo::Vehiculo(string m, string c, string b, int con)
{
    modelo = m;
    color = c;
    bastidor = b;
    concesionario = con;
}

Vehiculo::Vehiculo(string m, string c)
{
    modelo = m;
    color = c;
    bastidor = Vehiculo::generarBastidorRand();
    concesionario = 0;
}

string Vehiculo::generarBastidorRand()
{
    string bastidor = "";
    string letras="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i<5; i++)  //generamos las 5 letras aleatorias
    {
        int r = rand()%26;
        bastidor+=letras[r];
    }
    int numeros = rand()%100 +100; //Generamos los 3 numeros aleatorios
    bastidor+=to_string(numeros); //Pasamos los numeros a string y los concatenamos

    return bastidor;
}

string Vehiculo::modeloRand()
{
    string modelos[5] = {"M1","M2","M3","M4","M5"};
    int s = rand()%5;
    string modelo = modelos[s]; //elegimos elemento aleatorio s de la lista
    return modelo;
}

string Vehiculo::colorRand()
{
    string colores[3] = {"C1","C2","C3"};
    int t = rand()%3;
    string color = colores[t];
    return color;
}

void Vehiculo::set_concesionario(int n)
{
    concesionario=n;
}

string Vehiculo::devolverModelo()
{
    return modelo;
}
string Vehiculo::devolverColor()
{
    return color;
}
string Vehiculo::devolverBastidor()
{
    return bastidor;
}
int Vehiculo::devolverConcesionario()
{
    return concesionario;
}

int Vehiculo::getZona()
{
    return zona;
}

void Vehiculo::setZona(int z)
{
    zona = z;
}

string Vehiculo::pedirTipo()
{
    bool bucle = true;
    while (bucle)
    {
        string tipo;
        cout<<"Tipo pedido: 'P', 'N'"<<endl;
        cin>>tipo;
        if(tipo=="P")
        {
            return "P";
            bucle=false;
        }
        else if(tipo=="N")
        {
            return "N";
            bucle=false;
        }
        else
        {
            cout<<"Debe elegir entre P(Prioritario) y N(No prioritario)"<<endl;
        }
    }
}

string Vehiculo::pedirModelo()
{
    bool bucle = true;
    while (bucle)
    {
        cout<<"Modelo: 1,2,3,4,5"<<endl;
        cin>>modelo;
        if(modelo=="1")
        {
            return "M1";
            bucle=false;
        }
        else if(modelo=="2")
        {
            return "M2";
            bucle=false;
        }
        else if(modelo=="3")
        {
            return "M3";
            bucle=false;
        }
        else if(modelo=="4")
        {
            return "M4";
            bucle=false;
        }
        else if (modelo=="5")
        {
            return "M5";
            bucle=false;
        }
        else
        {
            cout<<"Debe elegir del 1 al 5"<<endl;
        }
    }
}

string Vehiculo::pedirColor()
{
    bool bucle = true;
    while (bucle)
    {
        cout<<"Color: 1,2,3"<<endl;
        cin>>color;
        if(color=="1")
        {
            return "C1";
            bucle=false;
        }
        else if(color=="2")
        {
            return "C2";
            bucle=false;
        }
        else if(color=="3")
        {
            return "C3";
            bucle=false;
        }
        else
        {
            cout<<"Debe elegir del 1 al 3"<<endl;
        }
    }
}

string Vehiculo::pedirBastidor()
{
    string bast;
    bool bucle=true;
    while (bucle)
    {
        cout<<"Introduce el numero de bastidor"<<endl;
        cin>>bast;
        if (bast.length()==8)
        {
            return bast;
            bucle=false;
        }
        else
        {
            cout<<"El bastidor debe tener 8 caracteres"<<endl;
        }
    }
}
int Vehiculo::pedirConcesionario(int nc)
{
    int con;

    bool bucle=true;
    while (bucle)
    {
        cout<<"Introduce el numero de concesionario"<<endl;
        cin>>con;
        if ((0<con) && (con<=nc))
        {
            return con;
            bucle=false;
        }
        else
        {
            cout<<"El numero de concesionario debe estar entre 1 y "<<nc<<endl;
        }
    }
}
string Vehiculo::verVehiculo()
{
    return("Vehiculo: " + devolverModelo() + ", color: " + devolverColor() + ", bastidor: " + devolverBastidor() + ", concesionario: " + to_string(devolverConcesionario()) + "\n");
}

Vehiculo::~Vehiculo()
{
    //dtor
}
