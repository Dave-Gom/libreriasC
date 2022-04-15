
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void menu();
void opcion1();
void opcion2();
void apariciones(char expresion[]);
void aparicion(char exp[], char p);
void vocales( char expresion[]);





void menu(){
  printf("%s\n%s\n%s\n%s\n", "Ingrese su opcion", "Opcion 1: Programa de texto", "Opcion 2: Programa de Matriz magica", "Opcion 3: Salir");
}

void opcion1(){
  char expresion[80];


  scanf ("%s", expresion);
  printf("%s\n" ,expresion);
 
  apariciones(expresion);
  vocales( expresion);


}

void apariciones( char expresion[]){
  aparicion( expresion, 'p');
  aparicion( expresion, 'r');
  aparicion( expresion, 'c');
  aparicion( expresion, 'e');
  aparicion( expresion, 'o');
}

void aparicion ( char exp[], char p){
  int i;
  for(i = 0; i< strlen(exp); i++){
    if( exp[i] == p){
      printf("%c aparece en la posicion %d\n", p, i);
      break;
    }
  }
}

void vocales( char exp[]){
  int cantidadAparicion[5] = {0}; /* posiciones 0 = a , 1 = e,... 4 = u */
  char vocalesstr[] = "aeiou";
  int longitud, i;
  longitud = strlen(exp);
  for ( i = 0; i < longitud; i++)
  {
    if( exp[i] == 'a' || exp[i] == 'A'){
      cantidadAparicion[0]++;
    }
    if( exp[i] == 'e' || exp[i] == 'E'){
      cantidadAparicion[1]++;
    }
    if( exp[i] == 'i' || exp[i] == 'I'){
      cantidadAparicion[2]++;
    }
    if( exp[i] == 'o' || exp[i] == 'O'){
      cantidadAparicion[3]++;
    }
    if( exp[i] == 'u' || exp[i] == 'U'){
      cantidadAparicion[4]++;
    }
    
  }
  
  for(i = 0; i< 5; i++){
    if( cantidadAparicion[i] != 0){
      printf("la vocal %c aparece %d veces \n su pocentaje de aparicion es %d prociento\n", vocalesstr[i], cantidadAparicion[i], 100*(cantidadAparicion[i]/longitud) );
    }
    else
    {
      printf("La vocal %c no existe o no tiene repeticion\n", vocalesstr[i]);
    }
    
  }
}


void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna])//lee solo digitos del 0 al 9 a una matriz dada
{

  int i,j;
  int val;
  for( i = 0; i< fila; i++){
    for( j = 0; j < columna ; j++){
      scanf("%d", &val);
      while (val < 0 || val > 9)
      {
        printf("valor incorrecto reingrese");
        scanf("%d", &val);
        
      }
      mat[i][j] = val;
    }
  }
}