
float gradosp[5][5]; /*array que guarda grados de pertenencias de los 5 conjuntos
difusos de cada una de las 5 variables */
float entradas[5];
float min;
float tablareglas[6][103]= {{0,	0,	0,	0,	1,	2},
                            {1,	0,	0,	0,	0,	1},
                            {4,	0,	0,	0,	5,	1},
                            {5,	0,	0,	0,	0,	1},
                            {1,	0,	0,	1,	0,	1},
                            {4,	0,	0,	4,	0,	4},
                            {3,	0,	0,	5,	0,	5},
                            {2,	1,	1,	1,	4,	1},
                            {1,	1,	1,	4,	5,	2},
                            {3,	1,	1,	4,	5,	4},
                            {1,	1,	1,	5,	3,	3},
                            {5,	1,	1,	5,	3,	1},
                            {4,	1,	2,	1,	1,	1},
                            {4,	1,	2,	1,	2,	1},
                            {4,	1,	2,	1,	3,	1},
                            {5,	1,	2,	2,	3,	2},
                            {4,	1,	2,	5,	4,	2},
                            {5,	1,	3,	2,	5,	1},
                            {4,	1,	3,	4,	4,	2},
                            {3,	1,	3,	5,	2,	4},
                            {3,	1,	3,	5,	4,	5},
                            {5,	1,	3,	5,	3,	2},
                            {4,	1,	4,	1,	3,	1},
                            {2,	1,	4,	2,	1,	2},
                            {5,	1,	4,	3,	2,	1},
                            {2,	1,	4,	4,	1,	4},
                            {3,	1,	4,	4,	1,	4},
                            {3,	1,	4,	5,	3,	4},
                            {3,	1,	5,	2,	2,	3},
                            {1,	1,	5,	4,	5,	2},
                            {2,	1,	5,	4,	2,	5},
                            {5,	1,	5,	4,	4,	2},
                            {2,	1,	5,	5,	4,	3},
                            {3,	2,	1,	2,	4,	3},
                            {3,	2,	1,	4,	2,	5},
                            {4,	2,	1,	4,	4,	3},
                            {4,	2,	2,	2,	3,	3},
                            {3,	2,	2,	5,	4,	5},
                            {5,	2,	2,	5,	2,	3},
                            {5,	2,	2,	5,	5,	2},
                            {3,	2,	3,	1,	5,	3},
                            {1,	2,	3,	2,	5,	2},
                            {1,	2,	3,	4,	1,	1},
                            {4,	2,	3,	4,	3,	5},
                            {2,	2,	3,	5,	4,	5},
                            {3,	2,	3,	5,	3,	5},
                            {3,	2,	3,	5,	4,	5},
                            {5,	2,	4,	2,	1,	2},
                            {3,	2,	4,	4,	3,	4},
                            {4,	2,	5,	3,	3,	2},
                            {5,	2,	5,	3,	4,	3},
                            {2,	2,	5,	5,	3,	3},
                            {2,	3,	1,	1,	4,	1},
                            {3,	3,	1,	1,	3,	1},
                            {3,	3,	1,	3,	3,	4},
                            {1,	3,	1,	4,	1,	1},
                            {4,	3,	1,	4,	3,	3},
                            {4,	3,	2,	1,	3,	1},
                            {3,	3,	3,	0,	0,	4},
                            {5,	3,	3,	1,	3,	1},
                            {2,	3,	3,	2,	3,	2},
                            {3,	3,	3,	3,	1,	3},
                            {3,	3,	3,	4,	5,	5},
                            {2,	3,	3,	5,	5,	5},
                            {3,	3,	5,	2,	5,	3},
                            {4,	3,	5,	2,	3,	2},
                            {3,	3,	5,	3,	5,	3},
                            {4,	3,	5,	3,	2,	3},
                            {2,	3,	5,	4,	2,	4},
                            {2,	3,	5,	4,	5,	3},
                            {4,	4,	0,	0,	0,	2},
                            {2,	4,	1,	2,	1,	2},
                            {1,	4,	1,	4,	1,	3},
                            {5,	4,	1,	5,	3,	3},
                            {4,	4,	3,	5,	2,	5},
                            {4,	4,	3,	5,	4,	1},
                            {2,	4,	4,	2,	4,	4},
                            {3,	4,	4,	2,	4,	3},
                            {5,	4,	4,	3,	3,	2},
                            {1,	4,	5,	1,	1,	1},
                            {3,	4,	5,	3,	5,	2},
                            {4,	4,	5,	3,	3,	4},
                            {2,	4,	5,	4,	3,	3},
                            {5,	4,	5,	5,	5,	5},
                            {5,	5,	0,	0,	0,	1},
                            {1,	5,	1,	1,	2,	1},
                            {2,	5,	1,	2,	1,	2},
                            {3,	5,	1,	2,	1,	3},
                            {2,	5,	1,	5,	1,	3},
                            {1,	5,	2,	1,	3,	1},
                            {2,	5,	2,	1,	3,	3},
                            {4,	5,	2,	1,	4,	3},
                            {2,	5,	2,	4,	2,	4},
                            {2,	5,	3,	2,	4,	3},
                            {5,	5,	3,	2,	5,	1},
                            {5,	5,	3,	3,	2,	2},
                            {4,	5,	4,	1,	1,	1},
                            {2,	5,	4,	3,	2,	2},
                            {5,	5,	4,	4,	2,	1},
                            {4,	5,	5,	1,	4,	1},
                            {4,	5,	5,	2,	3,	1},
                            {2,	5,	5,	4,	3,	2},
                            {4,	5,	5,	5,	2,	4}};
                     
