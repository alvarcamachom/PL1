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
        Pedido(string m, string col, string prio);
        virtual ~Pedido();

        string modeloRand();
        string colorRand();
        string tipoRand();
        int zonaRand();

        string getModelo();
        string getTipo();
        string getColor();
        int getZona();
        int getConcesionario();

        string verPedido();


    protected:


    private:
        string modelo;
        string color;
        int concesionario;
        int zona;
        string tipo;

};

#endif // PEDIDO_H
