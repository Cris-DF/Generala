#ifndef FUNGRAFICAS_H_INCLUDED
#define FUNGRAFICAS_H_INCLUDED

///imprime el menu principal en la consola
void dibujarMenu(){
    locate(1,1);
    cout<< "\t \t-Seleccionemos la opcion de Juego:\n" << endl;
    cout << "\t \t  Un jugador <Ingresar 1>             "<<endl;
    cout << "\t  \t Dos jugadores <Ingresar 2>          "<<endl;
    cout << "\t  \t Ver Puntuacion mas alta <Ingresar 3>"<<endl;
}

///Esta funcion dibuja un dado utilizando su valor, su posicion/indice y el lanzamiento correspondiente
void dibujarDado(int valor,int indice,int lanz){
    int posX;
    int posY;
    string filas[3] = {};
    posX = (indice*12)+55;  //dependiendo cual es el dado lo vamos a dibujar en una posicion X distinta
    posY = (lanz*9)+4;     //dependiendo en que lanzamiento corresponde una posicion Y distinta

    //se coloca en la posicion del dado y dibuja un cuadrado con caracteres
    setBackgroundColor(WHITE);
    setColor(BLACK);

    for(int i=posY+1;i<posY+6;i++){
        locate(posX,i);
        cout<<"         ";
    }

    //segun el valor del dado se le asigna un valor a sus filas para dibujar
    switch(valor){
        case 1: filas[1]= "    @  ";
                break;
        case 2: filas[1]= "  @   @";
                break;
        case 3: filas[1]= " @  @  @";
                break;
        case 4: filas[0]= "  @   @";
                filas[2]= "  @   @";
                break;
        case 5: filas[0]= "  @   @";
                filas[1]= "    @  ";
                filas[2]= "  @   @";
                break;
        case 6: filas[0]= "  @   @";
                filas[1]= "  @   @";
                filas[2]= "  @   @";
                break;

    }

    //ahora dibuja las filas adentro del dado
    locate(posX,posY+2);
    cout<<filas[0];
    locate(posX,posY+3);
    cout<<filas[1];
    locate(posX,posY+4);
    cout<<filas[2];

    setColor(LIGHTGREEN);
    rlutil::setBackgroundColor(RED);

}

///En esta funcion se imprimen los datos de ronda,jugador, puntaje
void dibujaCabeceraRonda(string nombre,int ronda,int puntos){

    locate(56,1);
    cout<<"Turno de "<<nombre<<" |  Ronda "<<ronda<<" | Puntaje Total "<<puntos<<endl;

}

///En esta funcion dibujaremos el lanzamiento actual y el valor actual de los dados en el lugar correspondiente al turno
void dibujarDadosLanzamiento(int lanz){

    int puntoY = lanz*9;
    locate(53,2+puntoY);
    cout<<"--------------------------------------------------------------"<<endl;
    locate(53,3+puntoY);
    cout<<"LANZAMIENTO NUMERO #"<<lanz+1<<":"<<endl;

    for(int i=0;i<CANT_D;i++){
        dibujarDado(dados[i],i,lanz);

    }

}

///imprime el diseño por defecto del lado izquierdo de la pantalla(horizontal <30)
void dibujarIzqPantalla(){

    for(int i=1;i<30;i++){
        locate(1,i);
        cout<<"                                                ..."<<endl;
    }

}

///se dibuja un marco en pantalla recibiendo el punto de inicio en X e Y, su ancho y su alto
void dibujaMarco(int x,int y,int ancho,int alto){

    for(int i=x; i<x+ancho+3;i++){
        locate(i,y);
        cout<<"_"<<endl;
        locate(i,y+alto);
        cout<<"_"<<endl;
    }
    locate(x,y+alto);
    cout<<"|_|"<<endl;
    locate(x+ancho,y+alto);
    cout<<"|_|"<<endl;

    for(int i=y+1;i<y+alto;i++){
        locate(x,i);
        cout<<"|:|"<<endl;
        locate(x+ancho,i);
        cout<<"|:|"<<endl;
    }

}

///limpia la pantalla y dibuja un cartel con los datos recibidos de una ronda
void dibujaCartelRonda(int ronda,int cantJugadores,string nombre[],int puntos[]){
    cls();
    int marcoX = 40;
    int marcoY = 12;
    int inicioX = 35;
    int inicioY = 5;

    dibujaMarco(inicioX,inicioY,marcoX,marcoY);

    locate(inicioX+marcoX/3,inicioY+marcoY/3);
    cout<<"    RONDA "<<ronda;

    for(int i=0;i<cantJugadores;i++){
        locate(inicioX+marcoX/3,inicioY+marcoY/2+i);
        cout<<"Puntos de "<<nombre[i]<<" : "<<puntos[i]<<endl;
    }
    locate(inicioX,inicioY+marcoY+1);
    cout<<"presione una tecla para continuar "<<endl;
}

///imprime los datos del fin del juego individual de acuerdo a los parametros
void imprimirFInDelJuego(int ronda, string nombre, int puntos, bool record){
    int marcoX = 49;
    int marcoY = 16;
    int inicioX = 33;
    int inicioY = 5;

    dibujaMarco(inicioX,inicioY,marcoX,marcoY);

    locate(inicioX+16,inicioY+marcoY/3);
    cout<<"Finalizaste "<<nombre;
    locate(inicioX+14,inicioY+marcoY-6);
    cout<<"Termino en la ronda "<<ronda<<" con ";
    locate(inicioX+14,inicioY+marcoY-5);
    if(puntos == GEN_SERVIDA){
        cout<<"Generala Servida";
    }
    else{
       cout<<"      "<<puntos<<" puntos";
    }
    if(record){
        locate(inicioX+4,inicioY+marcoY-2);
        cout<<"Felicitaciones, hizo un nuevo record!!";
    }

}

///imprime los datos del fin del juego versus de acuerdo a los parametros
void imprimirFInDelJuego(bool empate, bool esRecord,string ganador,int puntos){

    locate(35,3);
    if(empate){
        cout<<"HUBO EMPATE CON "<<puntos<<" PUNTOS"<<endl;
    }
    else{
        cout<<"GANO EL JUGADOR "<<ganador<<" CON "<<puntos<<" PUNTOS"<<endl;
    }

    if(esRecord){
        locate(35,4);
        cout<<"El GANADOR AHORA TIENE LA PUNTUACION RECORD";
    }

}

#endif // FUNGRAFICAS_H_INCLUDED
