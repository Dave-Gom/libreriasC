#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

/* Operaciones con arreglos */
int mayor(int arreglo[], const int longitud); // devuelve el mayor elemento del arreglo
int menor(int arreglo[], const int longitud); // devuelve el menor elemento del arreglo
int cantidadElementosDiferentes(int arreglo[], const int longitud);
int cantidadAparicionElemento(int, int arreglo[], int);
int sumaElementosArray(int arreglo[], int longitud);
void arraySimplificado(int arrayOrigen[], int dimensionOrigen, int arrayDestino[]);

void copiaArreglo(int origen[], int destino[], const int dim); // copia el arreglo del primer argumento en el arreglo del segundo argumento
void imprimeArreglo(int arreglo[], const int longitud);        // imprimie el arreglo
void iniciaArreglo(int arreglo[], const int lingitud);         // inicializa el arreglo con todos los valores en cero
void cargaVector(int arreglo[], const int lenght);             // asigna valores desde la entrada estandar al arreglo
int posMenor(const int arreglo[], const int longitud);         // develve la posicion del menor elemento del  menor elemento
int posMayor(const int arreglo[], const int longitud);         // develve la posicion del mayor elemento del  menor elemento
bool esMonotona(int array[], int dim);
void digitosInt(int arreglo[], int valor);

/* Operaciones con matrices */
void iniciaMatriz(const int fila, const int colum, int matriz[][colum]);                                         // inicializa la matriz con todos los valores en cero
void cargaMatriz(const int fila, const int colum, int matriz[][colum]);                                          // asigna valores desde la entrada estandar al arreglo
void copiaPrimerafilaEnMatriz(const int fila, const int colum, int matriz[][colum], bool introducePrimeraLinea); // copia la primera fila de la matriz en las demas filas
bool hayCerosEnMatriz(int fila, int col, int matriz[][col]);
bool esHermosa(int fila, int columna, int matriz[][columna]);
void sumaDeColumnas(int fila, int col, int matriz[][col], int sumaCol[]);
void sumaDeFilas(int fila, int col, int matriz[][col], int sumaFilas[]);
int sumaDiagonalPrincipal(int fila, int columna, int matriz[][columna]);
int sumaDiagonalSecundaria(int fila, int columna, int matriz[][columna]);
void imprimeMatrizFormat(int filas, int columnas, int Matriz[][columnas]);
void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna]);

/* funciones de busqueda */

int busquedaLineal(int arreglo[], const int longitud, int valorABuscar);
int busquedaBinaria(int arreglo[], int valBuscado, int inicio, int fin);
int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha);

/* Operaciones con caracters y cadenas */

int charToInt(char caracter);
char enteroACaracter(int numero);
void inverso(const char *const ptrS);
void leeConEspacios(char cadena[]);
int separaParabrasEnArray(char *array[], char enunciado[], char separador[]);
char getLetra(int val);
void vocales(char exp[]);
void primeraAparicion(char exp[], char p);
void leeFechaFormat(char cadena[]);
void enteroAString(int valor, char *cadena);
void imprimeArrayDePalabras(char *palabras[], int longitud);
int cantidadDePalabras(char palabras[], char separador[]);
void inicializaArrayPalabras(char *palabras[], int longitudArray);

/* ordenamientos */
void ordIntecambio(int arreglo[], int longitud);
void ordSeleccion(int a[], int n);
void ordSeleccionRecusiva(int arreglo[], int longitud);
void burbujaAsc(int arreglo[], const int longitud);
void burbuja_des(int arreglo[], const int longitud);
void quickSortD(double array[], int inicio, int fin);
void quickSortI(int array[], int inicio, int fin);
void mergeSortArrays(int array[], int longitud);
void mezclaEnOrden(int array1[], int dim1, int array2[], int dim2, int arrayDestino[]);

/* pruebas y generacion aleatoria */

void arrayAleatorio(int arreglo[], int longitud, int valorLimite);                  // asigna numeros aleatorios del cero hasta el valor del tercer argumento al arreglo
void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite); // asigna numeros aleatorios del cero hasta el valor del tercer argumento a la matriz

int enteroAleatorio(int limite);                        // devuelve un numero entero aleatorio menor entre uno y el limite
int enteroAleatorioEntre(int limiteInf, int limiteSup); // devuelve un numero aleatorio entre el limite inferior y el superior

