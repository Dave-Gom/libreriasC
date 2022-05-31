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

int main(int argc, char const *argv[])
{
  int dato;
  Lista listaDeEnteros = { NULL, NULL, 0}; //inicializo la lista
  scanf("%d", &dato);
  while ( dato != -1)
  {
    insertaEnOrden(dato, &listaDeEnteros); //utimilzamos el ordenamiento por seleccion
    scanf("%d", &dato);
  } 

  imprimeDesdeLaCabeza(&listaDeEnteros);
}



Nodo *creaNodo( int dato){ // crea un nodo de una lista y devuelve su direccion en memoria
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

void insertarEnCola( int dato, Lista *listaDestino){ //Inserta Por la cola de la lista (tabien valido para Colas)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
  Nodo *ptrNuevoNodo = creaNodo(dato);

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else{ // si la lista no esta vacia
      ptrNuevoNodo->ante = listaDestino->cola; //asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
      listaDestino->cola->sig = ptrNuevoNodo; //asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
      listaDestino->cola = ptrNuevoNodo; //asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
    }
  }
}

void insertarEnCabeza( int dato, Lista *listaDestino){ //Inserta Por la cabeza de la lista (tambien valido para pila)
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

int listaEstaVacia( Lista ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
}



Nodo *dirMayor(int Dato, Lista *listaDestino){ //encuentra la direccion del primer nodo que contenga un dato mayor al valor actual
  Nodo *ptrNodoEvaluado = listaDestino->cabeza;
  while (ptrNodoEvaluado != NULL)
  {
    if(ptrNodoEvaluado->dato > Dato){
      return ptrNodoEvaluado;
    }
    else
      ptrNodoEvaluado = ptrNodoEvaluado->sig;
  }

  return NULL;
  
}


void insertaAntesDe( Nodo *nodoMayor, int dato){ //inserta en la lista, detras del nodo especificado
  
  Nodo *ptrNuevoNodo = creaNodo(dato);

  ptrNuevoNodo->sig = nodoMayor; //asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; //asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
  nodoMayor->ante->sig = ptrNuevoNodo;
  nodoMayor->ante = ptrNuevoNodo;

}

void insertaEnOrden( int dato, Lista *listaDestino){

  Nodo *ptrNuevoNodo = creaNodo(dato);

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else
    {
      Nodo *ptrNodoMayor = dirMayor(dato, listaDestino);
      if(ptrNodoMayor == listaDestino->cabeza){
        insertarEnCabeza(dato, listaDestino);
      }
      else
      {
        if (ptrNodoMayor != NULL)
        {
          insertaAntesDe(ptrNodoMayor , dato);
        }
        else
        {
          insertarEnCola(dato, listaDestino);
        }
        
      }
    }
  }
}

void imprimeDesdeLaCabeza( const Lista *listaObjetivo){ //imprime una lista desde la cabeza (tambien valido para una Cola)
  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    printf("%d ", ptrNodoObjetivo->dato);

    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }

}