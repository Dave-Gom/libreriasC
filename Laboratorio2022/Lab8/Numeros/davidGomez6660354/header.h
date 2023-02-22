/* Laboratorio 8 - Manejo de archivos */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *abreArchivo( char nombre[], char tipoApertura[]); //abre un archivo y le asigna el nombre recibido como argumento, si no puede abrirlo imprime un mensaje y retorna null
int tipoNumero( long );
int esPrimo( long );
