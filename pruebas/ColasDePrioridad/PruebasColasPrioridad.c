#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct REGISTRO
{
  int Dato;
  int prioridad;
}Registro;


typedef struct NODO{ //los nodos tendran un registro dentro para mayor 
  Registro dato;

  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO


typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Cola; //definimos la cola

typedef struct COLAPRIORIDAD
{
  Cola Prioridades[4]; //array de Colas
  int CantPrioridades; //cantidad de priridades en la cola
}ColaDePrioridad; //tipo de dato personalizado "Cola"

ColaDePrioridad CreaColaPrioridad(int prioridades);
void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, Nodo *AInsertar);
void insertarDatosEnColaDePriridad(ColaDePrioridad *ColaDePrioridadDePrueba);
void leerColaDePrioridads(ColaDePrioridad *ColaDePrioridadDePrueba);
void imprimirColaDePrioridad(ColaDePrioridad ColaDePrioridadDePrueba);
Nodo *creaNodo( Registro dato);
void despliegaMenu();
void insertarEnCola( Nodo *ptrNuevoNodo, Cola *listaDestino);
int listaEstaVacia( Cola ListaVal);
Registro extraerCabeza( Cola *listaObjetivo);
void imprimeDesdeLaCabeza( const Cola *listaObjetivo);

int main(int argc, char const *argv[])
{
  int cantidadPrioridades = 4;
  ColaDePrioridad ColaDePrioridadDePrueba = CreaColaPrioridad(cantidadPrioridades);
  int opcion;
  despliegaMenu();
  scanf("%d", &opcion);
  while ( opcion != 4){
    switch (opcion)
    {
    case 1:
      insertarDatosEnColaDePriridad(&ColaDePrioridadDePrueba);
      break;
    
    case 2:
      leerColaDePrioridads(&ColaDePrioridadDePrueba);
      break;
    case 3:
      imprimirColaDePrioridad(ColaDePrioridadDePrueba);
    
    default:
      break;
    }
    despliegaMenu();
    scanf("%d", &opcion);
  }
  
  return 0;
}

ColaDePrioridad CreaColaPrioridad(int cantidadDePrioridades)
{
  ColaDePrioridad NuevaCola; //Cola A ser retornada

  int i; //iterador
  for ( i = 0; i < cantidadDePrioridades; i++) //Inicializa las colas del Array Prioridades a colas Vacias
  {
    NuevaCola.Prioridades[i].cabeza = NULL;
    NuevaCola.Prioridades[i].cola = NULL;
    NuevaCola.Prioridades[i].cantidadElem = 0;

  }

  NuevaCola.CantPrioridades = cantidadDePrioridades; //Indica cuantas prioridades hay en la Cola
  return NuevaCola;
  
}

void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, Nodo *AInsertar)
{
  if( AInsertar->dato.prioridad < ColaPrioridad->CantPrioridades && AInsertar->dato.prioridad>=0){
    insertarEnCola(AInsertar, &ColaPrioridad->Prioridades[AInsertar->dato.prioridad]);
  }
  else
  {
    printf("Error! Prioridad fuera de Rango");
    
  }
  
}


void insertarEnCola( Nodo *ptrNuevoNodo, Cola *listaDestino){ //Inserta Por la cola de la lista (tabien valido para Colas)


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

int listaEstaVacia( Cola ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
}

Registro DesencolaPrioridad(ColaDePrioridad *ColaDePrio)
{
  //esta funcion no es aplicable a colas de prioridades vacias

  int i = 0;
  Registro dato; //contenedor auxiliar a ser retornado
  for ( i = 0; i < ColaDePrio->CantPrioridades; i++)
  {
    if(listaEstaVacia( ColaDePrio->Prioridades[i]))
      continue;
    
    dato = extraerCabeza(&ColaDePrio->Prioridades[i]);
    break; //extrae solamente el primer elemento de la primera cola no vacia que encuentra
  }

  return dato; 
  
}

Registro extraerCabeza( Cola *listaObjetivo){ 
  Nodo *ptrNodoObjetivo;
  Registro Dato; //contenedor Auxiliar
  ptrNodoObjetivo = listaObjetivo->cabeza;

  Dato = ptrNodoObjetivo->dato; 
  listaObjetivo->cabeza = ptrNodoObjetivo->sig;
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la lista
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cola = NULL;
  
  return Dato;

}

int ColaPrioridadVacia( ColaDePrioridad ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  int i; //iterador 
  int bandera = -1; //su valor determina si esta o no vacia: -1 para vacia, 0 para no vacia
  for ( i = 0; i < ListaVal.CantPrioridades; i++)
  {
    if(ListaVal.Prioridades[i].cabeza != NULL)
    {
      bandera = 0;
      break; //basta con que una de las colas no este vacia para que la cola de prioridades no este vacia
    }
  }
  

  return bandera;
}

Nodo *creaNodo( Registro dato){ // crea un nodo de una lista y devuelve su direccion en memoria
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

void insertarDatosEnColaDePriridad(ColaDePrioridad *colaDePrioridad){
  int D;
  int P;
  
  printf("\nDato:");
  scanf("%d", &D);
  printf("Prioridad:");
  scanf("%d", &P);

  Registro Datos;
  Datos.Dato = D;

  Datos.prioridad = P-1;

  Nodo *ptrNuevoNodo = creaNodo(Datos);

  insertarEnPrioridad(colaDePrioridad, ptrNuevoNodo);
}

void leerColaDePrioridads(ColaDePrioridad *colaDePrioridad){
  if( ColaPrioridadVacia(*colaDePrioridad) != -1){
    Registro aux = DesencolaPrioridad(colaDePrioridad);
    printf("El Prime Dato era: %d", aux.Dato); //aqui deban inr las operaciones requeridas para hacer con el dato de la cola de prioridad
  }
  else
  {
    printf("Error: La cola de priridad Esta Vacia\n");
  }
  
}

void imprimirColaDePrioridad(ColaDePrioridad colaDePrioridad){
  int i; //iterador
  printf("\nCola De prioridad de %d Prioridades\n", colaDePrioridad.CantPrioridades);
  for ( i = 0; i < colaDePrioridad.CantPrioridades; i++)
  {
    printf("\nPrioridad %d\n", i+1);
    imprimeDesdeLaCabeza(&colaDePrioridad.Prioridades[i]);
  }
  
}

void imprimeDesdeLaCabeza( const Cola *listaObjetivo){ //imprime una lista desde la cabeza (tambien valido para una Cola)
  printf("La Cola cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    printf("%d",ptrNodoObjetivo->dato.Dato); //imprimie el registro asociado al nodo
    printf(" -> ");
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
  printf("NULL\n");
}

void despliegaMenu(){ // Operaciones basicas con Listas
  printf("\n");
  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Cola\n");
  printf("2 - Leer Dato desde la Cola\n");
  printf("3 - Imprimir la Cola de prioridades\n");
  printf("4 - Salir\n");
  printf("Su Opcion = ");

} */
