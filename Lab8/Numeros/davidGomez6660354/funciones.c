#include"header.h"


FILE *abreArchivo( char nombreArchivo[], char tipoApertura[]){
  FILE *ptrArchivo;
  ptrArchivo = fopen(nombreArchivo, tipoApertura);
  if( ptrArchivo == NULL )
  {
    printf("No se pudo abrir el Archivo %s", nombreArchivo);
    return NULL;
  }
  else
  {
    return ptrArchivo;
  }
  
}

int tipoNumero( long numero){ // retorna -1 si es impar 0 si es par y 1 si es primo
  if( numero < 0)
    numero = numero * -1;
    
  if( esPrimo(numero) != 1){
    return 1;
  }
  else{
    if ( numero % 2 == 0)
    {
      return 0;
    }
    else
    {
      return -1;
    }
  }
  
}

int esPrimo( long numero){ //retorna cero si el numero es primo
  int contadorDivisores = 0, i;
  int bandera = 0;
  for( i = 1; i<= (numero/2); i++){ //un numero mayor a la mitad del numero recibido jamas sera divisor exacto

    if( contadorDivisores > 1){ //el iterador empieza en uno, y el contador de divisore aumenta, si encuentra otro divisor exacto no es primo

      bandera = 1;
      break;
    }
    else {
      if (numero % i == 0)
      {
        contadorDivisores++;
      }
    }
    
  }

  switch (bandera)
  {
  case 0:
    return 0;
    break;
  case 1:
    return 1;
  default:
    return 1;
    break;
  }
}

