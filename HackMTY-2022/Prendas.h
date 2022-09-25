#ifndef Prendas_h
#define Prendas_h

#include <iostream>
using namespace std;

class Prendas
{
public:
    Prendas();
    Prendas(int id, string tipo, string genero, string talla, int disponibilidad);
    void setID(int _id) { id = _id; };
    int getID() { return id; };
    void setTipo(string _tipo) { tipo = _tipo; };
    string getTipo() { return tipo; };
    void setGenero(string _genero) { genero = _genero; };
    string getGenero() { return genero; };
    void setTalla(string _talla) { talla = _talla; };
    string getTalla() { return talla; };
    void setDisponibilidad(int _disponibilidad) { disponibilidad = _disponibilidad; };
    int getDisponibilidad() { return disponibilidad; };
    void mostrar();

private:
    string genero, tipo, talla;
    int id, disponibilidad;
};

Prendas::Prendas()
{
  id = 0;
  tipo = "";
  genero = "";
  talla = "";
  disponibilidad = 0;
}

Prendas::Prendas(int _id, string _tipo, string _genero, string _talla, int _disponibilidad)
{
  id = _id;
  tipo = _tipo;
  genero = _genero;
  talla = _talla;
  disponibilidad = _disponibilidad;
}

void Prendas::mostrar()
{
    cout << "ID: " << id << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Género: " << genero << endl;
    cout << "Talla: " << talla << endl;
}

#endif /* Prendas_h */