#include<stdio.h>
#include<stdlib.h>

typedef struct NODO{
  int dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Lista, Pila, Cola; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

int listaEstaVacia( Lista );
Nodo *creaNodo(int );
void insertarEnCola ( int dato, Lista*);
void imprimeDesdeLaCabeza( const Lista *);
void despliegaMenu();


int main(int argc, char const *argv[])
{
  Nodo primero = { 5, NULL, NULL};
  Lista ListaDePrueba = { NULL, NULL, 0};
  int opcion, valor;
  //Nodo elementos[12];/* no se puede declarar un arreglo vacio elementos[], no esta permitido */

  do
  {
    despliegaMenu();
    scanf("%d", &opcion);
    switch (opcion)
    {
    
      case 2:
        imprimeDesdeLaCabeza( &ListaDePrueba);
        break;
      case 1:
        printf("Insgrese Dato a Insertar = ");
        scanf("%d", &valor);
        insertarEnCola(valor, &ListaDePrueba);
        break;
      default:
        printf("Opcion Invalida. Favor Reinsertar!\n");
        break;
    }
  } while (opcion != 3);
  
  system("pause");
  return 0;
}

int listaEstaVacia( Lista ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
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

void imprimeDesdeLaCabeza( const Lista *listaObjetivo){ //imprime una lista desde la cabeza (tambien valido para una Cola)
  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    printf("%d -> ", ptrNodoObjetivo->dato);
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
  printf("NULL\n");
}

void despliegaMenu(){ // Operaciones basicas con Listas
  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Lista\n");
  printf("2 - Imprimir la Lista\n");
  printf("3 - Salir\n");
  printf("Su Opcion = ");

}
