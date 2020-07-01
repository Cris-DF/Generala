#ifndef JUGARVERSUS_H_INCLUDED
#define JUGARVERSUS_H_INCLUDED

void ingresarNombres(int cant, string nombres[]){
    for(int i=0;i<cant;i++){
        cout<<"Nombre jugador "<<i+1<<" ";
        cin>>nombres[i];
    }
}

int jugarRondasVersus(int cantRondas,int cantJugadores,string nombre[],int puntos[]){
    int ronda=0;
    bool jugar=true;

    while(ronda<cantRondas && jugar){  //ciclo que juega todas las rondas
        ronda++;

        for(int j=0;j<cantJugadores;j++){ //En el for se juega la ronda de cada jugador 'j'

            cls();
            dibujaCabeceraRonda(nombre[j],ronda,puntos[j]); //imprime en la cabecera los datos de la ronda

            puntos[j] += jugarRonda(); //jugarRonda devuelve los puntos e imprime los lanzamientos de la ronda en pantalla

            locate(10,18);
            cout<<"Presione una tecla para continuar"<<endl;
            locate(10,22);
            anykey();


            if(j+1<cantJugadores){
                cout<<"EL PROXIMO TURNO ES DE "<<nombre[j+1];
            }

        }

        //si No se jugo la ultima ronda: se dibuja el cartel con el resumen de la ronda
        if(ronda<cantRondas){
                dibujaCartelRonda(ronda,cantJugadores,nombre,puntos);
                locate(1,1);
                cout<<"Escape para finalizar";
                if(getkey()==KEY_ESCAPE){
                    jugar = false;
                }
                cout<<"EL PROXIMO TURNO ES DE "<<nombre[0];
        }

        //si alguno de los jugadores tuvo puntaje de Generala Servida se deja de jugar en esta ronda
        for(int j=0;j<cantJugadores;j++){
            if(puntos[j]==GEN_SERVIDA){
                jugar = false;;
            }
        }


    }

    cls();
    return ronda;
}

bool encontrarGanador(int cantJ, int puntos[], int *ganador ){
    int puntosGanador = 0;
    bool empate;

    for(int i=0;i<cantJ;i++){
        if(puntos[i]>puntosGanador){
            *ganador = i;
            puntosGanador = puntos[i];
            empate = false;
        }
        else if(puntos[i]==puntosGanador){
            empate = true;

        }
    }
    return empate;
}


void jugarVersus(){
    int cantJugadores = 2;
    int cantRondas = 10;
    string nombre[cantJugadores];
    string nombreGanador="";
    int ronda = 0;
    int puntos[cantJugadores] = {};
    int jGanador;
    bool empate;
    bool esRecord = false;


    cout<<"\t Genial! para empezar la partida versus ingresa el nombre de los jugadores"<<endl;
    ingresarNombres(cantJugadores,nombre);

    cls();
    cout<<"BIENVENID@S"<<endl;
    cout<<endl<<"EL PRIMER TURNO ES DE "<<nombre[0]<<endl;
    cout<<endl<<"PRESIONE CUALQUIER TECLA PARA EMPEZAR A JUGAR"<<endl;
    anykey();


    //juega las rondas y devuelve el numero de ronda con el que finalizo
    ronda = jugarRondasVersus(cantRondas,cantJugadores,nombre,puntos);

    //devuelve true si hubo empate y modifica jGanador con el indice del ganador
    empate = encontrarGanador(cantJugadores,puntos,&jGanador);

    if(empate){
        nombreGanador=" -Fue un empate-";
    }
    else{
        nombreGanador=nombre[jGanador];
    }

    esRecord = registrarPuntos(ronda,nombreGanador,puntos[jGanador]);

    dibujaCartelRonda(ronda,cantJugadores,nombre,puntos);

    imprimirFInDelJuego(empate,esRecord,nombreGanador,puntos[jGanador]);

    anykey();
    cls();
}

#endif // JUGARVERSUS_H_INCLUDED
