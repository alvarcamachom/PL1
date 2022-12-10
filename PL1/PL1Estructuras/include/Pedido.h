#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
using namespace std;


class Pedido
{
    public:
        Pedido();
        virtual ~Pedido();

        string modeloRand();
        string colorRand();
        string tipoRand();

        string getModelo();
        string getTipo();
        string getColor();
        string getZona();
        int getConcesionario();


    protected:


    private:
        string modelo;
        string color;
        int concesionario;
        string zona;
        string tipo;

};

#endif // PEDIDO_H
