#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct NODO{ //los nodos tendran un registro dentro para mayor 
  int dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
} Lista; //Una lista doblemente enlazada puede ser una Lista o una Cola dependiendo de como se carguen y lean los Nodos

Nodo *creaNodo( int dato);
void insertarEnCabeza( int dato, Lista *listaDestino);
void insertarEnCola( int dato, Lista *listaDestino);
int listaEstaVacia( Lista ListaVal);
Nodo *dirMayor(int Dato, Lista *listaDestino);
void insertaAntesDe( Nodo *nodoMayor, int dato);
void insertaEnOrden( int dato, Lista *listaDestino);
void imprimeDesdeLaCabeza( const Lista *listaObjetivo);