#include"ColasDePrioridad.h"


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

/**
 * @brief 
 * 
 * @param ColaPrioridad 
 * @param AInsertar 
 */
void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, RegistroDePrioridad *AInsertar)
{
  if( AInsertar->prioridad < ColaPrioridad->CantPrioridades && AInsertar->prioridad >=0){
    insertarEnCola(AInsertar, &ColaPrioridad->Prioridades[AInsertar->prioridad]);
  }
  else
  {
    printf("Error! Prioridad fuera de Rango");
    
  }
  
}

void insertarDatosEnColaDePriridad(ColaDePrioridad *colaDePrioridad){

  int P;

  RegistroDePrioridad *DatosDePrioridad = malloc(sizeof(RegistroDePrioridad));
  DatosDePrioridad->nodo->dato = creaRegistro();
  printf("Prioridad:");
  scanf("%d", &P);

  DatosDePrioridad->prioridad = P-1;

  Nodo *ptrNuevoNodo = creaNodo(DatosDePrioridad->nodo->dato);
  DatosDePrioridad->nodo = ptrNuevoNodo;
  insertarEnPrioridad(colaDePrioridad, DatosDePrioridad);
}


void leerColaDePrioridades(ColaDePrioridad *colaDePrioridad){
  if( ColaPrioridadVacia(*colaDePrioridad) != -1){
    Registro aux = DesencolaPrioridad(colaDePrioridad);
    printf("El Prime Dato era: %d", aux.valor); //aqui deban inr las operaciones requeridas para hacer con el dato de la cola de prioridad
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


void despliegaMenuColasDePrioridad(){ 
  printf("\n");
  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Cola de prioridades\n");
  printf("2 - Leer Dato desde la Cola de prioridades\n");
  printf("3 - Imprimir la Cola de prioridades\n");
  printf("4 - Salir\n");
  printf("Su Opcion = ");

}
