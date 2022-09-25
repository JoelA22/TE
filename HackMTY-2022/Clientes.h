#ifndef Clientes_h
#define Clientes_h

#include <iostream>
using namespace std;

class Clientes
{
public:
    Clientes();
    Clientes(int id, string nombre, string telefono, int prendas);
    void setID(int _id) { id = _id; };
    int getID() { return id; };
    void setNombre(string _nombre) { nombre = _nombre; };
    string getNombre() { return nombre; };
    void setTelefono(string _telefono) { telefono = _telefono; };
    string getTelefono() { return telefono; };
    void setPrendas(int _prendas) { prendas = _prendas; };
    int getPrendas() { return prendas; };

    virtual void mostrar();

protected:
    string nombre, telefono, type;
    int id, prendas;
};

Clientes::Clientes()
{
  id = 0;
  nombre = "";
  telefono = "";
  prendas = 0;
}

Clientes::Clientes(int _id, string _nombre, string _telefono, int _prendas)
{
  id = _id;
  nombre = _nombre;
  telefono = _telefono;
  prendas = _prendas;
}

void Clientes::mostrar()
{
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Prendas: " << prendas << endl;
}

#endif /* Clientes_h */