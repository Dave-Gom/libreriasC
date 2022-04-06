#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int resta_errad(int n);
int is_beautifull_year(int anio);
int calc_pasos(int dist);

int busqueda_lineal(  int arreglo[], const int longitud, int valorABuscar);
int mayor( int arreglo[], const int longitud);
int menor( int arreglo[], const int longitud);

void burbuja_asc( int arreglo[], const int longitud);
void burbuja_des( int arreglo[], const int longitud);

void iniciaMatriz( const int fila, const int colum, int matriz[][colum] );

int busquedaBinaria( int arreglo[], int valBuscado, int inicio, int fin);

int sube_escalera( int n );

void cargaVector( int arreglo[], const int lenght);

int agendador(int arreglo1[], const int dim, const int dias);


void copia_arreglo( int origen[], int destino[], const int dim);

void cargaMatriz( const int fila, const int colum, int matriz[][colum] );

void imprimeArreglo( int arreglo[], const int longitud);

void digitosInt( int arreglo[], int valor);

void iniciaArreglo( int arreglo[], const int lingitud);

void copiaPrimerafilaEnMatriz( const int fila, const int colum, int matriz[][colum] );


int charToInt( char caracter);
char enteroACaracter(int numero);

void quickSort( double array[], int inicio, int fin);

void inverso( const char * const ptrS );
void leeConEspacios( char cadena[] );

void separaParabrasEnArray( char *array[], char enunciado[], char separador[]);
