#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<time.h>

void arrayAleatorio( int arreglo[], int longitud, int valorLimite);//asigna numeros aleatorios del cero hasta el valor del tercer argumento al arreglo
void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite);//asigna numeros aleatorios del cero hasta el valor del tercer argumento a la matriz

int enteroAleatorio(int limite);//devuelve un numero entero aleatorio menor entre uno y el limite
int enteroAleatorioEntre(int limiteInf, int limiteSup);//devuelve un numero aleatorio entre el limite inferior y el superior

float flotanteAleatorio();//devuelve un numero flotante aleatorio
char caracterAleatorio(); // devuelve un caracter aleatorio 
void cadenaAleatoria( char cadena[], int longitud); //agrega varacteres aleatorios a la cadena
char *cadenaAleatoriaLongAleatoria(); //devuelve el apuntador a una cadena de longitud aleatoria




