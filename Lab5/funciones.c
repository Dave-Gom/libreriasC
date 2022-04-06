#include"header.h"
void digitosInt( const int *arreglo[], int valor){
  int longitud = 9; /* un int solo puede almacenar numeros de hasta 9 digios */
  int cont = 9, digito;
  while(valor!=0)
  {
  cont--;
  digito=valor%10;
  *(arreglo + cont) = digito;
  valor=valor/10;
  ;
  }
}


void copia_arreglo_aString( int origen[], char destino[], const int dim){
  int i, cont = 0;
  char digit;
  for( i= 0; i<dim; i++){
    digit = origen[i] + '0';
    if(origen[i] != 0 && isdigit(digit) != 0 ){
      destino[cont]=digit;
      cont++;
    }
  }
}

char enteroACaracter(char numero){
    return numero + 0;
}