#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

/* Funciones de Lab */
int resta_errad(int n);
int is_beautifull_year(int anio);
int calc_pasos(int dist);
void imprimeCamino( int fila, int col, int a[][col]);
int agendador(int arreglo1[], const int dim, const int dias);
int sube_escalera( int n );

/* Operaciones con arreglos */
int mayor( int arreglo[], const int longitud);//devuelve el mayor elemento del arreglo
int menor( int arreglo[], const int longitud);//devuelve el menor elemento del arreglo
void copia_arreglo( int origen[], int destino[], const int dim);//copia el arreglo del primer argumento en el arreglo del segundo argumento
void imprimeArreglo( int arreglo[], const int longitud);// imprimie el arreglo
void iniciaArreglo( int arreglo[], const int lingitud);//inicializa el arreglo con todos los valores en cero
void arrayAleatorio( int arreglo[], int longitud, int valorLimite);//asigna numeros aleatorios del cero hasta el valor del tercer argumento al arreglo
void cargaVector( int arreglo[], const int lenght);//asigna valores desde la entrada estandar al arreglo
int posMenor( const int arreglo[], const int longitud);//develve la posicion del menor elemento del  menor elemento

/* Operaciones con matrices */
void iniciaMatriz( const int fila, const int colum, int matriz[][colum] );//inicializa la matriz con todos los valores en cero
void cargaMatriz( const int fila, const int colum, int matriz[][colum] );//asigna valores desde la entrada estandar al arreglo
void copiaPrimerafilaEnMatriz( const int fila, const int colum, int matriz[][colum] );//copia la primera fila de la matriz en las demas filas
void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite);//asigna numeros aleatorios del cero hasta el valor del tercer argumento a la matriz
int verificaCeros(int fila, int col, int matriz[][col]);
int esHermosa( int fila, int columna, int matriz[][columna]) ;
void sumaDeColumnas(int fila, int col , int matriz[][col], int sumaCol[]);
void sumaDeFilas(int fila, int col , int matriz[][col], int sumaFilas[]);
int sumaDiagonalPrincipal(int fila, int columna, int matriz[][columna]);
int sumaDiagonalSecundaria(int fila, int columna, int matriz[][columna]);
void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]);

/* Operaciones con caracters y cadenas */
void digitosInt( int arreglo[], int valor);
int charToInt( char caracter);
char enteroACaracter(int numero);
void inverso( const char * const ptrS );
void leeConEspacios( char cadena[] );
void separaParabrasEnArray( char *array[], char enunciado[], char separador[]);
char getLetra(int val);
void vocales( char exp[]);
void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna]);
void primeraAparicion ( char exp[], char p) ;


/* ordenamientos */
void ordIntecambio( int arreglo[], int longitud);
int posMenor( const int arreglo[], const int longitud);
void ordSeleccionRecusiva( int arreglo[], int longitud);
void ordSeleccion( int a[], int n);
void burbuja_asc( int arreglo[], const int longitud);
void burbuja_des( int arreglo[], const int longitud);
void quickSort( double array[], int inicio, int fin);

/* funciones de busqueda */
int busqueda_lineal(  int arreglo[], const int longitud, int valorABuscar);
int busquedaBinaria( int arreglo[], int valBuscado, int inicio, int fin);

/* Estructuras de datos */

typedef struct NODO{
  int dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Lista, Pila, Cola; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

int listaEstaVacia( Lista ); //retorna -1 si la lista esta vacia, 0 si no
Nodo *creaNodo(int ); // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
void insertarEnCola ( int dato, Lista*);//Inserta Por la cola de la lista (tabien valido para Colas)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
void imprimeDesdeLaCabeza( const Lista *);//imprime una lista desde la cabeza (tambien valido para una Cola)
void despliegaMenu();//despliega menu de opciones para listas
