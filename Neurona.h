class Neurona{ //inicio de la clase Neurona
   public: 
//atributos
   float w[5];
   float x[5];
   float fx, sum;
   int bias=1;
  
    
//metodos
    void setpesos(float valuep[]); //para meter los pesos en la neurona
    void setentradas(float valuex[]); //para meter las entradas a la neurona
    void sumatoria(); //para realizar la sumatoria y activación
    float getfx(); //para obtener la salida de la neurona	
};

void Neurona::setpesos(float valuep[5]){ //para definir pesos
	w[5]=valuep[5]; 
}
void Neurona::setentradas(float valuex[5]){ //para definir entradas
	x[5]=valuex[5]
}
void Neurona::sumatoria(){
	for(int i=0;i<5;i++){ //sumatoria y activación
	   sum+=w[i]*x[i];
	}
	fx=1/(1+exp((sum+bias)*-1));
}
float Neurona::getfx(){ //obtener la salida de la neurona
	return fx;
}
