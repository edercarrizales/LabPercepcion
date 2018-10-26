#include <stdio.h>
#include <math.h>

class Neurona{ //inicio de la clase Neurona
   public: 
//atributos
   float w[5];
   float x[5];
   float normx[5];
   float fx, sum;
   float bias;
   
//metodos
    void setpesos(float valuep){
	   //para asignar los pesos en la neurona y guardarlos en un arreglo w
               for(int i=0;i<5;i++){
               w[i]=valuep;
               }
    }
 void setbias(float valuec){
	   //para asignar el bias en la neurona
               bias=valuec;
               
    }
	
    void setentradas(float valuex){     //para meter las entradas a la neurona y guardarlas en su arreglo x
     for(int m=0;m<5;m++){
        x[m]=valuex;
     }
	//NORMALIZACION DE ENTRADAS, PARA PONERLAS EN UN RANGO DE 0 A 1
	normx[0]=(x[0]-0)/(100-0);
	normx[1]=(x[1]-20)/(70-20);
	normx[2]=(x[2]-20)/(70-20);
	normx[3]=(x[3]-0)/(118-0);
	normx[4]=(x[4]-9)/(180-9);
    }
    void sumatoria(){
	   for(int n=0;n<5;n++){ //sumatoria y activación
	   sum=sum+w[n]*normx[n];
	}
	fx=1/(1+exp((sum+bias)*-1));
    }//para realizar la sumatoria y activación
    float getfx(){
	    return fx;
    }//para obtener la salida de la neurona
    	
};