float flotanteAleatorio();                         // devuelve un numero flotante aleatorio
char caracterAleatorio();                          // devuelve un caracter aleatorio
void cadenaAleatoria(char cadena[], int longitud); // agrega varacteres aleatorios a la cadena
char *cadenaAleatoriaLongAleatoria();              // devuelve el apuntador a una cadena de longitud aleatoria

/* Registros y estructuras */

typedef struct REGISTRO // registro de archivos
{
    /* Aqui deben ir los Argumentos del registro */
    int valor;
    /*   char nombre[60];
      double estadoDeCuenta; */
} Registro;

Registro creaRegistro();
void imprimeRegistro(Registro *);
void imprimeCopiaRegistro(Registro);
void borraRegistro(Registro *);

/* Listas Enlazadas */

typedef struct NODO // nodo de registro
{                   // los nodos tendran un registro dentro para mayor
    Registro dato;  // EL DATO PUEDE SER DE CUALQUIER TIPO
    struct NODO *sig;
    struct NODO *ante;
} Nodo; // define un alias para una estructura NODO

typedef struct NODOENTERO // nodo cuyo dato es un valor entero
{                         // los nodos tendran un registro dentro para mayor
    int dato;             // EL DATO PUEDE SER DE CUALQUIER TIPO
    struct NODOENTERO *sig;
    struct NODOENTERO *ante;
} NodoInt; // define un alias para una estructura NODO

typedef struct NODOCHAR // nodo nodo cuyo dato es un caracter
{                       // los nodos tendran un registro dentro para mayor
    char dato;          // EL DATO PUEDE SER DE CUALQUIER TIPO
    struct NODOCHAR *sig;
    struct NODOCHAR *ante;
} NodoChar; // define un alias para una estructura NODO

#define LONGITUDMAXSTRINGDENODO 100

typedef struct NODOSTRING // nodo cuyo dato es una cadena
{
    char *dato;
    struct NODOSTRING *sig;
    struct NODOSTRING *ante;
} NodoString; // define un alias para una estructura NODO

typedef struct LISTA
{
    Nodo *cabeza;
    Nodo *cola;
    int cantidadElem;
} Lista, Pila, Cola; // Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

#define INICIALIZALISTA \
    {                   \
        NULL, NULL, 0   \
    }

typedef struct LISTAINT
{
    NodoInt *cabeza;
    NodoInt *cola;
    int cantidadElem;
} ListaInt; // Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos. Eje de definicion: "malloc(sizeof(ListaInt));"

#define INICIALIZAPUNTEROLISTAINT malloc(sizeof(ListaInt))

typedef struct LISTACHAR
{
    NodoChar *cabeza;
    NodoChar *cola;
    int cantidadElem;
} ListaChar; // Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

#define INICIALIZAPUNTEROLISTAICHAR malloc(sizeof(ListaChar))
typedef struct LISTASTRING
{
    NodoString *cabeza;
    NodoString *cola;
    int cantidadElem;
} ListaString; // Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos
#define INICIALIZAPUNTEROLISTASTRING malloc(sizeof(ListaString))

/**
 * @brief Funciones de Listas
 *
 * @author Dave Gomez
 */

// listas de registros
Nodo *creaNodo(Registro);                                      // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
bool listaEstaVacia(Lista);                                    // retorna -1 si la lista esta vacia, 0 si no
void insertarDatoEnCabeza(Registro dato, Lista *listaDestino); // Inserta Por la cabeza de la lista (tabien valido para pilas)
void insertarDatoEnCola(Registro dato, Lista *);               // Inserta Por la cola de la lista (tabien valido para Colas)
void insertarEnCabeza(Lista *listaDestino);
void insertarEnCola(Lista *ACargar);
Registro extraerCabeza(Lista *listaObjetivo);
Registro extraerCola(Lista *listaObjetivo);
void imprimeDesdeLaCabeza(const Lista *); // imprime una lista desde la cabeza (tambien valido para una Cola)
void imprimeDesdeLaCola(const Lista *);   // imprime una lista desde la cola (tambien valido para una Pila)
Nodo *dirMayor(int Dato, Lista *listaDestino);
void insertaDatoAntesDe(Nodo *nodoMayor, Registro dato);
void insertaNodoAntesDe(Nodo *nodoMayor, Nodo *ptrNuevoNodo);
void insertaEnOrden(Registro dato, Lista *listaDestino); // Carga un Dato en una Lista Ya ordenada en Orden
void despliegaMenuListas();                              // despliega menu de opciones para listas

