#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "funCalcPuntos.h"



///Esta funcion devuelve un valor aleatorio para un dado
int lanzaDado(){
    int tiro;
    tiro = rand() % 6 + 1;
    return tiro;
}


///Se hace el lanzamiento de todos los dados
int lanzamientoCompleto(){

    for(int i=0;i<CANT_D;i++){
        dados[i] = lanzaDado();
    }
    dibujarDadosLanzamiento(0);

    return 1;
}


///Hace un lanzamiento selectivo, devuelve true si se eligio seguir lanzando
bool seguirLanzando(int tiro){

    char opcion;
    int nDados;
    int dado;
    bool seguir; //variable para indicar que se utilizo el lanzamiento

    locate(2,2);
    cout<<"Desea seguir lanzando? (S/N) "<<endl;
    cin>>opcion;

    if(opcion=='S'||opcion=='s'){
        cout<<"cuantos dados?(hasta 5)";
        cin>>nDados;

        for(int i=0;i<nDados;i++){  //se lanza la cantidad de dados elegida
            cout<<"Cual dado lanza?(del 1 al 5)";
            cin>>dado;
            if(dado<=CANT_D){
                dados[dado-1] = lanzaDado();
            }
        }
        dibujarDadosLanzamiento(tiro);
        seguir = true;
    }
    else{
        seguir = false;
    }

    return seguir;
}


///Funcion que se ocupa de realizar una ronda completa
int jugarRonda(){
    int puntos = 0;   //se acumularan los puntos de la ronda
    int tirosT = 3;  //tiros totales de cada ronda
    int tiroActual = 0;
    string jugada = "";
    bool seguirRonda = true;
    bool gServida = false;


    dibujarIzqPantalla(); //dibuja el fondo del lado izquierdo

    tiroActual += lanzamientoCompleto(); //se ejecuta el primer Lanzamiento y se acumula el 1 que retorna

    if(calcularPuntos(&jugada)==50){  //si luego del primer lanzamiento tenemos 50 puntos hubo generala servida
        gServida = true;
        seguirRonda = false;
        jugada = "GENERALA SERVIDA!!!";
        puntos = GEN_SERVIDA;
    }

    while(seguirRonda&&tiroActual<tirosT){           //mientras haya lanzamientos y se deba seguir la ronda
        seguirRonda = seguirLanzando(tiroActual);    //llama a la funcion que hace los lanzamientos extras
        tiroActual++;
        dibujarIzqPantalla(); //para limpiar el lado izquierdo de la pantalla entre lanzamientos
    }


    if(!gServida){                          //si no hubo una generala servida
        puntos = calcularPuntos(&jugada);       //calcula los puntos
        locate(17,10);
        cout<<"PUNTAJE DE RONDA:"<<puntos<<endl;
    }

    locate(19,11);
    cout<<"Sacaste "+jugada<<endl;

    return puntos;
}


#endif // FUNCIONES_H_INCLUDED



