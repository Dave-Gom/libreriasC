#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
void inOrden(NodoArbol *ptrNodoArbol);
void preOrden(NodoArbol *);
void postOrden(NodoArbol *ptrNodoArbol);
void imprimirArbol(Arbol *);

int main(int argc, char const *argv[])
{
  int dato;
  Arbol MiPrimerArbol = {NULL}; // inicializa el arbol
  despliegaMenuArboles();
  scanf("%d", &dato);
  while (dato != 3)
  {
    switch (dato)
    {
    case 1:
      scanf("%d", &dato);
      cargaArbol(&MiPrimerArbol, dato);
      break;
    case 2:
      imprimirArbol(&MiPrimerArbol); // solo envia una copia del arbol
      break;
    default:
      break;
    }
    scanf("%d", &dato);
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
