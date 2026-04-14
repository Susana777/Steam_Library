#include "aplicacion.h"
#include <iostream>
#include <string>

using namespace std;

//Constructores
Aplicacion::Aplicacion()    //Vacio
{
    nombre = "game404";
    precio = 0;
    tamanio =  0;
    requisitos = "N/A";
    desarrolladora = "Steam";
    fecha_lanzamiento = "00/00/0000";
}
//Lleno
Aplicacion::Aplicacion(string nombre, float precio, float tamanio, string requisitos, string desarrolladora, string fecha){
    this->nombre = nombre;
    this->precio = precio;
    this->tamanio = tamanio;
    this->requisitos = requisitos;
    this->desarrolladora = desarrolladora;
    this->fecha_lanzamiento = fecha;
}
//Destructor
Aplicacion::~Aplicacion()
{

}
//Getters y setters
string Aplicacion::getNombre(void){
    return nombre;
}
void Aplicacion::setNombre(string nombre){
    this->nombre = nombre;
}
float Aplicacion::getPrecio(void){
    return precio;
}
void Aplicacion::setPrecio(float precio){
    this->precio = precio;
}
float Aplicacion::getTamanio(void){
    return tamanio;
}
void Aplicacion::setTamanio(float tamanio){
    this->tamanio = tamanio;
}
string Aplicacion::getRequisitos(void){
    return requisitos;
}
void Aplicacion::setRequisitos(string requisitos){
    this->requisitos = requisitos;
}
string Aplicacion::getDesarrolladora(void){
    return desarrolladora;
}
void Aplicacion::setDesarrolladora(string desarrolladora){
    this->desarrolladora = desarrolladora;
}
string Aplicacion::getFecha(void){
    return fecha_lanzamiento;
}
void Aplicacion::setFecha(string fecha){
    this->fecha_lanzamiento = fecha;
}
//Métodos
void Aplicacion::ASCII() const{
cout<<"        _____\n";
cout<<"    .-,;='';_),-.\n";
cout<<"     /_/(),()/_/\n";
cout<<"       (,___,)\n";
cout<<"      ,-/`~`\-,___\n";
cout<<"     / /).:.('--._)\n";
cout<<"    {_[ (_,_)\n";
cout<<"        | Y |\n";
cout<<"       /  |  \\n\n";
}
