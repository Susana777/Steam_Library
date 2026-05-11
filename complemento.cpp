#include "complemento.h"
#include "aplicacion.h"
#include <iostream>
#include <string>

using namespace std;

//Constructores
Complemento::Complemento() : Aplicacion()
{
    tipo = "extra";
    juego_origen = "game404";
}
Complemento::Complemento(string nombre, float precio, float tamanio, string requisitos, string desarrolladora, string fecha_lanzamiento,
                         string tipo, string juego_origen) : Aplicacion(nombre, precio, tamanio, requisitos, desarrolladora, fecha_lanzamiento){
    this->tipo = tipo;
    this->juego_origen = juego_origen;
}
//Destructor
Complemento::~Complemento()
{
    //dtor
}
//Getters y setters
string Complemento::getTipo(void){
    return tipo;
}
void Complemento::setTipo(string tipo){
    this->tipo = tipo;
}
string Complemento::getJuego_origen(void){
    return juego_origen;
}
void Complemento::setJuego_origen(string juego_origen){
    this->juego_origen = juego_origen;
}
//Metodos
void Complemento::ASCII () const{
    cout<<" /$$$$$$$  /$$        /$$$$$$\n";
    cout<<"| $$__  $$| $$       /$$__  $$\n";
    cout<<"| $$  \\ $$| $$      | $$  \\__/\n";
    cout<<"| $$  | $$| $$      | $$\n";
    cout<<"| $$  | $$| $$      | $$\n";
    cout<<"| $$  | $$| $$      | $$    $$\n";
    cout<<"| $$$$$$$/| $$$$$$$$|  $$$$$$/\n";
    cout<<"|_______/ |________/ \\______/\n";

}

istream& operator>>(istream& entrada, Complemento& var){
    cin.ignore();
    cout<<"Ingresa el nombre del complemento: ";
    getline(cin, var.nombre);
    cout<<"Ingresa el precio del complemento: ";
    cin>>var.precio;
    cout<<"Ingresa el tamanio del complemento: ";
    cin>>var.tamanio;
    cout<<"Ingresa el nivel de gama que requiere el complemento: ";
    cin>>var.requisitos;
    cin.ignore();
    cout<<"Ingresa el grupo desarrollador del complemento: ";
    getline(cin, var.desarrolladora);
    cout<<"Ingresa la fecha en formato 00/00/000: ";
    cin>>var.fecha_lanzamiento;
    cin.ignore();
    cout<<"Ingresa el tipo de complemento(expansion/cosmetico): ";
    cin>>var.tipo;
    cout<<"Ingresa el juego origen: ";
    cin>>var.juego_origen;

    return entrada;
}
