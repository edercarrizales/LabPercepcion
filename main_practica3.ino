
float gradop[5]; /*array que guarda grados de pertenencias de los 5 conjuntos
difusos de cada una de las 5 variables */
float inputs[5];
float nivel_saludable; //salida final del sistema

void loop(){
 nivel_saludable = FuzzySysT1(inputs,tabla_reglas); /*REVISAR ESTA LINEA*/
  
  
}

int reglas=103;
int entradas = 5;//NTI=NTV-1;

double trapezoidmf(double x,double a,double b,double c,double d){ //FUNCION DE MEMBRESÍA TIPO TRAPEZOIDE
  double mf=max(min(min((x-a)/(b-a+0.000001),1),(d-x)/(d-c+0.0000001)),0);
  return mf;
}
double trianglemf(double x,double a,double b,double c){ //FUNCION DE MEMBRESIA TIPO TRIANGULAR
  double mf=max(min((x-a)/(b-a+0.000001),(c-x)/(c-b+0.000001)),0);
  return mf;
}
double Type1FS(double x,int n,double V[]){
  double a=V[0];
  double b=V[1];
  double c=V[2];
  double mf;
  if (n== 1){
      mf=trapezoidmf(x,a-1.0001,a,b,c);
    return mf;
    }
  if (n==2){
  mf=trianglemf(x,a,b,c);
  return mf;
    }
  if (n==3){
    mf=trianglemf(x,a,b,c);
    return mf;
    }
    if (n==4){
    mf=trianglemf(x,a,b,c);
    return mf;
    }
    if (n==5){
    mf=trapezoidmf(x,a,b,c,c+1);
    return mf;
    }
    if (n==0){
    mf=1;
    return mf;
    }
  }
  
double FuzzySysT1(double X[],int DB[][3])
{
    double PARAM[5][3]={{-1.0, -0.6666, -0.3333}
                      ,{-0.6666, -0.3333, 0}
                      ,{-0.3333, 0, 0.3333}
                      ,{0, 0.3333, 0.6666}
                      ,{0.3333, 0.6666, 1}};
    double V[3];
    double AC[5]={0,0.25,0.5,0.75,1};
    double Fo[reglas];
    for(int r=0;r<=(reglas-1);r++){
      double sumin=1;
      int n;
      for(int i=0;i<=(entradas-1);i++){
            n=DB[r][i]-1;
            if(n>-1){
            V[0]=PARAM[n][0];
            V[1]=PARAM[n][1];
            V[2]=PARAM[n][2];
         }
          double mf=Type1FS(X[i],(n+1),V);
          sumin=min(sumin,mf);
       }
     Fo[r] = sumin;
   }
      double sum1=0; double sum2=0.00000001;
      for(int r=0;r<=(reglas);r++){
         sum1=(sum1+(Fo[r]*AC[DB[r][2]-1]));
         sum2=(sum2+Fo[r]);
         }
      double y=sum1/sum2;
      return y;
}