float niveles[5]={1,2,3,4,5};
float conclusiones[5][103];
float grados_salida[103];

void loop(){
//las entradas se guardan en un array
entradas[0]=temperatura;
entradas[1]=luz;
entradas[2]=calidad_aire;
entradas[3]=pulso;
entradas[4]=humedad;
//se sacan los grados de pertenencia de cada variable de entrada
  gradosp[0]= grado_temperatura(entrada[0]);
  gradosp[1]= grado_luz_hum_air(entrada[1]);
  gradosp[2]= grado_luz_hum_air(entrada[2]);
  gradosp[3]= grado_pulso(entrada[3]);
  gradosp[4]= grado_luz_hum_air(entrada[4]);
  
  //ESTA PARTE DEL CODIGO RELACIONA LOS GRADOS DE PERTENENCIA DE LAS ENTRADAS A LA TABLA DE REGLAS
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      k=0;
      while(k<103){
        if(niveles[j]==tablareglas[j][k]){
          conclusiones[j][k]=gradosp[i][j];}
      k++;
      }
    }
  }
  //ESTA PARTE DEL CODIGO REALIZA LA OPERACION AND EN CADA REGLA Y OBTIENE EL GRADO DE SALIDA
  for(int m=0;m<5;m++){
    min=conclusiones[m][0];
    for(int n=0;n<5;n++){
        if(conclusiones[m][n] < min){
          min=conclusiones[m][n];}
      }
    grados_salida[m]=min;
    }
 
}
float grado_temperatura(float x){ 
float bajo,muybajo,medio,alto,muyalto;
//rutina que obtiene grado de pertenencia para temperatura
if (x <= 5) { //saca grado en conjunto muy bajo
 muybajo=1;
}else if (x >= 10) {
 muybajo = 0;
 } else if (x >5 && x <10) {
 muybajo= (10-x)/(10-5);
}

if (x <=5 && x>=25) { //saca grado en conjunto bajo
 bajo=0;
}else if (x > 5 && x <=15) {
 bajo = (x - 5)/(15-5);
 } else if (x >=15 && x <25) {
 bajo= (25-x)/(25-15);
}

if (x <=15 && x>=35) { //saca grado en conjunto medio
 medio =0;
}else if (x > 15 && x <=25) {
 medio = (x - 15)/(25-15);
 } else if (x >=25 && x <35) {
 medio = (35-x)/(35-25);
}


if (x <=25 && x>=45) { //saca grado en conjunto alto
 alto =0;
}else if (x > 25 && x <=35) {
 alto = (x - 25)/(35-25);
 } else if (x >=35 && x <45) {
 alto = (45-x)/(45-35);
}

if (x <=40) { //saca grado en conjunto muy alto
 muyalto =0;
}else if (x > 40 && x <45) {
 muyalto = (x-40)/(45-40);
 } else if (x >=45) {
 muyalto = 1;
}

float grado_luz_hum_air(float x){ 
float bajo,muybajo,medio,alto,muyalto;
//rutina que obtiene grado de pertenencia para luz, aire y humedad
if (x <= 10) { //saca grado en conjunto muy bajo
 muybajo=1;
}else if (x >= 20) {
 muybajo = 0;
 } else if (x >10 && x <20) {
 muybajo= (20-x)/(20-10);
}

if (x <=10 && x>=50) { //saca grado en conjunto bajo
 bajo=0;
}else if (x > 10 && x <=30) {
 bajo = (x - 10)/(30-10);
 } else if (x >=30 && x <50) {
 bajo= (50-x)/(50-30);
}

if (x <=30 && x>=70) { //saca grado en conjunto medio
 medio =0;
}else if (x > 30 && x <=50) {
 medio = (x - 30)/(50-30);
 } else if (x >=50 && x <70) {
 medio = (70-x)/(70-50);
}


if (x <=50 && x>=90) { //saca grado en conjunto alto
 alto =0;
}else if (x > 50 && x <=70) {
 alto = (x - 50)/(70-50);
 } else if (x >=70 && x <90) {
 alto = (70-x)/(90-70);
}

if (x <=80) { //saca grado en conjunto muy alto
 muyalto =0;
}else if (x > 80 && x <90) {
 muyalto = (x-80)/(90-80);
 } else if (x >=90) {
 muyalto = 1;
}

float grado_pulso(float x){ 
float bajo,muybajo,medio,alto,muyalto;
//rutina que obtiene grado de pertenencia PULSO CARDIACO
if (x <= 0) { //saca grado en conjunto muy bajo
 muybajo=1;
}else if (x >= 30) {
 muybajo = 0;
 } else if (x >15 && x <30) {
 muybajo= (30-x)/(30-15);
}

if (x <=10 && x>=60) { //saca grado en conjunto bajo
 bajo=0;
}else if (x > 10 && x <=35) {
 bajo = (x - 10)/(35-10);
 } else if (x >=35 && x <60) {
 bajo= (60-x)/(60-35);
}

if (x <=40 && x>=90) { //saca grado en conjunto medio
 medio =0;
}else if (x > 40 && x <=65) {
 medio = (x - 40)/(65-40);
 } else if (x >=65 && x <90) {
 medio = (90-x)/(90-65);
}


if (x <=70 && x>=120) { //saca grado en conjunto alto
 alto =0;
}else if (x > 70 && x <=96) {
 alto = (x - 70)/(95-70);
 } else if (x >=95 && x <120) {
 alto = (120-x)/(120-95);
}

if (x <=100) { //saca grado en conjunto muy alto
 muyalto =0;
}else if (x > 100 && x <115) {
 muyalto = (x-100)/(115-100);
 } else if (x >=130) {
 muyalto = 1;
}


}

