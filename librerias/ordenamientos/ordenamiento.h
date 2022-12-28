#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"./../arreglos/arreglos.h"

/* ordenamientos */
void ordIntecambio( int arreglo[], int longitud);
void ordSeleccion( int a[], int n);
void ordSeleccionRecusiva( int arreglo[], int longitud);
void burbujaAsc( int arreglo[], const int longitud);
void burbuja_des( int arreglo[], const int longitud);
void quickSort( double array[], int inicio, int fin);