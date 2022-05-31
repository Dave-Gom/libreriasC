#include"pruebas.h"
#include<limits.h>

void arrayAleatorio( int arreglo[], int longitud, int valorLimite){
  /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* incluir stdlib para usar rand() y time() */
  int i,j;
  srand(time(NULL));
  for ( i = 0; i < longitud; i++)
  {
    arreglo[i] = rand() % valorLimite;
  }
  
}

void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite)
{ /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* incluir stdlib para usar rand() y time() */
  int i,j;
  srand(time(NULL));
  for ( i = 0; i < fila; i++)
  {
    for ( j = 0; j < columna; j++)
    {
      arreglo[i][j] = rand() % valLimite;
    }
    
  }
}

int enteroAleatorio(int limite){//devuelve un numero entero positivo, negativo o cero aleatorio

  int valor1 = (rand() % limite);
  int valor2 = (rand() % limite);

  return valor1-valor2;

}

int enteroAleatorioEntre(int limiteInf, int limiteSup){//devuelve un numero aleatorio entre el limite inferior y el superior

  int valor = limiteInf + (rand() % (limiteSup - limiteInf));
  return valor;

}

float flotanteAleatorio(){//devuelve un numero flotante aleatorio
  //INT32_MAX es el limite maximo de los int de 32 bits
  int numerador = enteroAleatorio(INT32_MAX); //OPTIENE el numerador de forma aleatoria
  int denominador = 1 + enteroAleatorioEntre( 1, INT32_MAX -1); //OPTIENE el denominador de forma aleatoria el valor no puede ser cero
  float flotante = numerador / denominador;

  return flotante;
}

char caracterAleatorio(){ // devuelve un caracter aleatorio 
  char caracter = enteroAleatorioEntre(0, CHAR_MAX) + '0'; //asigna el valor aleatorio la variable
  return caracter;
}

void cadenaAleatoria( char cadena[], int longitud){ //agrega varacteres aleatorios a la cadena
  int i;
  for ( i = 0; i < longitud-1; i++)
  {
    cadena[i] = caracterAleatorio(); //asigna caracteres de forma aleatoria a la cadena
  }
  cadena[longitud -1] = '\n'; // asigna caracter de escape al ultimo caracter de la cadena
}

char *cadenaAleatoriaLongAleatoria(){ //devuelve el apuntador a una cadena de longitud aleatoria
  int longitud = enteroAleatorioEntres(1, 500);
  char Cadena[longitud];
  cadenaAleatoria(Cadena, longitud);
  return Cadena;

}
