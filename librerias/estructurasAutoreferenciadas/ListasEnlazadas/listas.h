#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"./../Estructuras/estructuras.h"


typedef struct NODO{ //los nodos tendran un registro dentro para mayor 
  Registro dato; //EL DATO PUEDE SER DE CUALQUIER TIPO
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct LISTA{
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Lista, Pila, Cola; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos


/**
 * @brief Funciones de Listas
 * 
 * @author Dave Gomez
 */

Nodo *creaNodo(Registro ); // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
int listaEstaVacia( Lista ); //retorna -1 si la lista esta vacia, 0 si no
void insertarDatoEnCabeza( Registro dato, Lista *listaDestino);//Inserta Por la cabeza de la lista (tabien valido para pilas)
void insertarDatoEnCola ( Registro dato, Lista*);//Inserta Por la cola de la lista (tabien valido para Colas)
Registro extraerCabeza( Lista *listaObjetivo); 
Registro extraerCola( Cola *listaObjetivo);
void imprimeDesdeLaCabeza( const Lista *);//imprime una lista desde la cabeza (tambien valido para una Cola)
void imprimeDesdeLaCola( const Lista *);//imprime una lista desde la cola (tambien valido para una Pila)
void imprimeRegistro(Registro datos);//imprime el registro que se le pasa
Nodo *dirMayor(int Dato, Lista *listaDestino);
void insertaDatoAntesDe( Nodo *nodoMayor, Registro dato); 
void insertaNodoAntesDe( Nodo *nodoMayor, Nodo *ptrNuevoNodo);
void insertaEnOrden( Registro dato, Lista *listaDestino);//Carga un Dato en una Lista Ya ordenada en Orden 
void despliegaMenu();//despliega menu de opciones para listas
