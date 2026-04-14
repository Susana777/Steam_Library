#include "juego.h"
#include <iostream>
#include <string>
#include "aplicacion.h"

using namespace std;

//Constructores
Juego::Juego() : Aplicacion()
{
    genero = "sim";
    horas_jugadas = 0;
    logros = 0;
    logros_obtenidos = 0;
}
Juego::Juego(string nombre, float precio, float tamanio, string requisitos, string desarrolladora, string fecha_lanzamiento,
             string genero, int horas_jugadas, int logros, int logros_obtenidos) : Aplicacion(nombre, precio, tamanio, requisitos, desarrolladora, fecha_lanzamiento){
    this->genero = genero;
    this->horas_jugadas = horas_jugadas;
    this->logros = logros;
    this->logros_obtenidos = logros_obtenidos;
}
//Destructor
Juego::~Juego()
{
    //dtor
}
//Getters y setters
string Juego::getGenero(void){
    return genero;
}
void Juego::setGenero(string genero){
    this->genero = genero;
}
int Juego::getHoras_jugadas(void){
    return horas_jugadas;
}
void Juego::setHoras_jugadas(int horas_jugadas){
    this->horas_jugadas = horas_jugadas;
}
int Juego::getLogros(void){
    return logros;
}
void Juego::setLogros(int logros){
    this->logros = logros;
}
int Juego::getLogros_obtenidos(void){
    return logros_obtenidos;
}
void Juego::setLogros_obtenidos(int logros_obtenidos){
    this->logros_obtenidos = logros_obtenidos;
}
//Metodos
void Juego::ASCII() const{
    cout<<"Hola papu";
}
//Sobrecarga de operadores
//Jugar con parámetro de horas, Actualizar logros en base a cada 4 horas
Juego Juego::operator+(const int &var){
    Juego aux = *this;   //Copia todo lo del objeto
    aux.horas_jugadas = this->horas_jugadas + var;
    aux.logros_obtenidos = aux.horas_jugadas/4;
    //En caso de que la medida anterior de logros se pase:
    if(logros_obtenidos>logros){
        logros_obtenidos = logros;
    } else{
        cout<<"\nHas obtenido "<<aux.logros_obtenidos - this->logros_obtenidos<<" nuevos logros!"<<endl;
    }
    return aux;
}
//""
Juego Juego::operator+=(const int &var){
    this->horas_jugadas += var;
    //Para checar la diferencia
    int diferencia = this->logros_obtenidos;
    //Y ya
    this->logros_obtenidos += this->horas_jugadas/4;
    if(this->logros_obtenidos > this->logros){
        this->logros_obtenidos = this->logros;
    } else {
        cout<<"\nHas obtenido "<<this->logros_obtenidos - diferencia<<" nuevos logros!"<<endl;
    }
    return *this;
}
//Mostrar cuanto tiempo tienes jugado en anios, meses, semanas, dias, minutos o segundos
void Juego::operator%(const string &var){
    float tiempo=0;
    if(var == "anios"){
            tiempo = horas_jugadas/8760;
            cout<<"El tiempo que tienes jugado en anios es de "<<tiempo<<" anios."<<endl;
    } else if(var == "meses"){
            tiempo = horas_jugadas/720;
            cout<<"El tiempo que tienes jugado en meses es de "<<tiempo<<" meses."<<endl;
    } else if(var == "semanas"){
            tiempo = horas_jugadas/168;
            cout<<"El tiempo que tienes jugado en semanas es de "<<tiempo<<" semanas."<<endl;
    } else if(var == "dias"){
            tiempo = horas_jugadas/24;
            cout<<"El tiempo que tienes jugado en dias es de "<<tiempo<<" dias."<<endl;
    } else if(var == "horas"){
            cout<<"El tiempo que tienes jugadas en horas es de "<<horas_jugadas<<" horas."<<endl;
    } else if(var == "minutos"){
            tiempo = horas_jugadas*60;
            cout<<"El tiempo que tienes jugado en minutos es de "<<tiempo<<" minutos."<<endl;
    } else if(var == "segundos"){
            tiempo = horas_jugadas*3600;
            cout<<"El tiempo que tienes jugado en segundos es de "<<tiempo<<" segundos."<<endl;
    } else{
        cout<<"Opcion invalida."<<endl;
    }
}
//Mostrar si 2 juegos son del mismo genero
bool Juego::operator==(Juego const &var) const{
    return (genero == var.genero);
}
//Mostar entre 2 juegos cuál tiene más horas
void Juego::operator<(Juego const &var) const{
    if(horas_jugadas>var.horas_jugadas){
        cout<<endl<<nombre<<" tiene mas horas de juego ("<<horas_jugadas<<") que "<<var.nombre<<" ("<<var.horas_jugadas<<")."<<endl;
    } else if(horas_jugadas==var.horas_jugadas){
        cout<<"\nAmbos juegos tienen las mismas horas de juego ("<<horas_jugadas<<")."<<endl;
    } else {
        cout<<endl<<var.nombre<<" tiene más horas de juego ("<<var.horas_jugadas<<") que "<<nombre<<" ("<<horas_jugadas<<")."<<endl;
    }
}
//Mostrar entre 2 juegos cuál está más cerca que platinarse y jugarlo
void Juego::operator!(){
    if(logros_obtenidos == logros){
        cout<<"\n\nESTE JUEGO ESTA PLATINADO!!!"<<endl;
        string str = " .-=========-.\n";
        str+=" \\'-=======-'/\n";
        str+=" _|   .=.   |_\n";
        str+="((|  {{1}}  |))\n";
        str+=" \\|   /|\\   |/\n";
        str+="  \\__ '`' __/\n";
        str+="    _`) (`_\n";
        str+="  _/_______\\_\n";
        str+=" /___________\\\n";
        cout<<str<<endl;
    } else {
        cout<<"\n\nEste juego aun no esta platinado, te faltan "<<((logros*4)-horas_jugadas)<<" horas para platinarlo."<<endl;
    }
}
 // -nombre,  precio,-tamanio,  r-equisitos,  -desarrolladora, -fecha, genero, -horas_jugadas,  logros, -logros_obtenidos
