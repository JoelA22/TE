#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "Prendas.h"
#include "Asociaciones.h"

Prendas *listaPrendas[100];
Clientes *listaClientes[100];
int cantPrendas;
int cantClientes;
Clientes *sesionCliente;
int idCarrito[10]; int contad = 0;

void inicializarObjetos() {
  string tipo, genero, talla, type;
  int id, disponibilidad;
  
  ifstream archivoPrendas;
    archivoPrendas.open("archivoPrendas.txt");
    cantPrendas = 0;
    while(archivoPrendas>>id>>tipo>>genero>>talla>>disponibilidad){
      listaPrendas[cantPrendas] = new Prendas(id,tipo,genero,talla,disponibilidad);
      cantPrendas++;
    }
    archivoPrendas.close();
  
  string nombre, telefono, dir;
  int id_clientes, num_prendas;
  
  ifstream archivoClientes;
    archivoClientes.open("archivoClientes.txt");
    cantClientes = 0;
    while(archivoClientes>>type){
      if(type == "c"){
        archivoClientes>>id_clientes>>nombre>>telefono>>num_prendas;
        listaClientes[cantClientes] = new Clientes(id_clientes,nombre,telefono,num_prendas);
        cantClientes++;
      }
      else if(type == "a"){
        archivoClientes>>id_clientes>>nombre>>telefono>>num_prendas>>dir;
        listaClientes[cantClientes] = new Asociaciones(id_clientes,nombre,telefono,num_prendas,dir);
        cantClientes++;
      }
    }
    archivoClientes.close();
}

void filtro(){
  string gen, tipo, talla;
  cout << "¿Por que género desea filtrar?" << "\nHombre, Mujer, Niño, Niña, Bebe" << endl;
  cin >> gen;
  cout << "¿Por que tipo de prenda desea filtrar?" << "\nPlayera, Camisa, Pantalon, Zapatos, Chaqueta, Vestido, Falda, Short" << endl;
  cin >> tipo;
  if (tipo=="Zapato"){
    cout << "¿Por que talla desea filtrar?" << "\n15, 24" << endl;
    cin >> talla;
  }
  else{
    cout << "¿Por que talla desea filtrar?" << "\nS, M, L" << endl;
    cin >> talla;
  }

  for(int i; i < cantPrendas; i++){
    if(gen == listaPrendas[i]->getGenero() && tipo == listaPrendas[i]->getTipo() && talla == listaPrendas[i]->getTalla()){
      listaPrendas[i]->mostrar();
    }
  }   
}

void iniciarSesion(int &cont) {
  string nom, tel;
  cout << "Iniciar sesión" << endl;
  cout << "Nombre: "; cin >> nom;
  cout << "Teléfono: "; cin >> tel;
  for(int i = 0; i < cantClientes; i++){
    if(nom == listaClientes[i]->getNombre() && tel == listaClientes[i]->getTelefono()) {
      cout << "\nBienvenid@ " << nom << endl;
      cont++;
      sesionCliente = listaClientes[i];
    }
  }
}

void agregarUsuario() {
  string nom, tel, op, dir;
  cout << "¿Desea crear una cuenta de Asociación o de Cliente? (a/c)" << endl;
  cin >> op;
  cout<<"Ingresar nombre del nuevo usuario: "; cin>>nom;
  cout<<"Ingresar telefono del nuevo usuario: "; cin>>tel;
  if (op == "a"){
    cout<<"Ingresar dirección de la asociación: "; cin>>dir;
    listaClientes[cantClientes] = new Asociaciones(cantClientes+1,nom,tel,0,dir);
    cantClientes++;
  } else if (op == "c") {
    listaClientes[cantClientes] = new Clientes(cantClientes+1,nom,tel,0);
    cantClientes++;
  }
}

void inicio(int &cont) {
  int opcion;
  cout<<"1. Inicio sesión"<<endl;
  cout<<"2. Registrate"<<endl;
  cin>>opcion;

  if (opcion == 1) {
    iniciarSesion(cont);
  } else if (opcion == 2) {
    agregarUsuario();
  } else {
    cout<<"Este número no es válido";
  }
}