// listas int
NodoInt *creaNodoInt(int);                                  // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
bool listaIntEstaVacia(ListaInt);                           // retorna -1 si la lista esta vacia, 0 si no
void insertarIntEnCabeza(int dato, ListaInt *listaDestino); // Inserta Por la cabeza de la lista (tabien valido para pilas)
void insertarIntEnCola(int dato, ListaInt *);               // Inserta Por la cola de la lista (tabien valido para Colas)
void insertarEnCabezaListaInt(ListaInt *listaDestino);
void insertarEnColaListaInt(ListaInt *ACargar);
int extraerCabezaListaInt(ListaInt *listaObjetivo);
int extraerColaListaInt(ListaInt *listaObjetivo);
void imprimeDesdeLaCabezaListaInt(const ListaInt *); // imprime una lista desde la cabeza (tambien valido para una Cola)
void imprimeDesdeLaColaListaInt(const ListaInt *);   // imprime una lista desde la cola (tambien valido para una Pila)
NodoInt *dirMayorEnListaInt(int Dato, ListaInt *listaDestino);
void insertaDatoAntesDeEnListaInt(NodoInt *nodoMayor, int dato);
void insertaNodoAntesDeEnListaInt(NodoInt *nodoMayor, NodoInt *ptrNuevoNodo);
void insertaEnOrdenEnListaInt(int dato, ListaInt *listaDestino); // Carga un Dato en una Lista Ya ordenada en Orden
void despliegaMenuListasInt();

// listas de char
NodoChar *creaNodoChar(char);                                  // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
bool listaCharEstaVacia(ListaChar);                            // retorna -1 si la lista esta vacia, 0 si no
void insertarCharEnCabeza(char dato, ListaChar *listaDestino); // Inserta Por la cabeza de la lista (tabien valido para pilas)
void insertarCharEnCola(char dato, ListaChar *);               // Inserta Por la cola de la lista (tabien valido para Colas)
void insertarEnCabezaListaChar(ListaChar *listaDestino);
void insertarEnColaListaChar(ListaChar *ACargar);
int extraerCabezaListaChar(ListaChar *listaObjetivo);
int extraerColaListaChar(ListaChar *listaObjetivo);
void imprimeDesdeLaCabezaListaChar(const ListaChar *); // imprime una lista desde la cabeza (tambien valido para una Cola)
void imprimeDesdeLaColaListaChar(const ListaChar *);   // imprime una lista desde la cola (tambien valido para una Pila)
/* NodoInt *dirMayorEnListaChar(char Dato, ListaChar *listaDestino);
void insertaDatoAntesDeEnListaChar(NodoChar *nodoMayor, char dato);
void insertaNodoAntesDeEnListaChar(NodoChar *nodoMayor, NodoChar *ptrNuevoNodo);
void insertaEnOrdenEnListaChar(char dato, NodoChar *listaDestino); // Carga un Dato en una Lista Ya ordenada en Orden
void despliegaMenuListasChar(); */
int simbolosValanceados(char cadena[], ListaChar pilaContenedora, char simboloApertura, char simboloCierre);

// lista de strings(palabras)
NodoString *creaNodoString(char *string);
bool listaStringEstaVacia(ListaString);
void insertarStringEnCabeza(char dato[], ListaString *listaDestino); // Inserta Por la cabeza de la lista (tabien valido para pilas)
void insertarStringEnCola(char dato[], ListaString *);
void insertarEnCabezaListaString(ListaString *ACargar);
void insertarEnColaListaString(ListaString *ACargar);
void imprimeDesdeLaCabezaListaString(const ListaString *);
void imprimeDesdeLaColaListaString(const ListaString *listaObjetivo);
char *extraerCabezaListaString(ListaString *listaObjetivo);

/* funciones de Colas de prioridad */
#define CANTIDADPRIORIDADES 4
typedef struct REGISTROPRIORIDAD
{
    Nodo *nodo;
    int prioridad;
} RegistroDePrioridad;

typedef struct COLAPRIORIDAD
{
    int CantPrioridades;                   // cantidad de priridades en la cola
    Cola Prioridades[CANTIDADPRIORIDADES]; // array de Colas
} ColaDePrioridad;                         // tipo de dato personalizado "Cola"

