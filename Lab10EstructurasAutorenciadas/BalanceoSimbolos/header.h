#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct NODO{ //los nodos tendran un registro dentro para mayor 
  char dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
} Pila; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

int listaEstaVacia( Pila ListaVal);
Nodo *creaNodo( char dato);
void insertarEnCabeza( char dato, Pila *listaDestino);
void extraerCabeza( Pila *listaObjetivo);
void leeConEspacios( char cadena[] );
int simbolosValanceados( char cadena[], Pila pilaContenedora, char simbolo,  char simboloCierre);