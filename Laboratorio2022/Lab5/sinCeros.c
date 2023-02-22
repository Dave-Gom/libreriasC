#include <stdio.h>
#include <ctype.h>
#include<string.h>
#include<stdlib.h>

int main(){

  int primerNumero, segundoNumero, resultado;
  int digitosPrimer[9] = {0};
  int digitosSeg[9] = {0};
  int digitosRes[9] = {0};
  char cadenaPrim[9] = "";
  char cadenaSeg[9] =  "";
  char cadenaRes[9] ="";
  
  scanf("%d", &primerNumero);
  scanf("%d", &segundoNumero);
  resultado = primerNumero + segundoNumero;
  digitosInt( digitosPrimer, primerNumero);
  digitosInt( digitosSeg, segundoNumero);
  digitosInt( digitosRes, resultado);
  copiaArregloDeEnterosAString(digitosPrimer, cadenaPrim, 9);
  copiaArregloDeEnterosAString(digitosSeg, cadenaSeg, 9);
  copiaArregloDeEnterosAString(digitosRes, cadenaRes, 9);



  if ( atoi(cadenaPrim) + atoi(cadenaSeg) == atoi(cadenaRes)){

    printf("SI");
  }
  else
  {
    printf("NO");
  }


  return 0;
}

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

/* void imprimeArreglo( int arreglo[], const int longitud){
  int i;
  for(i = 0; i<longitud; i++){
    printf("%d ", arreglo[i]);
    if( isalpha(arreglo[i]) )
      printf("si\n");
  }
} */

void copiaArregloDeEnterosAString( int origen[], char destino[], const int dim){
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