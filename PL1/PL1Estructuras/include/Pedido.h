#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>
using namespace std;


class Pedido
{
    public:
        Pedido();
        Pedido(int nc);
        Pedido(string m, string col);
        virtual ~Pedido();

        string modeloRand();
        string colorRand();
        string tipoRand();
        string zonaRand();

        string getModelo();
        string getTipo();
        string getColor();
        string getZona();
        int getConcesionario();

        string verPedido();


    protected:


    private:
        string modelo;
        string color;
        int concesionario;
        string zona;
        string tipo;

};

#endif // PEDIDO_H
