#include <iostream>
#include <string>
#include <vector>
#include "aplicacion.h"
#include "juego.h"
#include "complemento.h"

#define ln "\n\n"

using namespace std;

//Const max
const int max_juegos = 100;

////Prototipos
int menu();



////Main
int main()
{
    //Variables
    int opcion;
    int cont = 0;
    int cont2 = 0;
    string busqueda1;
    string busqueda2;
    int index1 = -1;
    int index2 = -1;
    string formato;
    char confirmacion;
    int horas;

    //Vector Biblioteca de juegos
    vector<Juego> juegos(max_juegos);
    //Vector Bibliteca de completentos
    vector<Complemento> complementos(max_juegos);
    vector<Juego>* J = &juegos;     //Puntero de la bibliteca de complementos

    //Ciclo principal
    do{
        //Llamada a la funcion menu
        opcion = menu();
        //Verificador de opcion
        switch(opcion){
            //
            //
            //
            //1.-Agregar videojuego
            case 1:
                cout<<"---------------Agregar videojuego---------------"<<ln;
                if(cont < max_juegos){
                    cin >> juegos[cont];
                    cout<<"Juego agregado."<<ln;
                    cont++;
                    system("pause");
                } else {
                    cout<<"Biblioteca llena."<<ln;
                    system("pause");
                }
                break;
            //
            //
            //
            //2.-Mostrar biblioteca
            case 2:
                cout<<"---------------Mostrar biblioteca---------------"<<ln;
                //Checa que no este vacia la bibliteca
                if(J->empty()){
                    cout<<"La biblioteca esta vacia.";
                } else {
                    for(int i=0; i<cont; i++){
                        cout<<"---"<<juegos[i].getNombre()<<endl;
                    }
                }
                cout<<ln;

                cout<<"---------------Mostrar biblioteca de complementos---------------"<<ln;
                //Checa que no este vacia la bibliteca
                if(complementos.empty()){
                    cout<<"La biblioteca esta vacia.";
                } else {
                    for(int i=0; i<cont; i++){
                        cout<<"---"<<complementos[i].getNombre()<<endl;
                    }
                }
                cout<<ln;
                system("pause");
                break;
            //
            //
            //
            //3.-Buscar un videojuego
            case 3:
                cout<<"---------------Buscar un videojuego---------------"<<ln;
                cout<<"Escribe el nombre del juego que quieres buscar: ";
                cin.ignore();   //Buffer para limpiar porsi acaso
                getline(cin, busqueda1);
                cout<<endl;
                for(int i=0; i<cont; i++){      //Busca en el vector
                    if(busqueda1 == juegos[i].getNombre()){
                        index1 = i;
                        break;        //Si lo encuentra lo rompe el ciclo
                    }
                }
                if(index1 != -1){
                    cout<<juegos[index1];        //Usa el << para imprimir
                    !juegos[index1];
                } else {
                    cout<<"El juego no existe o lo escribiste mal.";
                }
                cout<<ln;
                system("pause");
                break;
            //
            //
            //
            //4.-Mostrar horas jugadas en un juego en un formato.
            case 4:
                cout<<"---------------Mostrar horas jugadas en un juego en un formato---------------"<<ln;
                cout<<"Escribe el nombre del juego que quieres conocer las horas: ";
                cin.ignore();   //Buffer para limpiar porsi acaso
                getline(cin, busqueda1);
                for(int i=0; i<cont; i++){      //Busca en el vector
                    if(busqueda1 == juegos[i].getNombre()){
                        index1 = i;
                        break;        //Si lo encuentra lo rompe el ciclo
                    }
                }
                if(index1 != -1){
                    cout<<"Se encontro el juego, que formato quieres?";
                    cout<<"\n(anios) (meses) (semanas) (dias) (horas) (minutos) (segundos)\n";
                    cout<<"Respuesta: ";
                    cin>>formato;
                    juegos[index1] % formato;
                } else {
                    cout<<"El juego no existe o lo escribiste mal.";
                }
                cout<<ln;
                system("pause");
                break;
            //
            //
            //
            //5.-Comparar videojuegos
            case 5:
                cout<<"---------------Comparar videojuegos---------------"<<ln;
                cout<<"Escribe el nombre del primer juego que quieres comparar: ";
                cin.ignore();   //Solo ocupa un cin.ignore porque el buffer ya esta limpio
                getline(cin, busqueda1);
                cout<<"Escribe el nombre del segundo juego que quieres comparar: ";
                getline(cin, busqueda2);
                //Primer busqueda
                for(int i=0; i<cont; i++){
                    if(busqueda1 == juegos[i].getNombre()){
                        index1 = i;
                        break;
                    }
                }
                //Segunda busqueda
                for(int i=0; i<cont; i++){
                    if(busqueda2 == juegos[i].getNombre()){
                        index2 = i;
                        break;
                    }
                }
                //Checamos que los index no esten en -1
                if(index1 != -1){ //Primer busqueda
                    if(index2 != -1){   //Si lo encuentra, entonces segunda busqueda
                        //Compara con el operador sobrecargado si son del mismo genero
                        if(juegos[index1]==juegos[index2]){
                            cout<<"\nSon del mismo genero.\n";
                        } else {
                            cout<<"\nNo son del mismo genero.\n";
                        }
                        //Compara con el operador sobrecargado cual tiene mas horas
                        juegos[index1]<juegos[index2];
                    } else {
                        cout<<"No se pudo encontrar el segundo juego.";
                    }
                } else {
                    cout<<"No se pudo encontrar el primer juego.";
                }
                cout<<ln;
                system("pause");
                break;

            //
            //
            //
            //6.-Jugar un videojuego
            case 6:
                if(J->empty()){      //Checa que no este vacia la bibliteca
                    cout<<"\nLa biblioteca esta vacia, skill issue.";
                } else {                    //Si no esta vacia entonces:
                    cout<<"---------------Jugar un videojuego---------------"<<ln;
                    cout<<"Cual juego quieres jugar?\n";
                    for(int i=0; i<cont; i++){              //Muestra toda la biblioteca porque me parece mas comodo
                        cout<<"---"<<juegos[i].getNombre()<<endl;
                    }
                    cout<<"Juego: ";
                    cin.ignore();       //Limpia el buffer
                    getline(cin, busqueda1);
                    for(int i=0; i<cont; i++){
                        if(juegos[i].getNombre() == busqueda1){
                            index1 = i;
                            break;
                        }
                    }
                    if(index1 != -1){
                        cout<<"\nCuantas horas quieres jugarlo?: ";
                        cin>>horas;
                        juegos[index1] += horas;
                    } else {
                        cout<<"No se encontro el juego o lo escribiste mal.";
                    }
                }
                cout<<ln;
                system("pause");
                break;

            //
            //
            //
            //7.-Eliminar videojuego de la biblioteca
            case 7:
                cout<<"---------------Eliminar videojuego---------------"<<ln;
                cout<<"Escribe el nombre del juego que quieres borrar: ";
                cin.ignore();   //Solo ocupa un cin.ignore porque el buffer ya esta limpio
                getline(cin, busqueda1);
                for(int i=0; i<cont; i++){
                    if(busqueda1 == juegos[i].getNombre()){
                        index1 = i;
                        break;
                    }
                }
                if(index1 != -1){
                    cout<<"Estas seguro de querer borrarlo? (s/n): ";
                    cin.ignore();
                    cin>>confirmacion;
                    if(confirmacion == 's'){
                        cout<<"El juego "<<juegos[index1].getNombre()<<" se ha eliminado.";
                    } else if(confirmacion == 'n') {
                        cout<<"Se cancelo el borrado del juego.";
                    } else {
                        cout<<"Respuesta invalida, se cancela la accion.";
                    }
                } else {
                    cout<<"El juego no existe o lo escribiste mal.";
                }
                cout<<ln;
                system("pause");
                break;
            case 8:
                cout<<"---------------Agregar complemento---------------"<<ln;
                    if(cont2 < max_juegos){
                        cin>>complementos[cont2];
                        cout<<"Complemento agregado."<<ln;
                        cont2++;
                        system("pause");
                    } else {
                        cout<<"Biblioteca llena."<<ln;
                        system("pause");
                    }
                break;
            //En caso de que la opcion ingresada sea invalida
            default:
                cout<<"Opcion invalida."<<endl;
                opcion = 1;
                system("pause");
                break;
        }
    } while (opcion!=0);
}

////Funciones
//Funcion menu
int menu(){
    system("cls");
    int opcion_menu = 0;
    //Agregar opcion de ver tiempo jugado en
    cout<<"---------------Menu---------------"<<endl;
    cout<<"1.-Agregar videojuego!."<<endl;      //  operator>>
    cout<<"2.-Mostrar biblioteca!."<<endl;      //  opetarors<<
    cout<<"3.-Buscar un videojuego!."<<endl;        //    operator!
    cout<<"4.-Mostrar horas jugadas en un juego en un formato."<<endl;  //operator%
    cout<<"5.-Comparar videojuegos."<<endl;      //  operator<   operator==
    cout<<"6.-Jugar un videojuego."<<endl;   //  operator+   operator ++
    cout<<"7.-Eliminar videojuego de la biblioteca!."<<endl;
    cout<<"8.-Agregar un complemento."<<endl;
    cout<<"Opcion: ";
    cin>>opcion_menu;
    system("cls");
    return opcion_menu;
}
