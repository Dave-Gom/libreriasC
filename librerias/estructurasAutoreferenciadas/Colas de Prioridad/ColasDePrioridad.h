#include"./../ListasEnlazadas/listas.h"

typedef struct REGISTROPRIORIDAD
{
  Nodo *nodo;
  int prioridad;
}RegistroDePrioridad;

typedef struct COLAPRIORIDAD
{
  int CantPrioridades; //cantidad de priridades en la cola
  Cola Prioridades[4]; //array de Colas
}ColaDePrioridad; //tipo de dato personalizado "Cola"

void insertarDatosEnColaDePriridad(ColaDePrioridad *colaDePrioridad);
ColaDePrioridad CreaColaPrioridad(int prioridades);
void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, RegistroDePrioridad *AInsertar);
void insertarDatosEnColaDePriridad(ColaDePrioridad *ColaDePrioridadDePrueba);
void leerColaDePrioridades(ColaDePrioridad *ColaDePrioridadDePrueba);
void imprimirColaDePrioridad(ColaDePrioridad ColaDePrioridadDePrueba);
Registro DesencolaPrioridad(ColaDePrioridad *ColaDePrio);
void despliegaMenuColasDePrioridad();