ostream& operator<<(ostream &salida, const Juego &var){
    salida<<"Nombre: "<<var.nombre<<"\nGenero: "<<var.genero<<"\nHoras jugadas: "<<var.horas_jugadas<<"\nLogros: "
    <<var.logros<<"\nLogros obtenidos: "<<var.logros_obtenidos<<"\n\n\nPrecio: $"<<var.precio<<"\nTamanio: "<<var.tamanio<<" GB"
    <<"\nRequisitos: Gama "<<var.requisitos<<"\nDesarrolladora: "<<var.desarrolladora<<"\nFecha de lanzamiento: "<<var.fecha_lanzamiento;
    return salida;
}
istream& operator>>(istream &entrada, Juego &var){
    cin.ignore();
    cout<<"Ingresa el nombre del juego: ";
    getline(cin, var.nombre);
    cout<<"Ingresa el precio del juego: ";
    cin>>var.precio;
    cout<<"Ingresa el tamanio del juego: ";
    cin>>var.tamanio;
    cout<<"Ingresa el nivel de gama que requiere el juego: ";
    cin>>var.requisitos;
    cin.ignore();
    cout<<"Ingresa el grupo desarrollador del videojuego: ";
    getline(cin, var.desarrolladora);
    cout<<"Ingresa la fecha en formato 00/00/000: ";
    cin>>var.fecha_lanzamiento;
    cout<<"Ingresa el genero del juego: ";
    cin.ignore();
    getline(cin, var.genero);
    var.horas_jugadas=0;
    cout<<"Ingresa la cantidad de logros que tiene el juego: ";
    cin>>var.logros;
    var.logros_obtenidos=0;
    return entrada;
}
