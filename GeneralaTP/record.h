#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

///compara los puntos enviados en el parametro,devuelve verdadero si corresponden a un nuevo record y reemplaza los datos del record
bool registrarPuntos(int ronda,string nombre, int puntos){
    bool record = false;
    if(puntos>marcaRecord || (puntos==GEN_SERVIDA && ronda<rondaRecord)){
        marcaRecord = puntos;
        jugadorRecord = nombre;
        rondaRecord=ronda;
        record = true;
    }
    return record;
}

///se muestran los datos de la puntuacion record
void mostrarRecord(){
    int marcoX = 80;
    int marcoY = 20;
    int inicioX = 15;
    int inicioY = 4;

    dibujaMarco(inicioX,inicioY,marcoX,marcoY);

    if(marcaRecord>0){
        locate(inicioX+marcoX/3,inicioY+marcoY/2);
        cout<<"El puntaje record es: ";

        if(marcaRecord!=GEN_SERVIDA){
            cout<<marcaRecord<<endl;
        }
        else{
            cout<<"Generala Servida"<<endl;
        }

        locate(inicioX+marcoX/3,inicioY+marcoY/2+1);
        cout<<"Del Jugador "<<jugadorRecord;

        locate(inicioX+marcoX/3,inicioY+marcoY/2+2);
        cout<<"Hecho en "<<rondaRecord<<" rondas";
    }
    else{

        locate(inicioX+marcoX/4,inicioY+marcoY/2);
        cout<<"Todavia no hay registro de puntaje record";

    }


    anykey();

}

#endif // RECORD_H_INCLUDED
