
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

/* Operaciones con arreglos */
int mayor(int arreglo[], const int longitud); // devuelve el mayor elemento del arreglo
int menor(int arreglo[], const int longitud); // devuelve el menor elemento del arreglo

void copia_arreglo(int origen[], int destino[], const int dim); // copia el arreglo del primer argumento en el arreglo del segundo argumento
void imprimeArreglo(int arreglo[], const int longitud);         // imprimie el arreglo
void iniciaArreglo(int arreglo[], const int lingitud);          // inicializa el arreglo con todos los valores en cero
void cargaVector(int arreglo[], const int lenght);              // asigna valores desde la entrada estandar al arreglo
int posMenor(const int arreglo[], const int longitud);          // develve la posicion del menor elemento del  menor elemento
int posMayor(const int arreglo[], const int longitud);          // develve la posicion del mayor elemento del  menor elemento
int esMonotona(int array[], int dim);
void digitosInt(int arreglo[], int valor);

/* Operaciones con matrices */
void iniciaMatriz(const int fila, const int colum, int matriz[][colum]);             // inicializa la matriz con todos los valores en cero
void cargaMatriz(const int fila, const int colum, int matriz[][colum]);              // asigna valores desde la entrada estandar al arreglo
void copiaPrimerafilaEnMatriz(const int fila, const int colum, int matriz[][colum]); // copia la primera fila de la matriz en las demas filas
int verificaCeros(int fila, int col, int matriz[][col]);
int esHermosa(int fila, int columna, int matriz[][columna]);
void sumaDeColumnas(int fila, int col, int matriz[][col], int sumaCol[]);
void sumaDeFilas(int fila, int col, int matriz[][col], int sumaFilas[]);
int sumaDiagonalPrincipal(int fila, int columna, int matriz[][columna]);
int sumaDiagonalSecundaria(int fila, int columna, int matriz[][columna]);
void imprimeMatrizFormat(int filas, int columnas, int Matriz[][columnas]);
void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna]);

/* funciones de busqueda */

int busqueda_lineal(int arreglo[], const int longitud, int valorABuscar);
int busquedaBinaria(int arreglo[], int valBuscado, int inicio, int fin);
int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha);

/* Operaciones con caracters y cadenas */

int charToInt(char caracter);
char enteroACaracter(int numero);
void inverso(const char *const ptrS);
void leeConEspacios(char cadena[]);
void separaParabrasEnArray(char *array[], char enunciado[], char separador[]);
char getLetra(int val);
void vocales(char exp[]);
void primeraAparicion(char exp[], char p);

/* ordenamientos */
void ordIntecambio(int arreglo[], int longitud);
void ordSeleccion(int a[], int n);
void ordSeleccionRecusiva(int arreglo[], int longitud);
void burbuja_asc(int arreglo[], const int longitud);
void burbuja_des(int arreglo[], const int longitud);
void quickSort(double array[], int inicio, int fin);

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
void borraRegistro(Registro *);

/* Listas Enlazadas */

typedef struct NODO
{                // los nodos tendran un registro dentro para mayor
  Registro dato; // EL DATO PUEDE SER DE CUALQUIER TIPO
  struct NODO *sig;
  struct NODO *ante;
} Nodo; // define un alias para una estructura NODO

typedef struct LISTA
{
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
} Lista, Pila, Cola; // Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

/**
 * @brief Funciones de Listas
 *
 * @author Dave Gomez
 */

Nodo *creaNodo(Registro);                                      // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
int listaEstaVacia(Lista);                                     // retorna -1 si la lista esta vacia, 0 si no
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
} ColaDePrioridad;                       // tipo de dato personalizado "Cola"

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
} Archivo;

typedef struct REGISTRORARCHIVO
{
  unsigned int id;
  int estaEliminado; // esta eliminado valors, 0 registro en blanco, nunca escrito, 1 registro con datos, -1 registro dado de baja
  Registro Dato;
} RegistroArchivo;

RegistroArchivo creaRegistroArchivo();
Archivo *creaArchivo();
Archivo *creaArchivoBin(); // crea un archivo binario, si se especifica rb+ y el archivo no existe, primero lo crea y luego abre el archivo para actualizacion binaria
void guardaRegistroEnArchivo(Archivo *ptrArchivo, RegistroArchivo *aGuardar);
void nuevoRegistro(Archivo *prtF);
void eliminaRegistro(Archivo *ptrF);
void actualizaRegistro(Archivo *ptrF);
void informeTxt(Archivo *prtF);                                  // imprime un informe del archiv en txt
void guardaColaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos); // recibe una Lista y guarda los registros en un archivo desde la cabeza de la listavoid menuArchivos();
void menuArchivos();
void optenerCantidadElementos(Archivo *ptrArchivo);