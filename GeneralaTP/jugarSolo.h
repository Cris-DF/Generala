#ifndef JUGARSOLO_H_INCLUDED
#define JUGARSOLO_H_INCLUDED

#include "funRonda.h"

void jugarSolo(){
    string nombre;
    int cantRondas = 10;
    int ronda = 0;
    int puntos = 0;
    bool esRecord = false;
    bool terminar=false;

    cout<<"\t Genial! para empezar la partida individual ingresa tu nombre de Jugador \nNombre:"<<endl;
    cin>>nombre;
    cls();
    cout<<"Bienvenid@ "<<nombre<<"\n Ahora presiona alguna tecla para lanzar los dados"<<endl;;
    anykey();
    cls();


    while(ronda<cantRondas && !terminar){  //juega todas las rondas
        ronda++;
        cls();
        dibujaCabeceraRonda(nombre,ronda,puntos);
        puntos += jugarRonda();
        locate(12,18);
        cout<<"Presione una tecla para continuar"<<endl;
        locate(12,19);
        cout<<"   O Escape para finalizar"<<endl;

        if(getkey()==KEY_ESCAPE || puntos==GEN_SERVIDA){
           terminar=true;
       }
    }

    esRecord = registrarPuntos(ronda,nombre,puntos);
    cls();

    imprimirFInDelJuego(ronda,nombre,puntos,esRecord);

    anykey();
    cls();
}


#endif // JUGARSOLO_H_INCLUDED
