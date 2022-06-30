#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


/**
 * @brief Definicion de estructuras
 * 
 * @author Dave Gomez
 */
typedef struct REGISTRO //registro de archivos
{
  /* Aqui deben ir los Argumentos del registro */
  int valor;
/*   char nombre[60];
  double estadoDeCuenta; */

}Registro;

Registro creaRegistro();
void borraRegistro(Registro *);

