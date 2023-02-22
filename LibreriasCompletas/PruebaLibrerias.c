#include "headerDocumentado.h"

char *extraerColaListaString(ListaString *listaObjetivo);
int main()
{
    ListaString Prueba = {NULL, NULL, 0};
    // int i;
    char cadena[16];
    for (int i = 0; i < 12; i++)
    {
        insertarStringEnCola(cadenaAleatoriaLongAleatoria(), &Prueba);
    }
    imprimeDesdeLaCabezaListaString(&Prueba);
    extraerColaListaString(&Prueba);
    imprimeDesdeLaCabezaListaString(&Prueba);
    imprimeDesdeLaColaListaString(&Prueba);
    return 0;
}

/**
 * @brief Extrae el ultimo elemento de la cola de la lista String
 * @param listaObjetivo
 * @return char*
 */
char *extraerColaListaString(ListaString *listaObjetivo)
{
    NodoString *ptrNodoObjetivo;
    char *contenedor = malloc(sizeof(char *)); // contenedor Auxiliar
    if (!listaStringEstaVacia(*listaObjetivo))
    {
        ptrNodoObjetivo = listaObjetivo->cola; // direccion de memoria del nodo a extraer

        contenedor = ptrNodoObjetivo->dato;          // asigna el dato de la cola al registro contenedor
        listaObjetivo->cola = ptrNodoObjetivo->ante; // asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida

        listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
        if (listaObjetivo->cantidadElem == 0)
            listaObjetivo->cabeza = NULL;
        else
            listaObjetivo->cola->sig = NULL; // elimina la direccion de memoria del apuntador siguiente de la cola actual

        free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    }
    else
        printf("\nLa lista esta vacia\n");

    return contenedor;
}