void insertarDatosEnColaDePriridad(ColaDePrioridad *colaDePrioridad);
ColaDePrioridad CreaColaPrioridad(int prioridades);
void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, RegistroDePrioridad *AInsertar);
void insertarDatosEnColaDePriridad(ColaDePrioridad *ColaDePrioridadDePrueba);
void leerColaDePrioridades(ColaDePrioridad *ColaDePrioridadDePrueba);
void imprimirColaDePrioridad(ColaDePrioridad ColaDePrioridadDePrueba);
int ColaPrioridadVacia(ColaDePrioridad ListaVal);
Registro DesencolaPrioridad(ColaDePrioridad *ColaDePrio);
void despliegaMenuColasDePrioridad();

/**
 * @brief Funciones de Archivos
 *
 */

typedef struct ESTRUCTURAARCHIVOS
{
    int cantidadElementos;
    int registros;
    FILE *punteroArchivo;
} Archivo; // Para definir un puntero a este dato user "malloc(sizeof(Archivo));"

#define INICIALIZAPUNTEROARCHIVO malloc(sizeof(Archivo))

typedef struct REGISTRORARCHIVO
{
    unsigned int id;
    int estaEliminado; // esta eliminado valors, 0 registro en blanco, nunca escrito, 1 registro con datos, -1 registro dado de baja
    Registro Dato;
} RegistroArchivo;

// RegistroArchivo creaRegistroArchivo();
Archivo *creaArchivo();
void cierraArchivo(Archivo *ArchivoObjetivo);
Archivo *creaArchivoBin(); // crea un archivo binario, si se especifica rb+ y el archivo no existe, primero lo crea y luego abre el archivo para actualizacion binaria
void guardaRegistroEnArchivo(Archivo *ptrArchivo, RegistroArchivo *aGuardar);
void nuevoRegistro(Archivo *prtF);
void eliminaRegistro(Archivo *ptrF);
void actualizaRegistro(Archivo *ptrF);
Archivo *abreArchivoParaLectura();
void informeTxt(Archivo *prtF); // imprime un informe del archiv en txt
// void guardaColaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos); // recibe una Lista y guarda los registros en un archivo desde la cabeza de la listavoid menuArchivos();
void menuArchivos();
void optenerCantidadElementos(Archivo *ptrArchivo);
void despliegaMenuListasYArchivos();
void guardaListaIntEnArchivoNuevo(ListaInt *, Archivo *);
void guardaListaIntEnArchivoInforme(ListaInt *ListaOrigen);
void leeListaIntDeArchivoInforme(ListaInt *ListaInt, Archivo *Archivo);

/**
 * @brief Definiciones de funciones y estructuras para manejo de Arboles y monticulos
 *
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

NodoArbol *creaNodoArbol(int dato);
void cargaArbol(Arbol *ArbolObjetivo, int valor);
void despliegaMenuArboles();
void insertaNodoEnArbol(NodoArbol **, NodoArbol *);
void insertaNodoEnArbolConRep(NodoArbol **, NodoArbol *);

void inOrden(NodoArbol *ptrNodoArbol);
void preOrden(NodoArbol *);
void postOrden(NodoArbol *ptrNodoArbol);
void imprimirArbol(Arbol *);

void cargaArregloEnArbol(Arbol *ArbolObjetivo, int array[], int longitud);
void inOrdenArray(NodoArbol *ptrNodoArbol, int arreglo[], int direccion);

// Purebas con listas
ListaInt *creaListaIntAleatoria();
/**
 * @brief Funciones utilizadas en el laboratorio
 *
 */
// lab 2
int resta_errad(int n);
bool isBeautifullYear(int anio);
int calc_pasos(int dist);
// lab3
int sube_escalera(int n);
int cantidadHermososEnArreglo(int arreglo[], int);
int agendador(int arreglo1[], const int dim, const int dias);
// lab 4
void aniadeUno();

// Lab 5
void copiaArregloDeEnterosAString(int origen[], char destino[], const int dim);
void imprimeCamino(int fila, int col, int a[][col]);

// Lab 7
typedef struct rectangulo
{
    int lado1;
    int lado2;
} Rectangulo;

// define una estructura para un vector en 3 dimensiones
typedef struct vector
{
    int x;
    int y;
    int z;
} Vector;

void inicializaVector(Vector *V, int valorInicial);
void cargarVector(Vector *V);
int FuerzasEnEquilibrio(Vector Fuerzas[], int cantidad);

// lab 8
int esPrimo(long numero);
int tipoNumero(long numero);

// funciones extra
int esPalidromo(char cadena[]);