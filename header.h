#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

/* funciones para testeo */
int enteroAleatorio(int limite);//devuelve un numero entero aleatorio menor entre uno y el limite
int enteroAleatorioEntre(int limiteInf, int limiteSup);//devuelve un numero aleatorio entre el limite inferior y el superior

float flotanteAleatorio();//devuelve un numero flotante aleatorio
char caracterAleatorio(); // devuelve un caracter aleatorio 
void cadenaAleatoria( char cadena[], int longitud); //agrega varacteres aleatorios a la cadena
char *cadenaAleatoriaLongAleatoria(); //devuelve el apuntador a una cadena de longitud aleatori

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
int hayCerosEnMatriz(int fila, int col, int matriz[][col]);
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
void burbujaAsc( int arreglo[], const int longitud);
void burbuja_des( int arreglo[], const int longitud);
void quickSort( double array[], int inicio, int fin);

/* funciones de busqueda */
int busquedaLineal(  int arreglo[], const int longitud, int valorABuscar);
int busquedaBinaria( int arreglo[], int valBuscado, int inicio, int fin);

/* Estructuras de datos */

typedef struct registroArchivo //registro de archivos
{
  int id;//Por convencion mia y de las db en general todos lor registros llevaran una id con Primary key
  /* Aqui deben ir los Argumentos del registro */
  int numeroCuenta;
  char nombre[60];
  double estadoDeCuenta;

}Registro;

typedef struct NODO{ //los nodos tendran un registro dentro para mayor 
  Registro dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Lista, Pila, Cola; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

int listaEstaVacia( Lista ); //retorna -1 si la lista esta vacia, 0 si no
Nodo *creaNodo(Registro ); // crea un nuevo nodo, le asigna el dato que recibe de parametro y devuelve su ubicacion en memoria
void insertarEnCola ( Registro dato, Lista*);//Inserta Por la cola de la lista (tabien valido para Colas)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
void imprimeDesdeLaCabeza( const Lista *);//imprime una lista desde la cabeza (tambien valido para una Cola)
void imprimeDesdeLaCola( const Lista *);//imprime una lista desde la cola (tambien valido para una Pila)
void insertarEnCabeza( Registro dato, Lista *listaDestino);//Inserta Por la cabeza de la lista (tabien valido para pilas)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
void despliegaMenu();//despliega menu de opciones para listas
void imprimeRegistro(Registro datos);//imprime el registro que se le pasa
/* archivos */
/* Info
  r     Abre un archivo para lectura.
  w     Crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.
  a     Agrega; abre o crea un archivo para escritura al final del archivo.
  r+    Abre un archivo para actualización (lectura y escritura).
  w+    Crea un archivo para actualización. Si el archivo ya existe, descarta el contenido actual.
  a+    Agrega; abre o crea un archivo para actualización; la escritura se hace al final del archivo.
  rb    Abre un archivo para lectura en modo binario.
  wb    Crea un archivo para escritura en modo binario. Si el archivo ya existe, descarta el contenido actual.
  ab    Agrega; abre o crea un archivo para escritura al final del archivo en modo binario.
  rb+   Abre un archivo para actualización (lectura y escritura) en modo binario.
  wb+   Crea un archivo para actualización en modo binario. Si el archivo ya existe, descarta el contenido
  actual.
  ab+   Agrega; abre o crea un archivo para actualización en modo binario; la escritura se hace al final del archivo.
 */


void actualizaRegistro( FILE *ptrF);
void nuevoRegistro( FILE *prtF);
void eliminaRegistro( FILE *ptrF);
FILE *creaArchivo();
void menuArchivos();
void leeConEspacios( char cadena[] );
Registro creaRegistro(); //crea un nuevo registro y devuelve el apuntador a este
void informeTxt( FILE *prtF);//imprime un informe del archiv en txt
Registro creaRegistroAleatorio();// crea un registro nuevo, lee sus valor y devuelve una copia
void cargaRegistrosAleatoriosEnArchivo( FILE *); //carga con valores de prueba un archivo
FILE *creaArchivoBin(); //crea un archivo binario, si se especifica rb+ y el archivo no existe, primero lo crea y luego abre el archivo para actualizacion binaria
void guardaColaEnArchivo(FILE *ptrArchivo, Lista ListaDatos);//recibe una Lista y guarda los registros en un archivo desde la cabeza de la lista




Registro creaRegistroAleatorio();// crea un registro nuevo, lee sus valor y devuelve una copia