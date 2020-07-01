#ifndef FUNCALCPUNTOS_H_INCLUDED
#define FUNCALCPUNTOS_H_INCLUDED

///contamos las veces que aparece un numero en el vector de dados
int apariciones(int n){
    int apariciones=0;
    for(int j=0;j<CANT_D;j++){ //recorremos cada indice para contar cuantas veces salio el nro "i"
        if(dados[j]==n){
            apariciones++;
        }
    }
    return apariciones;
}


///funcion para contar los puntos de los juegos del 1 al 6 y devolver la maxima puntuacion posible
int juegoDeX(int puntos){

        for(int i=1;i<=6;i++){ //iteramos los numeros del 1 al 6
            if(i*apariciones(i) > puntos){  //si el puntaje de apariciones de valor "i" es mayor al puntaje actual
                puntos = i*apariciones(i);  //se reemplaza el valor de los puntos
            }
        }
    return puntos;
}


bool hayEscalera(){  //verdadero si las combinaciones de los dados pueden formar 1-2-3-4-5 o 2-3-4-5-6
    bool escalera = false;
    bool seisYuno = true;
    bool distintos = true;

    for(int i=1;i<=6;i++){ //iteramos los numeros del 1 al 6
        if(apariciones(i) > 1){  //si las aparicion de algun numero en los dados es mayor a 1
                distintos=false;
        }
        if((i==6 || i==1) && apariciones(i)>0){ //si el salio el 6 o el 1
            seisYuno = !seisYuno;    //se niega la variable de tal forma que si aparecieron ambos(o ninguno) esta vuelva a su valor original
        }
    }

    escalera = (distintos && !seisYuno);    // es Escalera si todos los numeros son distintos y 6-1 no aparecen al mismo tiempo

    return escalera;
}


bool hayFull(){ //verdadero si un numero aparece en los dados 3 veces Y otro aparece 2

    bool doble = false;
    bool triple = false;
    bool full = false;

    for(int i=1;i<=6;i++){
        if(apariciones(i) == 2){
            doble = true;;
        }
        else if(apariciones(i) == 3){
            triple = true;
        }
    }
    full = (triple&&doble); //si hay un triple Y un doble full es verdadero

    return full;
}


bool hayPoker(){    //verdadero si un numero aparece 4 veces en los dados
    bool poker = false;

    for(int i=1;i<=6;i++){
        if(apariciones(i) == 4){
            poker = true;;
        }
    }
    return poker;
}


bool hayGenerala(){ //verdadero si un numero aparece 5 veces en los dados
    bool generala = false;

    for(int i=1;i<=6;i++){
        if(apariciones(i) == 5){
            generala = true;;
        }
    }
    return generala;
}


///calcula un puntaje de acuerdo a la jugada de dados[]
int calcularPuntos(string *mensaje){
    int puntosAct = 0;
    string jugada;

    if(hayEscalera()){
        puntosAct = 25;
        jugada = "Escalera";
    }
    else if(hayFull()){
        puntosAct = 30;
        jugada = "Full";
    }
    else if(hayPoker()){
        puntosAct = 40;
        jugada = "Poker";
    }
    else if(hayGenerala()){
        puntosAct = 50;
        jugada = "Generala";
    }
    else{
        puntosAct = juegoDeX(puntosAct);
        jugada = "Juego";
    }

    *mensaje = jugada;
    return puntosAct;
}

#endif // FUNCALCPUNTOS_H_INCLUDED
