#ifndef Asociaciones_h
#define Asociaciones_h

#include <iostream>
using namespace std;

#include "Clientes.h"

class Asociaciones : public Clientes
{
public:
    Asociaciones();
    Asociaciones(int id, string nombre, string telefono, int prendas, string direccion);
    void setDireccion(string _direccion) { direccion = _direccion; };
    string getDireccion() { return direccion; };

    void mostrar();

private:
    string direccion;
};

Asociaciones::Asociaciones() : Clientes()
{
  direccion = "";
}

Asociaciones::Asociaciones(int _id, string _nombre, string _telefono, int _prendas, string _direccion) : Clientes(_id, _nombre, _telefono, _prendas)
{
  direccion = _direccion;
}

void Asociaciones::mostrar()
{
    Clientes::mostrar();
    cout << "Dirección: " << direccion << endl;
}

#endif /* Asociaciones_h */