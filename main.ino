
#include <stdio.h>
#include <math.h>

/* CODIGO PRINCIPAL DE LA RED NEURONAL en c++ (PUDO COMPILARSE y FUNCIONA*/

float pesos[10][5]=	{{-2.2566 ,-1.6073, 4.5879, -1.7217, 2.8855}, //matriz de pesos
			{2.5878, 2.3727 ,0.65321 ,-2.5595, -0.62181},
			 {-2.448 ,-2.2294 ,-1.003, 2.3426 ,-1.5004},
			 {1.6966 ,-1.2221, -0.74892, 4.2356 ,-1.4105},
			 {1.3647, -1.2293, -1.0779, 0.84817 ,-3.7749},
			 {0.55926 ,0.28109, -2.5553, 0.057725, -2.6402},
			 {-2.4934, 2.1719 ,-1.3042, -1.094, 2.7571},
			 {-0.62004, 1.2122, -4.5157 ,3.4804, 1.7965},
			 {-2.533 ,0.59524 ,-3.1944, -1.4765, 0.84828},
			 {1.5498 ,-1.8177, -1.3099, -1.9517, -2.7161}};
float o[10]={5.3685, -0.22467, 0.41556 ,-2.4524, -1.9709, -2.3866, 1.2674, -4.8561, 0.015185, 0.09361}; //vector de pesos de las salidas de cada neurona
float wbias[10]={3.4430,-3.5317, 2.9038 ,-0.9064,-0.1030 ,-0.4307,-1.3326,-1.3909 ,  -3.6082 ,   4.5604}; //vector de pesos de los bias de cada neurona
float entradas[5];  //vector para entradas. Aqui asigné las entradas para probar con el primer caso de nuestra tabla.
float sum_salidas=0; //variable que guarda la sumatoria de las salidas de las neuronas por su peso
float normy,y; //variable de salida de la red neuronal
float bias2=1.619; //bias del nodo de salida
float sum[10]; //variable auxiliar para sumatoria de los pesos por su entrada en la neurona
float xw[10][5]; //matriz que guarda la multiplicacion de los pesos por las entradas
float ofx[10]; //array de activación por el peso del nodo de salida
float fx[10]; //array que guarda la activacion de la sumatoria de la neurona
float normx[5]; //entradas normalizadas
int grado_salud; //es el grado de la salud de nuestro sistema


void setup (){
        for(int h=3;h<=5;h++){ //declara pines de los leds como salida
	pinMode(h,OUTPUT);
        }
}

void loop() {
  //AQUI SE GUARDAN LAS ENTRADAS, DEBEN COLOCARSE EN ESTE ORDEN
/*LUZ, TEMPERATURA, HUMEDAD, PULSO, POSTURA */
entradas[0]=100;
entradas[1]=20;
entradas[2]=20;
entradas[3]=70;
entradas[4]=90;

//se normalizan entradas
normx[0]=(entradas[0]-0)*(1-(-1))/(100-0)+(-1);
normx[1]=(entradas[1]-20)*(1-(-1))/(70-20)+(-1);
normx[2]=(entradas[2]-20)*(1-(-1))/(70-20)+(-1);
normx[3]=(entradas[3]-0)*(1-(-1))/(118-0)+(-1);
normx[4]=(entradas[4]-9)*(1-(-1))/(180-9)+(-1);   
//INICIA RED NEURONAL
   for(int i=0;i<10;i++){ 
     for(int j=0;j<5;j++){
          xw[i][j]=pesos[i][j]*normx[j]; //multiplica pesos y entradas de cada neurona
          sum[i]=sum[i]+xw[i][j]; //suma elementos de cada neurona
      }
      fx[i]=1/(1+exp(-1*(sum[i]+wbias[i]))); //funcion de activacion de cada neurona
      ofx[i]=fx[i]*o[i]; //multiplica salidas de las neuronas por pesos del nodo de la salida
      sum_salidas=ofx[i]+sum_salidas; //suma todos los elementos para la salida
    } 
     normy=1/(1+exp((sum_salidas+bias2)*-1)); //funcion de activacion final
     y=(((normy-0)*2)/1)+1;  //SALIDA FINAL DE LA RED NEURONAL
//REINICIO DE LAS VARIABLES DE SUMA. Esto para que no se acumulen los valores y arrojen errores.
        for(int v=0;v<10;v++){
		sum[v]=0;
	}
	sum_salidas=0;
//ASIGNACION DE GRADOS DE SALUD
if(y>=0.95 && y<= 1.05)
	grado_salud=1; 
if(y>=1.95 && y<= 2.05)
	grado_salud=2; 
if(y>=2.95 && y<= 3.05)
	grado_salud=3; 
/*--------------Dependiendo del grado de salud, el sistema realizara ciertas funciones:----------*/
}
