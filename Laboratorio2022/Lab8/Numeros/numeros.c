/* Laboratorio 8 - Manejo de archivos */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *abreArchivo( char nombre[], char tipoApertura[]); //abre un archivo y le asigna el nombre recibido como argumento, si no puede abrirlo imprime un mensaje y retorna null
int tipoNumero( long );
int esPrimo( long );

int main()
{
  FILE *ptrPares, *ptrImpares, *ptrPrimos, *ptrOrigen;

  long int numero;
  if( (ptrOrigen = abreArchivo("numeros.txt", "r")) != NULL){
    if( (ptrPares = abreArchivo("pares.txt", "w")) != NULL){
      if( (ptrImpares = abreArchivo("impares.txt", "w")) != NULL){
        if( (ptrPrimos = abreArchivo("primos.txt", "w")) != NULL){
          
          while (!feof(ptrOrigen))
          {
            fscanf(ptrOrigen, "%ld", &numero);
            
            switch (tipoNumero(numero))
            {
            case -1:
              printf("el numero %ld es impar\n", numero);
              fprintf( ptrImpares, "%ld\n", numero);
              break;
            case 0:
              printf("el numero %ld es par\n", numero);
              fprintf( ptrPares, "%ld\n", numero);
              break;
            case 1:
              printf("el numero %ld es primo\n", numero);
              fprintf( ptrPrimos, "%ld\n", numero);
              if( numero != 1){
                printf("el numero %ld es impar\n", numero);//todos los numero primos excepto el 2 son tambien impares
                fprintf( ptrImpares, "%ld\n", numero);

              }
              break;
          
            default:
              break;
            }

          }
          fclose(ptrPares);
          fclose(ptrImpares);
          fclose(ptrPrimos);
          fclose(ptrOrigen);
        }
      }
    }
  }

  return 0;
}

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

  printf("bander = %d\t", bandera);
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

