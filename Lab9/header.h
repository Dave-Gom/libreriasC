#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct rectangulo
{
  int a,b,c,d;
}Rectangulo;

typedef struct corrdenada{
  int x,y;
}Coordenada;

void cargaMatriz( const int fila, const int colum, int matriz[][colum] );
int rectangulosHermosos( Rectangulo rectanguloDim, int fila, int columna, int matriz[fila][columna]);
void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]);
void izquierda(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);
void derecha(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);

void arriba(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);
void abajo(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);
int cantidadRecHermosos(int fila, int columna, int matriz[fila][columna]);
