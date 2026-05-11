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
///////////////Validadores
float leerFloat(const string &mensaje){
    float valor;
    while(true){
        cout<<mensaje;
        cin>>valor;
        if(cin.fail()){
            cout<<"Valor invalido, error al guardar.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else {
            cin.ignore(1000, '\n');
            return valor;
        }
    }
}
string leerFecha(const string &mensaje){
    string _fecha;
    while(true){
        cout<<mensaje;
        getline(cin, _fecha);
        if(_fecha.length() > 10){
            cout<<"Formato invalido, ingresa denuevo porfavor.\n";
            cin.clear();
        } else {
            cin.clear();
            return _fecha;
        }
    }
}
istream& operator>>(istream& entrada, Complemento& var){
    cin.ignore(1000,'\n');
    cout<<"Ingresa el nombre del complemento: ";
    getline(cin, var.nombre);
    var.precio = leerFloat("Ingresa el precio del complemento: ");
    var.tamanio = leerFloat("Ingresa el tamanio del complemento: ");
    cout<<"Ingresa el nivel de gama que requiere el complemento: ";
    cin>>var.requisitos;
    cin.ignore(1000,'\n');
    cout<<"Ingresa el grupo desarrollador del complemento: ";
    getline(cin, var.desarrolladora);
    var.fecha_lanzamiento = leerFecha("Ingresa la fecha en formato 00/00/000: ");
    cout<<"Ingresa el tipo de complemento(expansion/cosmetico): ";
    getline(cin, var.tipo);
    cout<<"Ingresa el juego origen: ";
    getline(cin, var.juego_origen);
    return entrada;
}
