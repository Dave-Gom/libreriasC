/* Laboratorio 8 - Manejo de archivos */
#include"header.h"

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
              fprintf( ptrImpares, "%ld\n", numero);
              break;
            case 0:
              fprintf( ptrPares, "%ld\n", numero);
              break;
            case 1:
              fprintf( ptrPrimos, "%ld\n", numero);
              if( numero != 1){//todos los numero primos excepto el 2 son tambien impares
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
