#include"header.h"

int resta_errad(int n){
  int res;
  int ult = n%10;
  if(ult == 0){
    res = n/10;
  }
  else
  {
    res = n-1;
  }
  
  return res;
}

/* devuelve uno cero si todos los digitos del anio son diferentes
caso contrario devuelce -1 */
int is_beautifull_year(int anio){
  int unid, dec, cent, uni_mil, ret = 0;

  unid = anio%10;
  dec = ((anio%100) - unid)/10;
  cent = ((anio %1000)- dec*10 - unid)/100;
  uni_mil = ((anio%10000) - cent*100 - dec*10 - unid)/1000;

  if( unid == dec)
    ret = -1;

  if( unid == cent)
    ret = -1;

  if( unid == uni_mil)
    ret = -1;

  if( cent == dec)
    ret = -1;

  if( uni_mil == dec)
    ret = -1;

  if( uni_mil == cent)
    ret = -1;

  return ret;
}


int calc_pasos(int dist){
  int pos = 0, pasos = 0 ,x = dist;
  while (pos != x)
  {
    if(pos+5 <= x){
      pasos++;
      pos+=5;
      break;
    }
    if(pos+4 <= x){
      pasos++;
      pos+=4;
      break;
    }
    if(pos+3 <= x){
      pasos++;
      pos+=3;
      break;
    }
    if(pos+2 <= x){
      pasos++;
      pos+=2;
      break;
    }
    if(pos+1 <= x){
      pasos++;
      pos+=1;
      break;
    }
  }

  return pasos;
}

/* retorna la posicion de un valor dentro de un arreglo, -1 si el 
no se encuentra */
int busqueda_lineal(  int arreglo[], const int longitud, int valorABuscar){
  int i, bandera = 0;
  for ( i = 0; i< longitud; i++){
    if(arreglo[i] == valorABuscar){
      bandera = 1;
      break;
    }
  }

  if(bandera == 0)
    i = -1;

  return i;
}

/* retorna el mayor elemento de un arreglo */
int mayor( int arreglo[], const int longitud){

  int mayor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      mayor=arreglo[i];

    if( arreglo[i]>mayor)
      mayor = arreglo[i];

  }

  return mayor;
}

/* retorna el menor elemento de un arreglo */
int mayor( int arreglo[], const int longitud){

  int mayor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      mayor=arreglo[i];

    if( arreglo[i]>mayor)
      mayor = arreglo[i];

  }

  return mayor;
}