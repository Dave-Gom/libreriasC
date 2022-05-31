#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* Operaciones con arreglos */
int mayor( int arreglo[], const int longitud);//devuelve el mayor elemento del arreglo
int menor( int arreglo[], const int longitud);//devuelve el menor elemento del arreglo

void copia_arreglo( int origen[], int destino[], const int dim);//copia el arreglo del primer argumento en el arreglo del segundo argumento
void imprimeArreglo( int arreglo[], const int longitud);// imprimie el arreglo
void iniciaArreglo( int arreglo[], const int lingitud);//inicializa el arreglo con todos los valores en cero
void cargaVector( int arreglo[], const int lenght);//asigna valores desde la entrada estandar al arreglo
int posMenor( const int arreglo[], const int longitud);//develve la posicion del menor elemento del  menor elemento
int posMayor( const int arreglo[], const int longitud);//develve la posicion del mayor elemento del  menor elemento
int esMonotona( int array[], int dim);
void digitosInt( int arreglo[], int valor);



/* Operaciones con matrices */
void iniciaMatriz( const int fila, const int colum, int matriz[][colum] );//inicializa la matriz con todos los valores en cero
void cargaMatriz( const int fila, const int colum, int matriz[][colum] );//asigna valores desde la entrada estandar al arreglo
void copiaPrimerafilaEnMatriz( const int fila, const int colum, int matriz[][colum] );//copia la primera fila de la matriz en las demas filas
int verificaCeros(int fila, int col, int matriz[][col]);
int esHermosa( int fila, int columna, int matriz[][columna]) ;
void sumaDeColumnas(int fila, int col , int matriz[][col], int sumaCol[]);
void sumaDeFilas(int fila, int col , int matriz[][col], int sumaFilas[]);
int sumaDiagonalPrincipal(int fila, int columna, int matriz[][columna]);
int sumaDiagonalSecundaria(int fila, int columna, int matriz[][columna]);
void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]);
void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna]);