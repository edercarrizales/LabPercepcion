
float gradop[5]; /*array que guarda grados de pertenencias de los 5 conjuntos
difusos de cada una de las 5 variables */
float entradas[5];

void loop(){
//las entradas se guardan en un array
entradas[0]=temperatura;
entradas[1]=luz;
entradas[2]=calidad_aire;
entradas[3]=pulso;
entradas[4]=humedad;
//se sacan los grados de pertenencia finales de cada variable de entrada
  gradop[0]= grado_temperatura(entrada[0]);
  gradop[1]= grado_luz_hum_air(entrada[1]);
  gradop[2]= grado_luz_hum_air(entrada[2]);
  gradop[3]= grado_pulso(entrada[3]);
  gradop[4]= grado_luz_hum_air(entrada[4]);

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

