#ifndef COMPLEMENTO_H
#define COMPLEMENTO_H
#include "aplicacion.h"
#include <string>

using namespace std;

class Complemento : public Aplicacion
{
    //Atributos
    private:
        string tipo;
        string juego_origen;
    public:
        //Constructores
        Complemento();
        Complemento(string, float, float, string, string, string, string, string);
        //Destructor
        virtual ~Complemento();
        //Getters y setters
        string getTipo(void);
        void setTipo(string);
        string getJuego_origen(void);
        void setJuego_origen(string);
        //Metodos
        virtual void ASCII() const override;

        friend istream& operator>>(istream&, Complemento&);
        friend ostream& operator<<(ostream&, const Complemento&);
};

#endif // COMPLEMENTO_H
