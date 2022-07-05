#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#define MAXNODOS 1001 // VARIABLE GLOBAL CANTIDAD MAXIMA DE NODOS

/**
 * @brief
 *
 * @param estructura nodos para arbols
 * @param definicion estructura para representar diferentes arboles
 * @return int
 */

typedef struct NODOARBOL
{
  int dato; // puede ser un registro o de cualqier tipo
  struct NODOARBOL *izq;
  struct NODOARBOL *der;

} NodoArbol;

typedef struct ARBOL
{
  NodoArbol *Raiz;
} Arbol;

NodoArbol *creaNodoArbol();
void cargaArbol(Arbol *ArbolObjetivo, int valor);
void despliegaMenuArboles();
void insertaNodoEnArbol(NodoArbol **, NodoArbol *);
void insertaNodoEnArbolConRep(NodoArbol **, NodoArbol *);

void inOrden(NodoArbol *ptrNodoArbol);
void preOrden(NodoArbol *);
void postOrden(NodoArbol *ptrNodoArbol);
void imprimirArbol(Arbol *);

void cargaArregloEnArbol(Arbol *ArbolObjetivo, int array[], int longitud);
void arrayAleatorio(int arreglo[], int longitud, int valorLimite);
void imprimeArreglo(int arreglo[], const int longitud);
void inOrdenArray(NodoArbol *ptrNodoArbol, int arreglo[], int *dimension);

int main(int argc, char const *argv[])
{
  int opcion;
  int dim = 20;
  int indece = 0;
  Arbol MiPrimerArbol = {NULL}; // inicializa el arbol
  despliegaMenuArboles();
  scanf("%d", &opcion);
  int arreglo[dim];
  while (opcion != 3)
  {
    switch (opcion)
    {
    case 1:
      arrayAleatorio(arreglo, dim, 50);
      printf("\nEl arreglo es: \n");
      imprimeArreglo(arreglo, dim);
      cargaArregloEnArbol(&MiPrimerArbol, arreglo, dim);
      inOrdenArray(MiPrimerArbol.Raiz, arreglo, &indece);
      printf("\nEl arreglo ordenado es: \n");
      imprimeArreglo(arreglo, dim);
      break;
    case 2:
      imprimirArbol(&MiPrimerArbol); // solo envia una copia del arbol
      break;
    default:
      break;
    }
    despliegaMenuArboles();
    scanf("%d", &opcion);
  }

  return 0;
}

void despliegaMenuArboles()
{
  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar Nodo En arbol\n");
  printf("2 - Imprimir Arbol\n");
  printf("3 - Salir\n");
  printf("Su Opcion = ");
}

void cargaArbol(Arbol *ArbolObjetivo, int valor)
{
  NodoArbol *ptrNuevoNodo = creaNodoArbol(valor);
  insertaNodoEnArbol(&ArbolObjetivo->Raiz, ptrNuevoNodo);
}

NodoArbol *creaNodoArbol(int dato)
{
  NodoArbol *nuevoNodo = malloc(sizeof(NodoArbol)); // libera espacio en memora para el nuevo nodo
  if (nuevoNodo != NULL)
  {
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
  }
  else
  {
    printf("No de pudo crear el Nuevo Nodo, Memoria insuficiente");
    return NULL;
  }
}

void insertaNodoEnArbol(NodoArbol **SubArbol, NodoArbol *ptrNuvoNodo)
{
  if (*SubArbol == NULL) // si el arbol esta vacio
  {
    *SubArbol = ptrNuvoNodo;
  }
  else // si no esta vacio
  {
    if ((*SubArbol)->dato > ptrNuvoNodo->dato)
      insertaNodoEnArbol(&(*SubArbol)->izq, ptrNuvoNodo);

    if ((*SubArbol)->dato < ptrNuvoNodo->dato)
      insertaNodoEnArbol(&(*SubArbol)->der, ptrNuvoNodo);
  }
}

void inOrden(NodoArbol *ptrNodoArbol)
{
  if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
  {
    inOrden(ptrNodoArbol->izq);
    printf(" %d -", ptrNodoArbol->dato);
    inOrden(ptrNodoArbol->der);
  }
}

void preOrden(NodoArbol *ptrNodoArbol)
{
  if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
  {
    printf(" %d -", ptrNodoArbol->dato);
    preOrden(ptrNodoArbol->izq);
    preOrden(ptrNodoArbol->der);
  }
}

void postOrden(NodoArbol *ptrNodoArbol)
{
  if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
  {
    postOrden(ptrNodoArbol->der);
    printf(" %d -", ptrNodoArbol->dato);
    postOrden(ptrNodoArbol->izq);
  }
}

void imprimirArbol(Arbol *aImprimir)
{
  int opcion;
  if (aImprimir->Raiz == NULL)
  {
    printf("Arbol Vacio!\n");
  }
  else
  {
    printf("Como desea Visualizar el Arbol\n");
    printf("Ingrese su Opcion\n");
    printf("1- InOrden\n");
    printf("2- preOrden\n");
    printf("3- posOrden\n");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
      inOrden(aImprimir->Raiz);
      break;
    case 2:
      preOrden(aImprimir->Raiz);
      break;
    case 3:
      postOrden(aImprimir->Raiz);
      break;
    default:
      printf("Opcion Invalida");
      break;
    }
  }
}

void insertaNodoEnArbolConRep(NodoArbol **SubArbol, NodoArbol *ptrNuvoNodo)
{
  if (*SubArbol == NULL) // si el arbol esta vacio
  {
    *SubArbol = ptrNuvoNodo;
  }
  else // si no esta vacio
  {
    if ((*SubArbol)->dato > ptrNuvoNodo->dato)
      insertaNodoEnArbolConRep(&(*SubArbol)->izq, ptrNuvoNodo);

    if ((*SubArbol)->dato <= ptrNuvoNodo->dato)
      insertaNodoEnArbolConRep(&(*SubArbol)->der, ptrNuvoNodo);
  }
}

void arrayAleatorio(int arreglo[], int longitud, int valorLimite)
{
  /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* incluir stdlib para usar rand() y time() */
  int i, j;
  srand(time(NULL));
  for (i = 0; i < longitud; i++)
  {
    arreglo[i] = rand() % valorLimite;
  }
}

void cargaArregloEnArbol(Arbol *ArbolObjetivo, int array[], int longitud)
{
  int i;
  for (i = 0; i < longitud; i++)
  {
    insertaNodoEnArbolConRep(&ArbolObjetivo->Raiz, creaNodoArbol(array[i]));
  }
}

void imprimeArreglo(int arreglo[], const int longitud)
{
  int i;
  printf("[");
  for (i = 0; i < longitud; i++)
  {
    printf(" %d, ", arreglo[i]);
  }
  printf("]\n");
}

void inOrdenArray(NodoArbol *ptrNodoArbol, int arreglo[], int *dimension)
{
  int bandera = 0;
  if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
  {
    inOrdenArray(ptrNodoArbol->izq, arreglo, dimension);
    arreglo[*dimension] = ptrNodoArbol->dato;
    *dimension = *dimension + 1;
    inOrdenArray(ptrNodoArbol->der, arreglo, dimension);
  }
}