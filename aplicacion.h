#ifndef APLICACION_H
#define APLICACION_H
#include <string>

using namespace std;

class Aplicacion
{
    protected:
        string nombre;
        float precio;
        float tamanio;
        string requisitos;
        string desarrolladora;
        string fecha_lanzamiento;
    public:
        //Constructores
        Aplicacion();
        Aplicacion(string, float, float, string, string, string);
        //Destructor
        virtual ~Aplicacion();
        //Getters y setters
        string getNombre(void);
        void setNombre(string);
        float getPrecio(void);
        void setPrecio(float);
        float getTamanio(void);
        void setTamanio(float);
        string getRequisitos(void);
        void setRequisitos(string);
        string getDesarrolladora(void);
        void setDesarrolladora(string);
        string getFecha(void);
        void setFecha(string);
        //Polimorfismo
        virtual void ASCII() const;
};

#endif // APLICACION_H
