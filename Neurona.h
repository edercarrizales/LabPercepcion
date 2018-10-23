#ifndef Neurona_h
#define Neurona_h
#include "Arduino.h"

class Neurona{ //inicio de la clase Neurona
   public: 
//atributos
   float w[5];
   float x[5];
   float fx, sum;
   int bias=1;
 
//constructor 
    Neurona(); 
    
//metodos
    void setpesos(float valuep[]); //para meter los pesos en la neurona
    void setentradas(float valuex[]); //para meter las entradas a la neurona
    void sumatoria(); //para realizar la sumatoria y activación
    float getfx(); //para obtener la salida de la neurona	

}
