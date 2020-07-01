#include <iostream>
#include <stdlib.h>
#include "rlutil.h"
#include <time.h>

#define CANT_D 5      //declaro el tamaño del vector dados como constante
#define GEN_SERVIDA 50000 //le doy un valor en puntos a la Generala Servida

using namespace rlutil;
using namespace std;

int dados[CANT_D] = {}; //crea el vector de los dados como variable global para poder modificarlo desde cada funcion
int marcaRecord = 0;
int rondaRecord = 0;
string jugadorRecord ="";

#include "funGraficas.h"
#include "record.h"
#include "jugarSolo.h"
#include "jugarVersus.h"



int main()
{
    setBackgroundColor(RED);
    cls();
    setColor(rlutil::LIGHTGREEN);
    hidecursor();

    char opcion;

    cout << "   Hola (n_n) BIENVENID@ a GENERALA! \n"<<endl;

    //creamos el menu principal del juego
    while(1){
        srand(time(NULL));//cada vez que ingresa al menu se reinicia el patron de aleatoriedad con el tiempo

        dibujarMenu(); //se dibuja el menu en pantalla
        cin>>opcion;
        cls();

        switch(opcion){
            case '1': jugarSolo();
                        break;

            case '2': jugarVersus();
                        break;

            case '3': mostrarRecord();
                        break;

            default: break;
        }
        cls();
    }
    return 0;
}


