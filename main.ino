/* referencia: http://panamahitek.com/orientacion-a-objetos-en-arduino/ */

/* CODIGO PRINCIPAL DE LA RED NEURONAL */
#include "Neurona.h" //para incluir a la clase Neurona en nuestro codigo principal
Neurona neuron[10]; //creación de un vector de objetos con las 10 neuronas
float pesos[]={{0.98974, 0.8106, -1.3236, 1.3094, -0.96841},
	           {-1.0236, 1.2626, -1.1912, -0.93483, 0.17389},
	           {-1.0334, 0.97535, 0.70657, -0.77163, 1.5046},
	           {0.48952, -1.4867, -1.1721, -1.0599, -0.1817},
	           {-1.3093, -0.86667, -0.53684, 0.1581, 1.4143},
	           {0.65461, -0.56113, 0.22411, -1.7109, 1.0781},
	           {1.1982, 1.1231, -1.4408, -0.40939, -0.47364},
	           {0.44124, 0.4415, 0.4986, -1.8219, 0.70645},
	           {0.78649, 0.97337, -0.020147, -1.3024, -1.2905},
	           {-0.84858, -0.42739, -1.1201, 0.91443, 1.391}}; //Matriz de pesos que tendrá cada neurona
float o[]={-0.8133, -0.72435, 0.94446, -0.48808, 0.54746, 0.1182, -0.86334, -0.32111, 0.19862, -0.048843}; //vector de pesos de las salidas de cada neurona
float entradas[];  //vector para entradas
float sum_salidas; //variable que guarda la sumatoria de las salidas de las neuronas por su peso
float y; //variable de salida de la red neuronal

void setup(){
//INICIO MONITOR SERIAL
Serial.begin(9600);
//ASIGNACION DE PESOS A CADA NEURONA ***REVISAR***
 for(int i=0;i<10;i++){
   for(int j=0;j<5;j++){
   neuron[i].setpesos(pesos[i][j]); //revisar esta linea, ya que se ingresa como dato una matriz y no un array
  }
 }
}

void loop(){
  entradas[]={100,20,20,70,90}; //captura de las entradas en el vector. Prueba con caso 1 de la tabla.
  for(int k=0;k<10;k++){ 
     neuron[k].setentradas(entradas[]);  //ASIGNAR ENTRADAS A CADA NEURONA
     neuron[k].sumatoria(); //realiza la sumatoria y funcion para cada neurona
     sum_salidas+=neuron[k].getfx()*o[k]; //sumatoria de las salidas de las neuronas por su peso
  }
  y=1/(1+exp(sum*-1)); //SALIDA DE LA RED NEURONAL. Debe ser aproximadamente 1 para este caso.
  Serial.println(y);
     
}

