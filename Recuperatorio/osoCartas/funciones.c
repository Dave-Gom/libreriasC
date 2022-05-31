#include"header.h"


int menor( int arreglo[], const int longitud){

  int menor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      menor=arreglo[i];

    if( arreglo[i]<menor && arreglo[i] != -1) //-1 es el valor con el que se inicializo el vector de sumas, como cada carta tiene un entero positivo este numero no se debe tomar en cuenta para el resultado final
      menor = arreglo[i];

  }

  return menor;
}


