#ifndef JUEGO_H
#define JUEGO_H
#include "aplicacion.h"
#include <iostream>
#include <string>

using namespace std;

class Juego : public Aplicacion
{
    //Atributos
    private:
        string genero;
        int horas_jugadas;
        int logros;
        int logros_obtenidos;
    public:
        //Constructores
        Juego();
        //Cargado
        Juego(string, float, float, string, string, string, string, int, int, int);
        //Destructor
        virtual ~Juego();
        //Getters y setters
        string getGenero(void);
        void setGenero(string);
        int getHoras_jugadas(void);
        void setHoras_jugadas(int);
        int getLogros(void);
        void setLogros(int);
        int getLogros_obtenidos(void);
        void setLogros_obtenidos(int);
        //Metodos
        virtual void ASCII() const override;
        //Sobrecarga de operadores
        Juego operator+(const int &);    //Jugar con parámetro de horas, Actualizar logros en base a cada 4 horas
        Juego operator+=(const int &);   //""
        void operator%(const string &);   //Mostrar cuanto tiempo tienes jugado en meses, semanas, dias, minutos o segundos
        bool operator==(Juego const &) const;  //Mostrar si 2 juegos son del mismo genero
        void operator<(Juego const &) const;   //Mostar entre 2 juegos cuál tiene más horas
        void operator!();                   //Muestra si un juego esta platinado o no
        friend ostream& operator<<(ostream &, const Juego &);
        friend istream& operator>>(istream &, Juego &);
};

#endif // JUEGO_H
