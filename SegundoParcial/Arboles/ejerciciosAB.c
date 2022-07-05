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
void inOrdenArray(NodoArbol *, int arreglo[], int *);

int enteroAleatorioEntre(int limiteInf, int limiteSup);
void arrayAleatorio(int arreglo[], int longitud, int LimiteInf, int LimiteSup);
void despliegaMenu();
void ordenaArray();
void imprimeArreglo(int arreglo[], const int longitud);

int main(int argc, char const *argv[])
{

    int opcion;

    do
    {
        despliegaMenu();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            ordenaArray();
            break;
        case 2:
            break;

        default:
            printf("Opcion No valida\n");
            break;
        }
    } while (opcion != 2);

    return 0;
}

/**
 * @brief devuelve un numero aleatorio entre el limite inferior y el superior
 *
 * @param limiteInf
 * @param limiteSup
 * @return int
 */
int enteroAleatorioEntre(int limiteInf, int limiteSup)
{

    int valor = limiteInf + (rand() % (limiteSup - limiteInf));
    return valor;
}

/**
 * @brief Inicializa una matriz con valores aleatorios del 0 a valor especificado
 *
 * @param limiteInf
 * @param limiteSup
 * @return int
 */
void arrayAleatorio(int arreglo[], int longitud, int LimiteInf, int LimiteSup)
{
    /* incluir stdlib para usar rand() y time() */
    int i, j;
    srand(time(NULL));
    for (i = 0; i < longitud; i++)
    {
        arreglo[i] = enteroAleatorioEntre(LimiteInf, LimiteSup);
    }
}

/**
 * @brief Despliega el menu
 *
 */
void despliegaMenu()
{
    printf("\nMENU\n");
    printf("Ingrese Su Opcion:  \n");
    printf("1 - Generar y ordenar un Array con HeapSort  \n");
    printf("2 - Salir:  \n");
    printf("Opcion: ");
}

void ordenaArray()
{
    Arbol arbolExamen = {NULL};             // inicializa el arbol
    int dimension, limiteInf, limiteSup, i; // iterador
    printf("Ingrese La dimension del arreglo: ");
    scanf("%d", &dimension);
    printf("Ingrese el valor minimo del arreglo: ");
    scanf("%d", &limiteInf);
    printf("Ingrese  el valor maximo del arreglo: ");
    scanf("%d", &limiteSup);

    int arregloAleatorio[dimension];
    int arregloOrdenado[dimension];
    arrayAleatorio(arregloAleatorio, dimension, limiteInf, limiteSup);
    imprimeArreglo(arregloAleatorio, dimension);

    for (i = 0; i < dimension; i++)
    {
        cargaArbol(&arbolExamen, arregloAleatorio[i]);
    }
    i = 0;
    printf("Indice \n");
    inOrden(arbolExamen.Raiz, arregloOrdenado, &i);

    imprimeArreglo(arregloOrdenado, dimension);
}

/**
 * @brief Imprimie un arreglo unidimensional separado por tabulaciones
 *
 * @param arreglo Arreglo a ser impreso
 * @param longitud Dimension del arreglo
 */
void imprimeArreglo(int arreglo[], const int longitud)
{
    int i;
    printf("\n");

    for (i = 0; i < longitud; i++)
    {
        printf(" %d\t", arreglo[i]);
    }
    printf("\n");
}

/**
 * @brief Crea un Nodo De arbol y le saigna el valor recibido
 *
 * @param dato
 * @return NodoArbol*
 */
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

/**
 * @brief Inserta Nodo En arbol
 *
 * @param SubArbol
 * @param ptrNuvoNodo
 */
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

/**
 * @brief Carga El Arbol en el arreglo
 *
 * @param ptrNodoArbol
 */
void inOrdenArray(NodoArbol *ptrNodoArbol, int arreglo[], int *dimension)
{
    int bandera = 0;
    if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
    {
        inOrden(ptrNodoArbol->izq, arreglo, dimension);
        arreglo[*dimension] = ptrNodoArbol->dato;
        *dimension = *dimension + 1;
        inOrden(ptrNodoArbol->der, arreglo, dimension);
    }
}

/**
 * @brief carga el arbol con el Valor recibido
 *
 * @param ArbolObjetivo
 * @param valor
 */
void cargaArbol(Arbol *ArbolObjetivo, int valor)
{
    NodoArbol *ptrNuevoNodo = creaNodoArbol(valor);
    insertaNodoEnArbol(&ArbolObjetivo->Raiz, ptrNuevoNodo);
}