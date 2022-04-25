#include<stdio.h>
#include<stdlib.h>

typedef struct triangulo{ /* define un triangulo con lado de longitud a, b, c */
  int mayor;
  int menor;
  int mediano;
}Triangulo;

/* Estructuras de datos */
void imprimeCamino( int fila, int col, int a[][col]);
int agendador(int arreglo1[], const int dim, const int dias);
int sube_escalera( int n );