void verPrendas() {
  int cont;
  cout<<"PRENDAS EXISTENTES"<<endl;
  for(int i=0;i<cantPrendas;i++) {
    if (listaPrendas[i]->getDisponibilidad() == 1) {
      listaPrendas[i]->mostrar();
      cout<<endl;
    }
  }
}

void agregarCarrito(){
  for (int i=0; i<10; i++) {
    idCarrito[i] = 0;
  }
  int idProducto, idCliente, contadorAux = 0;
  string validar;
  Prendas *aux[100]; int conta=0;
  int maxACarrito = 10;
  int maxCarrito = 10;

  if (typeid(*sesionCliente)==typeid(Asociaciones)) {
    for(int i = 0; i < maxACarrito; i++){
      cout << "Ingresa el ID del producto a comprar: ";
      cin >> idProducto;
      idCarrito[i] = idProducto;
      cout << "Quieres comprar un nuevo producto? (S/N): " << endl;
      cin >> validar;
      contad++;

      if(validar == "N" || contad >= 10){
        break;
      }
    }

    if (contad == 10 && validar == "S") {
      cout<<"Ya llegó al limite de compras"<<endl;
    }
    
    for (int i = 0; i < contad; i++) {
      for (int j = 0; j < cantPrendas; j++) {
        if (idCarrito[i] == listaPrendas[j]->getID()) {
          listaPrendas[j]->setDisponibilidad(0);
        }
      }
    }
  }
  else if(typeid(*sesionCliente)==typeid(Clientes)){
    for(int i = 0; i < maxCarrito; i++){
      cout << "Ingresa el ID del producto a comprar: ";
      cin >> idProducto;
      idCarrito[i] = idProducto;
      cout << "Quieres comprar un nuevo producto? (S/N): " << endl;
      cin >> validar;
      contad++;

      if(validar == "N" || contad >= 4){
        break;
      }
    }

    if (contad == 4 && validar == "S") {
      cout<<"Ya llegó al limite de compras"<<endl;
    }
    
    for (int i = 0; i < contad; i++) {
      for (int j = 0; j < cantPrendas; j++) {
        if (idCarrito[i] == listaPrendas[j]->getID()) {
          listaPrendas[j]->setDisponibilidad(0);
        }
      }
    } 
  }
  
}

void finalizarCompra() {
  ofstream prendas("archivoPrendas.txt"); 
  vector<string> lineas;
  
  for (int i =0; i < contad; i++) {
    for (int j=0; j < cantPrendas;j++) {
      
      
      if (idCarrito[i] == listaPrendas[j]->getID()) {
          listaPrendas[j]->mostrar();
          cout<<endl;
        }
    }
  }
  for (int i=0; i<cantPrendas;i++){
    prendas << listaPrendas[i]->getID() << " " << listaPrendas[i]->getTipo() << " " << listaPrendas[i]->getGenero() << " " << listaPrendas[i]->getTalla() << " "<< listaPrendas[i]->getDisponibilidad() << " " << endl;
  }
  prendas.close();

  sesionCliente->setPrendas(contad);
  
  cout << "Estos son los articulos seleccionados, su compra se ha procesado" << endl;

  
}

int menu() {
  int opcion;
  cout<<"1. Ver prendas"<<endl;
  cout<<"2. Agregar prendas al carrito"<<endl;
  cout<<"3. Finalizar compra"<<endl;
  cout<<"4. Cerrar sesión"<<endl;

  cin>>opcion;
  
  if (opcion == 1) {
    verPrendas();
  } else if (opcion == 2) {
    agregarCarrito();
  } else if (opcion == 3) {
    finalizarCompra();
  } else if (opcion == 4) {
    cout<<"Gracias, haz cerrado tu sesión.";
  } else {
    cout<<"Este número no es válido";
  }
  return opcion;
}

int main() {
  int opcion = 0, cont = 0;
  
  inicializarObjetos();

  while (cont != 1) {
    inicio(cont);
  }

  if (cont == 0) {
      cout<<"Opción invalida";
  } else {
    while(opcion != 4) {
      opcion = menu();
    }
  }
}