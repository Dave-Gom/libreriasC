#include<stdlib.h>
#include<string.h>
#include<ctype.h>


/* Operaciones con caracters y cadenas */
int charToInt( char caracter);
char enteroACaracter(int numero);
void inverso( const char * const ptrS );
void leeConEspacios( char cadena[] );
void separaParabrasEnArray( char *array[], char enunciado[], char separador[]);
char getLetra(int val);
void vocales( char exp[]);
void primeraAparicion ( char exp[], char p) ;