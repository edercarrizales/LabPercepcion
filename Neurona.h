class Neurona{ //inicio de la clase Neurona
   public: 
//atributos
   float w[5];
   float x[5];
   float fx, sum;
   int bias=1;
  
    
//metodos
    void setpesos(float valuep[]){
	    w[5]=valuep[5]; 
    }//para meter los pesos en la neurona
    void setentradas(float valuex[]){
    		x[5]=valuex[5]:
    }//para meter las entradas a la neurona
    void sumatoria(){
	    for(int i=0;i<5;i++){ //sumatoria y activación
	   sum+=w[i]*x[i];
	}
	fx=1/(1+exp((sum+bias)*-1));
    }//para realizar la sumatoria y activación
    float getfx(){
	    return fx;
    }//para obtener la salida de la neurona	
};

