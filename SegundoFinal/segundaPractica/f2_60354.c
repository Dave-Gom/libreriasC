#include "header.h"

typedef struct REGISTROVEHICULO // registro de archivos
{
    char chapa[10];
    char marca[20];
    char modelo[20];
    Lista titulares;

} RegistroVehiculo;

typedef struct NODOVehiculo
{                          // los nodos tendran un registro dentro para mayor
    RegistroVehiculo dato; // EL DATO PUEDE SER DE CUALQUIER TIPO
    struct NODOVehiculo *sig;
    struct NODOVehiculo *ante;
} NodoVehiculo;

typedef struct LISTAV
{
    NodoVehiculo *cabeza;
    NodoVehiculo *cola;
    int cantidadElem;
} ListaVehiculos;

void menu();
RegistroVehiculo creaRegistroVehiculo();
void insertarEnColaVehiculos(ListaVehiculos *ACargar);
RegistroVehiculo extraerCabezaVehiculos(ListaVehiculos *listaObjetivo);
void insertarDatoEnColaVehiculos(RegistroVehiculo dato, ListaVehiculos *);
NodoVehiculo *creaNodoVehiculo(RegistroVehiculo dato);
void ingresarPropietario(ListaVehiculos *ACargar);
void imprimeListaVehiculos(ListaVehiculos *listaObjetivo);

int main(int argc, char const *argv[])
{

    ListaVehiculos RegistrosVehiculares = {NULL, NULL, 0};
    int opcion;
    menu();
    scanf("%d", &opcion);
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            insertarEnColaVehiculos(&RegistrosVehiculares);
            break;
        case 2:
            ingresarPropietario(&RegistrosVehiculares);
            break;
        case 3:
            imprimeListaVehiculos(&RegistrosVehiculares);
            break;
        default:
            break;
        }
        menu();
        scanf("%d", &opcion);
    }

    return 0;
}

void menu()
{
    printf("Que desea Hacer?\n");
    printf("Opciones:\n");
    printf("1 - Cargar un Vehiculo\n");
    printf("2 - Cargar una Tranferencia\n");
    printf("3 - Imprimir los vehiculos\n");
    printf("4 - Imprimir los Titulares de un vehiculo\n");
    printf("5 - Informe en txt\n");
    printf("6 - Salir\n");
    printf("Su Opcion = ");
}

void insertarEnColaVehiculos(ListaVehiculos *ACargar)
{
    RegistroVehiculo RegistroAInsertar = creaRegistroVehiculo();
    insertarDatoEnColaVehiculos(RegistroAInsertar, ACargar);
}

RegistroVehiculo creaRegistroVehiculo()
{ // crea un registro nuevo, lee sus valor y devuelve una copia

    printf("\n** Crea un Registro **\n");
    RegistroVehiculo *ptrNuevoRegistro = malloc(sizeof(Registro)); // libera espacio en memoria para el nuevo registro
    printf("Ingresa la chapa del vehiculo: ");
    scanf("%s", ptrNuevoRegistro->chapa);
    printf("Ingresa la marca del vehiculo: ");
    scanf("%s", ptrNuevoRegistro->marca);
    printf("Ingresa el modelo del vehiculo: ");
    scanf("%s", ptrNuevoRegistro->modelo);
    printf("Ingrese El titular: \n");
    insertarEnCola(&ptrNuevoRegistro->titulares);
    return *ptrNuevoRegistro; // retorna una copia del registro creado
}

void insertarDatoEnColaVehiculos(RegistroVehiculo dato, ListaVehiculos *listaDestino)
{
    /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
    NodoVehiculo *ptrNuevoNodo = creaNodoVehiculo(dato);

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaDestino->cabeza != NULL)
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                            // si la lista no esta vacia
            ptrNuevoNodo->ante = listaDestino->cola; // asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
            listaDestino->cola->sig = ptrNuevoNodo;  // asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
            listaDestino->cola = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief Crea un nodo de una lista y devuelve su direccion en memoria
 *
 * @param dato Dato a ser insertado en el Nodo, dependiendo del tipo de nodo puede ser un Registro, entero, cadena, o cualquier tipo de dato
 * @return Nodo*
 *
 * @author Dave Gomez
 */

NodoVehiculo *creaNodoVehiculo(RegistroVehiculo dato)
{
    NodoVehiculo *nuevoNodo = malloc(sizeof(NodoVehiculo));
    if (nuevoNodo != NULL)
    {
        nuevoNodo->dato = dato;
        nuevoNodo->sig = NULL;
        nuevoNodo->ante = NULL;
        printf("\nRegistro Creado Exitosamente");
        return nuevoNodo;
    }
    else
    {
        printf("No de pudo crear el Nuevo Nodo, Memoria insuficiente");
        return NULL;
    }
}

void ingresarPropietario(ListaVehiculos *listaObjetivo)
{

    char chapa[30];
    printf("Ingrese numero de chapa del vechiculo: %s", chapa);
    NodoVehiculo *ptrNodoObjetivo = listaObjetivo->cabeza;
    int encontrado = 5;
    encontrado = strcmp(ptrNodoObjetivo->dato.chapa, chapa);
    while (ptrNodoObjetivo != NULL || encontrado != 0)
    {
        ptrNodoObjetivo = ptrNodoObjetivo->sig;
        encontrado = strcmp(ptrNodoObjetivo->dato.chapa, chapa);
    }

    if (encontrado == 0)
    {
        insertarEnCabeza(&(ptrNodoObjetivo->dato).titulares);
    }
    else
        printf("NO SE ENCONTRO aunto con la chapa %s", chapa);
}

void imprimeListaVehiculos(ListaVehiculos *listaObjetivo)
{
    printf("\nLa lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    NodoVehiculo *ptrNodoObjetivo = listaObjetivo->cabeza;
    while (ptrNodoObjetivo != NULL)
    {
        printf("Chapa: %s, marca: %s, Modelo: %s", ptrNodoObjetivo->dato.chapa, ptrNodoObjetivo->dato.marca, ptrNodoObjetivo->dato.modelo);
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->sig;
    }
    printf("NULL\n");
}