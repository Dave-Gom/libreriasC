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


int main(int argc, char const *argv[])
{
  int i = 0, banderaParentesis = 0, banderaCorchete = 0, banderaLlaves = 0;
  char cadena[15];
  scanf("%s", cadena);


  Pila parentesis = {NULL, NULL, 0};

  banderaParentesis = simbolosValanceados(cadena, parentesis, '(', ')');
  banderaCorchete = simbolosValanceados(cadena, parentesis, '[', ']');
  banderaLlaves = simbolosValanceados(cadena, parentesis, '{', '}');


  if( banderaCorchete == 1 || banderaLlaves == 1 || banderaParentesis == 1){
    printf("NO\n");
  }
  else
    printf("SI\n");
  

  return 0;
}

int simbolosValanceados( char cadena[], Pila pilaContenedora, char simboloApertura, char simboloCierre){
  int bandera = 0, i= 0;
  while (cadena[i] != '\0' && cadena[i] != '\n')
  {
    if(cadena[i] == simboloApertura){
      insertarEnCabeza( cadena[i], &pilaContenedora);// si encuentra apertura de parentesis agrega a la pila
    }
    if(cadena[i] == simboloCierre){
      if(pilaContenedora.cantidadElem == 0){ // si encuentra una cierre de parentesis y la pila esta vacia retorna bandera 1 
        bandera = 1;
        break;
      }
      else {
        extraerCabeza( &pilaContenedora);

      }
    }
    i++;
  }

  if(pilaContenedora.cantidadElem != 0){
    bandera = 1;
  }

  return bandera;
}

Nodo *creaNodo( char dato){ // crea un nodo de una lista y devuelve su direccion en memoria
  Nodo *nuevoNodo = malloc( sizeof ( Nodo));
  if( nuevoNodo != NULL){
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ante = NULL;
    return nuevoNodo;
  }
  else
  {
    printf("No de pudo crear el Nuevo Nodo, Memoria insuficiente");
    return NULL;
  }

}

void insertarEnCabeza( char dato, Pila *listaDestino){ //Inserta Por la cabeza de la lista (tambien valido para pila)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
   /* obs: para una pila, si inserto desde la cabeza tambien debo leer desde la cabeza */
  Nodo *ptrNuevoNodo = creaNodo(dato);

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else{ // si la lista no esta vacia
      ptrNuevoNodo->sig = listaDestino->cabeza; //asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
      listaDestino->cabeza->ante = ptrNuevoNodo; //asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
      listaDestino->cabeza = ptrNuevoNodo; //asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
    }
  }
}


void extraerCabeza( Pila *listaObjetivo){ //no se necesita leer ni imprimir nada, simplemente saca  una apertura de parentesis de la pila
  
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  listaObjetivo->cabeza = ptrNodoObjetivo->sig;
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la pila
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cola = NULL;

}


int listaEstaVacia( Pila ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
}

void leeConEspacios( char cadena[] ){
  char c;
  int i = 0;
  while ( (c = getchar() ) != '\n' )
  {
    cadena[i++] = c;
  } 
  
}