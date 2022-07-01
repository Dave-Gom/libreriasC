#include "headerDocumentado.h"

/* FUNCIONES CON ARREGLOS UNIDIMENSIONALES */

/**
 * @brief Retorna el Mayor valor almacenado en un arreglo de enteros
 *
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int mayor(int arreglo[], const int longitud)
{

  int mayor, // valor mayor almacenado
      i;     // iterador
  for (i = 0; i < longitud; i++)
  {

    if (i == 0)
      mayor = arreglo[i];

    if (arreglo[i] > mayor)
      mayor = arreglo[i];
  }

  return mayor;
}

/**
 * @brief Retorna el menor valor almacenado en un arreglo de enteros
 *
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int menor(int arreglo[], const int longitud)
{

  int menor, // valor menor del array
      i;     // iterador
  for (i = 0; i < longitud; i++)
  {

    if (i == 0)
      menor = arreglo[i]; // asigna el primer elemento como menor

    if (arreglo[i] < menor) // si encueltra un elemento que sea menor
      menor = arreglo[i];   // asigna ese valor a la variable menor
  }

  return menor;
}

/**
 * @brief Copia los elemenots del arreglo origen al arreglo destino
 *
 * @param origen Arreglo del que se copiaran los elementos
 * @param destino Arreglo que recibira la copia de los elementos
 * @param dim dimension de ambos arreglos (Debe ser igual)
 */
void copia_arreglo(int origen[], int destino[], const int dim)
{
  int i; // iterador
  for (i = 0; i < dim; i++)
  {
    destino[i] = origen[i];
  }
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
  for (i = 0; i < longitud; i++)
  {
    printf(" %d\t", arreglo[i]);
  }
}

/**
 * @brief Asigna el valor inicial 0 a todas las posiciones del arreglo
 *
 * @param arreglo Arreglo a ser inicializado
 * @param lingitud Dimension del arreglo
 */
void iniciaArreglo(int arreglo[], const int lingitud)
{
  int i;
  for (i = 0; i < lingitud; i++)
  {
    arreglo[i] = 0;
  }
}

/**
 * @brief Carga valores en un arrego de dimension dada
 *
 * @param arreglo Arreglo a ser cargado
 * @param lenght Dimension del Areglo
 */
void cargaVector(int arreglo[], const int lenght)
{
  int iterador, valor;

  for (iterador = 0; iterador < lenght; iterador++)
  {
    scanf("%d", &valor);
    arreglo[iterador] = valor;
  }
}

/**
 * @brief Retorna la posicion del menor elemento de un arreglo
 *
 * @param arreglo Arreglo en el que se buscara
 * @param longitud Dimension del arreglo
 * @return int
 */
int posMenor(const int arreglo[], const int longitud)
{

  int menor, i;
  for (i = 0; i < longitud; i++)
  {

    if (i == 0)
      menor = i;

    if (arreglo[i] < arreglo[menor])
      menor = i;
  }
  return menor;
}

/**
 * @brief Retorna la posicion del mayor elemento de un arreglo
 *
 * @param arreglo Arreglo en el que se buscara
 * @param longitud Dimension del arreglo
 * @return int
 */
int posMayor(const int arreglo[], const int longitud)
{

  int mayor, i;
  for (i = 0; i < longitud; i++)
  {

    if (i == 0)
      mayor = i;

    if (arreglo[i] > arreglo[mayor])
      mayor = i;
  }
  return mayor;
}

/**
 * @brief Retorna 0 si un array es Monotono.
 *
 * Para que una array sea monotono, todos sus valores deben ser iguales
 *
 * @param array Arreglo a ser evaluado
 * @param dim Dimension del arreglo
 * @return int
 */
int esMonotona(int array[], int dim)
{
  int i;           // iterador
  int bandera = 0; // su valor determina si es o no monotona
  int primerValor; // primer valor del arreglo
  for (i = 0; i < dim; i++)
  {
    if (i == 0)
      primerValor = array[i];

    if (array[i] != primerValor)
    {
      bandera = -1;
      break;
    }
  }

  return bandera;
}

/* FUNCIONES CON ARREGLOS MULTIDIMINSIONALES (MATRICES) */

/**
 * @brief Asigna el valor inicial 0 a todas las posiciones de la matriz
 *
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser inicializada
 */
void iniciaMatriz(const int fila, const int colum, int matriz[][colum])
{
  int i, j;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < colum; j++)
      matriz[i][j] = 0;
  }
}

/**
 * @brief Carga valores en una matriz de dimensiones dadas
 *
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser cargada
 */
void cargaMatriz(const int fila, const int colum, int matriz[][colum])
{
  int i, j, aux;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < colum; j++)
    {
      scanf("%d", &aux);
      matriz[i][j] = aux;
    }
  }
}

/**
 * @brief Leer la primera fila de una matriz y asigna los mismos valore a las demas filas
 *
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser cargada
 */
void copiaPrimerafilaEnMatriz(const int fila, const int colum, int matriz[][colum])
{
  int i, j, aux;
  /* solicita que  si ingrese la primera fila del arreglo */
  for (j = 0; j < colum; j++)
  {
    scanf("%d", &aux);
    matriz[0][j] = aux;
  }

  /* copia los valores de la primera fila en el resto de la matriz */
  for (i = 1; i < fila; i++)
  {
    for (j = 0; j < colum; j++)
    {
      matriz[i][j] = matriz[0][j];
    }
  }
}

/**
 * @brief Verifica la existencia  de ceros en una matriz, si existe, devuelce -1 si no existen devuelce cero
 *
 * @param fila Cantidad de filas de la matriz
 * @param col Cantidad de comlumnas de la matriz
 * @param matriz Matriz a ser verificada
 * @return int
 */
int verificaCeros(int fila, int col, int matriz[][col])
{
  int i, j;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < col; j++)
    {
      if (matriz[i][j] == 0)
      {
        return -1;
      }
    }
  }

  return 0;
}

/**
 * @brief retorna cero si la matriz es hermosa, -1 en caso contario.
 *
 * Para que una matriz sea hermosa, la suma de todas sus filas, debe ser igual a la suma de todas sus columnas e igual a la suma de sus diagonales
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de Comlumnas
 * @param matriz Matriz a ser evaluada
 * @return int
 */
int esHermosa(int fila, int columna, int matriz[][columna])
{

  int isBeauty = 0; // presuponemos que es hermmosa
  if (fila != columna)
  {
    printf("No es Cuadrada\n");
    return 1; // para se hermosa debe ser cuadrada
  }
  int i;
  int sumadeFilas[fila];
  int sumadeColumnas[columna];

  sumaDeColumnas(fila, columna, matriz, sumadeColumnas);
  sumaDeFilas(fila, columna, matriz, sumadeFilas);

  if (sumadeColumnas[0] != sumadeFilas[0] || esMonotona(sumadeColumnas, fila) != 0 || esMonotona(sumadeColumnas, columna) != 0)
    return -1; // si la condicion de arriba se cumple sabemos que no es monotna y devolvemos -1

  if (sumaDiagonalPrincipal(fila, columna, matriz) != sumaDiagonalSecundaria(fila, columna, matriz))
  {
    return -1; // si la condicion de arriba se cumple sabemos que no es monotna y devolvemos -1
  }

  return isBeauty;
}

/* Funciones de busqueda */

/**
 * @brief Retorna la posicion de un valor dentro de un arreglo, -1 si el valor no se encuentra en el arreglo
 *
 * @param arreglo Arreglo en el cual se buscara
 * @param longitud Longitud del arreglo
 * @param valorABuscar Valor buscado
 * @return int
 *
 * @author Dave Gomez
 */
int busqueda_lineal(int arreglo[], const int longitud, int valorABuscar)
{
  int i, bandera = 0;
  for (i = 0; i < longitud; i++)
  {
    if (arreglo[i] == valorABuscar)
    {
      bandera = 1;
      break;
    }
  }

  if (bandera == 0)
    i = -1;

  return i;
}

/**
 * @brief Retorna la posicion de un valor dentro de un arreglo, -1 si el valor no se encuentra en el arreglo por el metodo de la busqueda binaria de forma iterativa
 *
 * @param arreglo Arreglo en el cual se buscara
 * @param valBuscado Valor buscado
 * @param inicio Inicio de posicion a buscar
 * @param fin Fin de Posicion a buscar
 * @return int
 *
 * @author Dave Gomez
 */
int busquedaBinaria(int arreglo[], int valBuscado, int inicio, int fin)
{
  int central;
  while (inicio <= fin)
  {

    central = (inicio + fin) / 2;

    if (valBuscado == arreglo[central])
    {
      return central;
    }
    else if (valBuscado < arreglo[central])
    {
      fin = central - 1;
    }
    else
    {
      inicio = central + 1;
    }
  }

  return -1;
}

/**
 * @brief Retorna la posicion de un valor dentro de un arreglo, -1 si el valor no se encuentra en el arreglo por el metodo de la busqueda binaria de forma recursiva
 *
 * @author Dave Gomez
 * @param arreglo Arreglo en el cual se buscara
 * @param busqueda Valor buscado
 * @param izquierda Inicio de posicion a buscar
 * @param derecha Fin de Posicion a buscar
 * @return int
 *
 * @author Dave Gomez
 *
 */

int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha)
{
  if (izquierda > derecha)
    return -1;

  int indiceDeLaMitad = ((izquierda + derecha) / 2);

  int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
  if (busqueda == valorQueEstaEnElMedio)
  {
    return indiceDeLaMitad;
  }

  if (busqueda < valorQueEstaEnElMedio)
  {
    // Entonces está hacia la izquierda
    derecha = indiceDeLaMitad - 1;
  }
  else
  {
    // Está hacia la derecha
    izquierda = indiceDeLaMitad + 1;
  }
  return busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}

/**
 * @brief Agrega en una Arreglo la suma de cada Columan de una matriz
 *
 * @param fila Cantidad de filas
 * @param col Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @param sumaCol Arreglo de sumas
 */
void sumaDeColumnas(int fila, int col, int matriz[][col], int sumaCol[])
{
  int i, j, acum = 0;
  for (i = 0; i < col; i++)
  {
    for (j = 0; j < fila; j++)
    {
      acum += matriz[j][i];
    }
    sumaCol[i] = acum;
    acum = 0;
  }
}

/**
 * @brief Agrega a un array la suma de todas las filas de la matriz
 *
 * @param fila Cantidad de filas
 * @param col Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @param sumaFilas Arreglo de sumas
 */
void sumaDeFilas(int fila, int col, int matriz[][col], int sumaFilas[])
{
  int i, j, acum = 0;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < col; j++)
    {
      acum += matriz[i][j];
    }
    sumaFilas[i] = acum;
    acum = 0;
  }
}

/**
 * @brief Retorna el valor de la suma de la diagonal principal de una matriz
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @return int
 */
int sumaDiagonalPrincipal(int fila, int columna, int matriz[][columna])
{
  int i, j, acum = 0;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < columna; j++)
    {
      if (i == j)
      {
        acum += matriz[i][j];
        break;
      }
    }
  }
  return acum;
}

/**
 * @brief Retorna el valor de la suma de la diagonal secundaria de una matriz
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @return int
 */
int sumaDiagonalSecundaria(int fila, int columna, int matriz[][columna])
{
  /* trabajamos con matrices cuadradas, lo que implica que fila == comulna */
  if (fila != columna)
    return 'x';

  int i, j, acum = 0;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < columna; j++)
    {
      if (i + j == fila - 1)
      {
        acum += matriz[i][j];
        break;
      }
    }
  }
  printf("\n");
  return acum;
}

/**
 * @brief Imprimie una matriz formateada en forma de Table
 *
 * @param filas Cantidad de filas
 * @param columnas Cantidad de columnas
 * @param Matriz Matriz a ser impresa
 */
void imprimeMatrizFormat(int filas, int columnas, int Matriz[][columnas])
{
  int i;
  int j;

  /* printf("\n\nEste es el tablero:\n\n "); */
  for (i = 0; i < filas; i++)
  {
    for (j = 0; j < columnas; j++)
    {
      printf(" %d\t", Matriz[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}

/**
 * @brief Lee solo digitos del 0 al 9 a una matriz dada
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de columnas
 * @param mat Matriz a ser cargada
 */
void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna])
{

  int i, j;
  int val;
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < columna; j++)
    {
      scanf("%d", &val);
      while (val < 0 || val > 9)
      {
        printf("valor incorrecto reingrese");
        scanf("%d", &val);
      }
      mat[i][j] = val;
    }
  }
}

/**
 * @brief Separa los digitos de un entero en un arrayy
 *
 * @param arreglo Arreglo destino
 * @param valor Entero a ser spliteado
 */
void digitosInt(int arreglo[], int valor)
{
  int longitud = 9; /* un int solo puede almacenar numeros de hasta 9 digios */
  int cont = 0, digito;
  while (valor != 0)
  {
    digito = valor % 10;
    arreglo[cont] = digito;
    valor = valor / 10;
    cont++;
  }
}

/* Funciones de caracteres y cadenas */

/**
 * @brief Recibe un caracter y devuelve su valor entero
 *
 * @param caracter Caracter a ser convertido
 * @return int
 */
int charToInt(char caracter)
{
  return caracter - '0';
}

/**
 * @brief Convierte un entero a digito
 *
 * @param numero Entero a ser convertido
 * @return char
 */
char enteroACaracter(int numero)
{
  return numero + '0';
}

/**
 * @brief Imprime recursivamente los caracteres de una cadena en orden inverso
 *
 * @param ptrS Puntero a la cadena
 */
void inverso(const char *const ptrS)
{
  /* si es el final de la cadena */
  if (ptrS[0] == '\0')
  { /* caso base */
    return;
  } /* fin de if */
  else
  {                    /* si no es el final de la cadena */
    inverso(&ptrS[1]); /* paso recursivo */
    putchar(ptrS[0]);  /* utiliza putchar para desplegar los caracteres */
  }                    /* end else */
} /* fin de la función inverso */

/**
 * @brief Lee una cadena con espacios por medio de la funcion getchar
 *
 * @param cadena Cadena Destino
 */
void leeConEspacios(char cadena[])
{
  char c;
  int i = 0;
  while ((c = getchar()) != '\n')
  {
    cadena[i++] = c;
  }
}

/**
 * @brief Separa las palabras de un enunciado en un array
 *
 * @param array Array destino
 * @param enunciado Cadena a ser Spliteada
 * @param separador Caracter separador
 */
void separaParabrasEnArray(char *array[], char enunciado[], char separador[])
{

  int i;
  char *ptrToken = strtok(enunciado, separador);

  while (ptrToken != NULL)
  {
    array[i++] = ptrToken;
    ptrToken = strtok(NULL, separador);
  }
}

/**
 * @brief Retorna letras de la A a la H para rempresentar las columnas del tablero de ajedrez
 *
 * @param val Posicion en el tablero
 * @return char
 */
char getLetra(int val)
{
  switch (val)
  {
  case 1:
    return 'a';
    break;
  case 2:
    return 'b';
    break;
  case 3:
    return 'c';
    break;
  case 4:
    return 'd';
    break;
  case 5:
    return 'e';
    break;
  case 6:
    return 'f';
    break;
  case 7:
    return 'g';
    break;
  case 8:
    return 'h';
    break;
  default:
    return 'x';
    break;
  }
}

/**
 * @brief Devuelve la cantidada de apariciones de cada vocal en una cadena
 *
 * @param exp Cadena a evaluar
 */
void vocales(char exp[])
{
  int cantidadAparicion[5] = {0}; /* posiciones 0 = a , 1 = e,... 4 = u */
  char vocalesstr[] = "aeiou";
  int longitud, i;
  longitud = strlen(exp);
  for (i = 0; i < longitud; i++)
  {
    if (exp[i] == 'a' || exp[i] == 'A')
    {
      cantidadAparicion[0]++;
    }
    if (exp[i] == 'e' || exp[i] == 'E')
    {
      cantidadAparicion[1]++;
    }
    if (exp[i] == 'i' || exp[i] == 'I')
    {
      cantidadAparicion[2]++;
    }
    if (exp[i] == 'o' || exp[i] == 'O')
    {
      cantidadAparicion[3]++;
    }
    if (exp[i] == 'u' || exp[i] == 'U')
    {
      cantidadAparicion[4]++;
    }
  }

  for (i = 0; i < 5; i++)
  {
    if (cantidadAparicion[i] != 0)
    {
      printf("la vocal %c aparece %d veces \n su pocentaje de aparicion es %d prociento\n", vocalesstr[i], cantidadAparicion[i], 100 * (cantidadAparicion[i] / longitud));
    }
    else
    {
      printf("La vocal %c no existe o no tiene repeticion\n", vocalesstr[i]);
    }
  }
}

/**
 * @brief Emite un mensaje con la posicion de primera a paricion de un caracter en una cadena
 *
 * @param exp Cadena a evaluar
 * @param p Caracter buscado
 */
void primeraAparicion(char exp[], char p)
{
  int i;
  for (i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == p)
    {
      printf("%c aparece en la posicion %d\n", p, i);
      break;
    }
  }
}

/* Funciones de Ordenamiento */

/**
 * @brief Ordenamiento de intercambio. Ordena un array en orden ascendente por el metodo de intercambio de variables
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void ordIntecambio(int arreglo[], int longitud)
{
  int i,   // iterador
      j,   // iterador
      aux; // contenedor temporal del valor

  for (i = 0; i < longitud - 1; i++) // inicia desde la primera posicion del arreglo hasta la posicion longitud -1
  {
    for (j = i + 1; j < longitud; j++) // inicia desde la segunda posicion de arreglo hasta la ultima posicion
    {
      if (arreglo[i] > arreglo[j]) // si el arreglo de la segunda pisicon i > al de posicion j los intercambia
      {
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
      }
    }
  }
}

/**
 * @brief Ordena un Array por el metodo de seleccion. Ejemplo del libro Joyanes
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void ordSeleccion(int arreglo[], int longitud) // ejemplo joyanes
{
  printf("seleccion\n");
  int indiceMenor, // pos menor
      i,           // iterador
      j;           // iterador
  double aux;      // contenedor temporal
  for (i = 0; i < longitud - 1; i++)
  {
    indiceMenor = i; // inicial el menor elemento en el principio de cada iteracion

    for (j = i + 1; j < longitud; j++) // empieza a buscar una posicion despues de la posicion de i
    {
      if (arreglo[j] < arreglo[indiceMenor])
        indiceMenor = j; /* situa el elemento menor */
    }

    if (i != indiceMenor)
    { /* si existia un elemento menor lo intercambia por la posicion actual del puntero */
      aux = arreglo[i];
      arreglo[i] = arreglo[indiceMenor];
      arreglo[indiceMenor] = aux;
    }
  }
}

/**
 * @brief Ordena un arreglo por el metodo de seleccion. Desarrollo propio, adaptado para desarrollarse de forma recursiva
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void ordSeleccionRecusiva(int arreglo[], int longitud)
{
  int aux,           // contenedor temporal
      posicionMenor; // posicion del elemento menor
  if (longitud > 1)
  {
    posicionMenor = posMenor(arreglo, longitud); // determina la posicion del menor elemento del arreglo
    /* intercambia el arreglo de la posicion inicial con el menor  */
    aux = arreglo[0];
    arreglo[0] = arreglo[posicionMenor];
    arreglo[posicionMenor] = aux;
    /*  */

    ordSeleccionRecusiva(&arreglo[1], longitud - 1); // recursion con el array a partir de la posicion dos
  }
}

/**
 * @brief Ordena un arreglo de forma ascendente por el metodo de burbuja
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void burbuja_asc(int arreglo[], const int longitud)
{
  int pasadas, i, almacenador;

  for (pasadas = 0; pasadas < longitud; pasadas++)
  {
    for (i = 0; i < longitud - 1; i++)
    {
      if (arreglo[i + 1] < arreglo[i])
      {
        almacenador = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = almacenador;
      }
    }
  }
}

/**
 * @brief Ordena un arreglo de forma descendente por el metodo de burbuja
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void burbuja_des(int arreglo[], const int longitud)
{
  int pasadas, i, almacenador;

  for (pasadas = 0; pasadas < longitud; pasadas++)
  {
    for (i = 0; i < longitud - 1; i++)
    {
      if (arreglo[i + 1] > arreglo[i])
      {
        almacenador = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = almacenador;
      }
    }
  }
}

/**
 * @brief Ordena un arreglo de forma ascendente por el metodo de ordenacion rapida (Quicksort)
 *
 * @param array Arreglo a ser ordenado
 * @param inicio Inicio de rango a ordenar
 * @param fin Fin de rango a ordenar
 */
void quickSort(double array[], int inicio, int fin)
{
  int i,       // iterador
      j,       // iterador
      central; // indicador del centro del array
  double pivote;
  central = (inicio + fin) / 2; // ubica el centro del array
  pivote = array[central];      // ubica en el valor pivote el valor del elemento central del array
  double temporal;
  do
  {
    while (array[i] < pivote)
      i++; // ubica el primer elemento menor que el pivote
    while (array[j] > pivote)
      j++; // ubica el primer elemento mayor que el pivote

    if (i <= j)
    { // si la posicion del primer elemento mayo y menor, el menr es menor o igual al mayor

      // intercambia los valores
      temporal = array[i];
      array[i] = array[j];
      array[j] = temporal;
      i++; // incrementa la posicion del elemento menor
      j--; // decrementa la posicion del elemento mayor
    }

  } while (i <= j);

  if (inicio <= j)
  {                              // si el inico es menor o igual a la posicion del primer elemento mayor al pivote
    quickSort(array, inicio, j); // recursadesde el inicio hasta la posicion
  }

  if (i < fin)
  {                           // si el inico es menor o igual a la posicion del primer elemento mayor al pivote
    quickSort(array, i, fin); // recursa desde la posicion hasta el fin
  }
}

/* Funciones de Pruebas y generacion aleatoria */

/**
 * @brief Genera numeros aleatorios desde el cero hasta un valor especificado
 * incluir stdlib para usar rand() y time()
 * @param arreglo Arreglo en que se cargaran los numero
 * @param longitud longitud del arreglo
 * @param valorLimite valor techo
 *
 * @author Dave Gomez
 */
void arrayAleatorio(int arreglo[], int longitud, int valorLimite)
{
  int i, j;
  srand(time(NULL));
  for (i = 0; i < longitud; i++)
  {
    arreglo[i] = rand() % valorLimite;
  }
}

/**
 * @brief Inicializa una matriz con valores aleatorios del 0 a valor especificado
 *
 * @param fila cantidad de filas
 * @param columna cantidad de columnas
 * @param arreglo matriz a ser cargada
 * @param valLimite valor maximo
 */
void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite)
{ /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* incluir stdlib para usar rand() y time() */
  int i, j;
  srand(time(NULL));
  for (i = 0; i < fila; i++)
  {
    for (j = 0; j < columna; j++)
    {
      arreglo[i][j] = rand() % valLimite;
    }
  }
}

/**
 * @brief devuelve un numero entero positivo, negativo o cero aleatorio
 *
 * @param limite valor maximmo
 * @return int
 */
int enteroAleatorio(int limite)
{ // devuelve un numero entero positivo, negativo o cero aleatorio

  int valor1 = (rand() % limite);
  int valor2 = (rand() % limite);

  return valor1 - valor2;
}

/**
 * @brief devuelve un numero aleatorio entre el limite inferior y el superior
 *
 * @param limiteInf limite inferior
 * @param limiteSup limite Superior
 * @return int
 */

int enteroAleatorioEntre(int limiteInf, int limiteSup)
{ // devuelve un numero aleatorio entre el limite inferior y el superior

  int valor = limiteInf + (rand() % (limiteSup - limiteInf));
  return valor;
}

/**
 * @brief devuelve un numero flotante aleatorio INT32_MAX es el limite maximo de los int de 32 bits
 *
 * @return float
 */
float flotanteAleatorio()
{ // devuelve un numero flotante aleatorio
  // INT32_MAX es el limite maximo de los int de 32 bits
  int numerador = enteroAleatorio(INT32_MAX);                   // OPTIENE el numerador de forma aleatoria
  int denominador = 1 + enteroAleatorioEntre(1, INT32_MAX - 1); // OPTIENE el denominador de forma aleatoria el valor no puede ser cero
  float flotante = numerador / denominador;

  return flotante;
}

/**
 * @brief  devuelve un caracter aleatorio
 *
 * @return char
 */
char caracterAleatorio()
{                                                          // devuelve un caracter aleatorio
  char caracter = enteroAleatorioEntre(0, CHAR_MAX) + '0'; // asigna el valor aleatorio la variable
  return caracter;
}

/**
 * @brief agrega varacteres aleatorios a la cadena
 *
 * @param cadena
 * @param longitud
 */
void cadenaAleatoria(char cadena[], int longitud)
{
  int i;
  for (i = 0; i < longitud - 1; i++)
  {
    cadena[i] = caracterAleatorio(); // asigna caracteres de forma aleatoria a la cadena
  }
  cadena[longitud - 1] = '\n'; // asigna caracter de escape al ultimo caracter de la cadena
}

/**
 * @brief devuelve el apuntador a una cadena de longitud aleatoria
 *
 * @return char*
 */
char *cadenaAleatoriaLongAleatoria()
{ // devuelve el apuntador a una cadena de longitud aleatoria
  int longitud = enteroAleatorioEntre(1, 500);
  char Cadena[longitud];
  cadenaAleatoria(Cadena, longitud);
  return Cadena;
}

/* Registros y Estructuras */

/**
 * @brief Crea un registro nuevo, lee sus valor y devuelve una copia
 *
 * Obs: Al editar la definicion de registro dependiendo de la necesidad del programa, se edebe editar esta funcion para poder usarla
 *
 * @return Registro
 */
Registro creaRegistro()
{ // crea un registro nuevo, lee sus valor y devuelve una copia

  printf("\n** Crea un Registro **\n");
  Registro *ptrNuevoRegistro = malloc(sizeof(Registro)); // libera espacio en memoria para el nuevo registro
  printf("Ingresa el valor a ser insertado en el Registro: ");
  scanf("%d", &ptrNuevoRegistro->valor);
  /*   printf("Ingrese El nombre del Propietario de la Cuenta: ");
  scanf("%s", ptrNuevoRegistro->nombre);
  printf("ingrese EL estado de la cuenta: ");
  scanf("%lf", &ptrNuevoRegistro->estadoDeCuenta); */

  return *ptrNuevoRegistro; // retorna una copia del registro creado
}

/**
 * @brief libera espacio en memoria para el nuevo registro
 *
 * @param ptrRegistro Registro a ser liberado
 */
void borraRegistro(Registro *ptrRegistro)
{
  free(ptrRegistro); // libera espacio en memoria para el nuevo registro
}

void imprimeRegistro(Registro *ptrRegistro)
{
  printf("%d", ptrRegistro->valor);
}

/* Listas Enlazadas */

/**
 * @brief Funciones de Manipulacion de Listas Enlazadas
 *
 * @author Dave Gomez
 */

/**
 * @brief Crea un nodo de una lista y devuelve su direccion en memoria
 *
 * @param dato Dato a ser insertado en el Nodo, dependiendo del tipo de nodo puede ser un Registro, entero, cadena, o cualquier tipo de dato
 * @return Nodo*
 *
 * @author Dave Gomez
 */

Nodo *creaNodo(Registro dato)
{
  Nodo *nuevoNodo = malloc(sizeof(Nodo));
  if (nuevoNodo != NULL)
  {
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ante = NULL;
    return nuevoNodo;
  }
  else
  {
    printf("No de pudo crear el Nuevo Nodo, Memoria insuficiente");
    return NULL;
  }
}

/**
 * @brief Retorna -1 si la lista esta vacia, 0 en caso contrario
 *
 * @param ListaVal Lista a ser Evaluada
 * @return int
 *
 * @author Dave Gomez
 */
int listaEstaVacia(Lista ListaVal)
{
  if (ListaVal.cabeza == NULL && ListaVal.cola == NULL)
  { // si la cabeza y la cola son iguales a NULL
    return -1;
  }
  else
  {
    return 0;
  }
}

/**
 * @brief Crea un nodo y lo inserta en la cabeza de la lista (tambien valido para pila)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}.
 * Obs: para una pila, si inserto desde la cabeza tambien debo leer desde la cabeza.
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarDatoEnCabeza(Registro dato, Lista *listaDestino)
{
  Nodo *ptrNuevoNodo = creaNodo(dato); // crea el nodo con el dato

  if (ptrNuevoNodo != NULL)
  {
    listaDestino->cantidadElem++;

    if (listaEstaVacia(*listaDestino) == -1)
    { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else
    {                                            // si la lista no esta vacia
      ptrNuevoNodo->sig = listaDestino->cabeza;  // asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
      listaDestino->cabeza->ante = ptrNuevoNodo; // asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
      listaDestino->cabeza = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
    }
  }
}

/**
 * @brief Crea un nodo y lo inserta en cola de la lista (tabien valido para Colas)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarDatoEnCola(Registro dato, Lista *listaDestino)
{
  /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
  Nodo *ptrNuevoNodo = creaNodo(dato);

  if (ptrNuevoNodo != NULL)
  {
    listaDestino->cantidadElem++;

    if (listaEstaVacia(*listaDestino) == -1)
    { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else
    {                                          // si la lista no esta vacia
      ptrNuevoNodo->ante = listaDestino->cola; // asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
      listaDestino->cola->sig = ptrNuevoNodo;  // asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
      listaDestino->cola = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
    }
  }
}

/**
 * @brief crea un registro y lo inserta en la cabeza de la lista
 *
 * @param ACargar
 */
void insertarEnCabeza(Lista *ACargar)
{
  int valor;
  Registro RegistroAInsertar = creaRegistro();
  insertarDatoEnCabeza(RegistroAInsertar, ACargar);
}

/**
 * @brief crea un registro y lo inserta en la cola de la lista
 *
 * @param ACargar
 */
void insertarEnCola(Lista *ACargar)
{
  int valor;
  Registro RegistroAInsertar = creaRegistro();
  insertarDatoEnCola(RegistroAInsertar, ACargar);
}

/**
 * @brief Extrae un el dato de la cabeza de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return Registro
 *
 * @author Dave Gomez
 */
Registro extraerCabeza(Lista *listaObjetivo)
{

  Registro Dato = {0}; // contenedor Auxiliar
  if (listaEstaVacia(*listaObjetivo) != -1)
  {

    Nodo *ptrNodoObjetivo;

    ptrNodoObjetivo = listaObjetivo->cabeza;

    Dato = ptrNodoObjetivo->dato;
    listaObjetivo->cabeza = ptrNodoObjetivo->sig;
    listaObjetivo->cabeza->ante = NULL; // asigna null al puntero anterior del nodo cabeza
    listaObjetivo->cantidadElem--;      // resta uno a la cantidad de elementos de la lista
    if (listaObjetivo->cantidadElem == 0)
      listaObjetivo->cola = NULL;

    free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
  }
  else
    printf("\nLa lista esta vacia\n");

  return Dato; // retorna una copia del registro extraido
}

/**
 * @brief Extrae un el dato de la cola de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return Registro
 *
 * @author Dave Gomez
 */
Registro extraerCola(Lista *listaObjetivo)
{
  Nodo *ptrNodoObjetivo;
  Registro Dato;                         // contenedor Auxiliar
  ptrNodoObjetivo = listaObjetivo->cola; // direccion de memoria del nodo a extraer

  Dato = ptrNodoObjetivo->dato;                // asigna el dato de la cola al registro contenedor
  listaObjetivo->cola = ptrNodoObjetivo->ante; // asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida

  listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
  if (listaObjetivo->cantidadElem == 0)
    listaObjetivo->cabeza = NULL;
  else
    listaObjetivo->cola->sig = NULL; // elimina la direccion de memoria del apuntador siguiente de la cola actual

  free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
  return Dato;
}

/**
 * @brief Imprime una lista desde la cabeza (tambien valido para una Cola)
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaCabeza(const Lista *listaObjetivo)
{
  printf("\nLa lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while (ptrNodoObjetivo != NULL)
  {
    imprimeRegistro(&ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
    printf(" -> ");
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
  printf("NULL\n");
}

/**
 * @brief imprime una lista desde la Cola (tambien valido para una Pila)
 * Obs: para una pila, si leo desde la cola es porque cargue los datos desde la cola
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaCola(const Lista *listaObjetivo)
{

  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cola;
  while (ptrNodoObjetivo != NULL)
  {
    imprimeRegistro(&ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
    printf(" -> ");
    ptrNodoObjetivo = ptrNodoObjetivo->ante;
  }
  printf("NULL\n");
}

/**
 * @brief Imprime El registro Recibido
 * Obs: como los registros pueden variar segun la necesidad se debe editar aqui los espeficicadores de conversion y los parametros a imprimir
 *
 * @param datos Registro a Imprimir
 *
 * @author Dave Gomez
 */

/**
 * @brief Retorna la direccion del primer nodo que contenga un dato mayor al valor recibido como parametro
 *
 * @param Dato Entero que sera comparado
 * @param listaDestino Lista en la que se buscara
 * @return Nodo*
 *
 * @author Dave Gomez
 */
Nodo *dirMayor(int Dato, Lista *listaDestino)
{
  Nodo *ptrNodoEvaluado = listaDestino->cabeza;
  while (ptrNodoEvaluado != NULL)
  {
    if (ptrNodoEvaluado->dato.valor > Dato)
    { // compara el valor
      return ptrNodoEvaluado;
    }
    else
      ptrNodoEvaluado = ptrNodoEvaluado->sig;
  }

  return NULL;
}

/**
 * @brief Inserta un dato recibido en la lista, detras del nodo especificado
 *
 * @param nodoMayor Direccion de memoria del Nodo del cual se insertara el dato Antes
 * @param dato Dato a ser insertado
 *
 * @author Dave Gomez
 */
void insertaDatoAntesDe(Nodo *nodoMayor, Registro dato)
{

  Nodo *ptrNuevoNodo = creaNodo(dato);

  ptrNuevoNodo->sig = nodoMayor;        // asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; // asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
  nodoMayor->ante->sig = ptrNuevoNodo;
  nodoMayor->ante = ptrNuevoNodo;
}

/**
 * @brief Inserta un Nodo detras de otro especificado
 *
 * @param nodoMayor Direccion de memoria del Nodo del cual se insertara el dato Antes
 * @param dato Dato a ser insertado
 *
 * @author Dave Gomez
 */
void insertaNodoAntesDe(Nodo *nodoMayor, Nodo *ptrNuevoNodo)
{

  ptrNuevoNodo->sig = nodoMayor;        // asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; // asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
  nodoMayor->ante->sig = ptrNuevoNodo;
  nodoMayor->ante = ptrNuevoNodo;
}

/**
 * @brief Inserta un Dato en una Lista dependidendo de Su orden
 *
 * @param dato
 * @param listaDestino
 *
 * @author Dave Gomez
 */
void insertaEnOrden(Registro dato, Lista *listaDestino)
{

  Nodo *ptrNuevoNodo = creaNodo(dato);

  if (ptrNuevoNodo != NULL)
  {
    listaDestino->cantidadElem++;

    if (listaEstaVacia(*listaDestino) == -1)
    { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else
    {
      Nodo *ptrNodoMayor = dirMayor(dato.valor, listaDestino);
      if (ptrNodoMayor == listaDestino->cabeza)
      {
        insertarDatoEnCabeza(dato, listaDestino);
      }
      else
      {
        if (ptrNodoMayor != NULL)
        {
          insertaNodoAntesDe(ptrNodoMayor, ptrNodoMayor);
        }
        else
        {
          insertarDatoEnCola(dato, listaDestino);
        }
      }
    }
  }
}

/**
 * @brief Despliga un menu con las poeraciones basicas con listas
 *
 * @author Dave Gomez
 */
void despliegaMenuListas()
{

  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Cabeza de la lista Lista\n");
  printf("2 - Insertar en la Cola de la Lista\n");
  printf("3 - Extraer de la cabeza la Lista\n");
  printf("4 - Extraer de la cola la Lista\n");
  printf("5 - Imprimir la Lista\n");
  printf("6 - Salir\n");
  printf("Su Opcion = ");
}

/* Funciones de colas de prioridad */

/**
 * @brief Crea una cola de prioridad
 *
 * @param cantidadDePrioridades
 * @return ColaDePrioridad
 */
ColaDePrioridad CreaColaPrioridad(int cantidadDePrioridades)
{
  ColaDePrioridad NuevaCola; // Cola A ser retornada

  int i;                                      // iterador
  for (i = 0; i < cantidadDePrioridades; i++) // Inicializa las colas del Array Prioridades a colas Vacias
  {
    NuevaCola.Prioridades[i].cabeza = NULL;
    NuevaCola.Prioridades[i].cola = NULL;
    NuevaCola.Prioridades[i].cantidadElem = 0;
  }

  NuevaCola.CantPrioridades = cantidadDePrioridades; // Indica cuantas prioridades hay en la Cola
  return NuevaCola;
}

/**
 * @brief Inserta un registro en una cola de prioridad
 *
 * @param ColaPrioridad
 * @param AInsertar
 */
void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, RegistroDePrioridad *AInsertar)
{
  if (AInsertar->prioridad < ColaPrioridad->CantPrioridades && AInsertar->prioridad >= 0)
  {
    insertarDatoEnCola(AInsertar->nodo->dato, &ColaPrioridad->Prioridades[AInsertar->prioridad]);
  }
  else
  {
    printf("Error! Prioridad fuera de Rango");
  }
}

/**
 * @brief  inserta en una una cola de prioridad
 *
 * @param colaDePrioridad
 */
void insertarDatosEnColaDePriridad(ColaDePrioridad *colaDePrioridad)
{

  int P;

  RegistroDePrioridad *DatosDePrioridad = malloc(sizeof(RegistroDePrioridad));
  DatosDePrioridad->nodo = creaNodo(creaRegistro());
  printf("Prioridad:");
  scanf("%d", &P);
  DatosDePrioridad->prioridad = P - 1;

  insertarEnPrioridad(colaDePrioridad, DatosDePrioridad);
}

/**
 * @brief Lee un dato de la cola de prioridad
 *
 * @param colaDePrioridad
 */
void leerColaDePrioridades(ColaDePrioridad *colaDePrioridad)
{
  if (ColaPrioridadVacia(*colaDePrioridad) != -1)
  {
    Registro aux = DesencolaPrioridad(colaDePrioridad);
    printf("El Prime Dato era: %d", aux.valor); // aqui deban inr las operaciones requeridas para hacer con el dato de la cola de prioridad
  }
  else
  {
    printf("Error: La cola de priridad Esta Vacia\n");
  }
}

/**
 * @brief Imprime el estado actual de la cola de prioridad
 *
 * @param colaDePrioridad
 */
void imprimirColaDePrioridad(ColaDePrioridad colaDePrioridad)
{
  int i; // iterador
  printf("\nCola De prioridad de %d Prioridades\n", colaDePrioridad.CantPrioridades);
  for (i = 0; i < colaDePrioridad.CantPrioridades; i++)
  {
    printf("\nPrioridad %d\n", i + 1);
    imprimeDesdeLaCabeza(&colaDePrioridad.Prioridades[i]);
  }
}
/**
 * @brief Retorna -1 si la lista esta vacia, 0 en caso contrario
 *
 * @param ListaVal
 * @return int
 */
int ColaPrioridadVacia(ColaDePrioridad ListaVal)
{                   // retorna -1 si la lista esta vacia, 0 en caso contrario
  int i;            // iterador
  int bandera = -1; // su valor determina si esta o no vacia: -1 para vacia, 0 para no vacia
  for (i = 0; i < ListaVal.CantPrioridades; i++)
  {
    if (ListaVal.Prioridades[i].cabeza != NULL)
    {
      bandera = 0;
      break; // basta con que una de las colas no este vacia para que la cola de prioridades no este vacia
    }
  }

  return bandera;
}

/**
 * @brief Saca un dato de la cola de prioridad
 *
 * @param ColaDePrio
 * @return Registro
 */
Registro DesencolaPrioridad(ColaDePrioridad *ColaDePrio)
{
  // esta funcion no es aplicable a colas de prioridades vacias

  int i = 0;
  Registro dato; // contenedor auxiliar a ser retornado
  for (i = 0; i < ColaDePrio->CantPrioridades; i++)
  {
    if (listaEstaVacia(ColaDePrio->Prioridades[i]))
      continue;

    dato = extraerCabeza(&ColaDePrio->Prioridades[i]);
    break; // extrae solamente el primer elemento de la primera cola no vacia que encuentra
  }

  return dato;
}

/**
 * @brief Despliega un menu de operaciones de la cola de prioridad
 *
 */
void despliegaMenuColasDePrioridad()
{
  printf("\n");
  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Cola de prioridades\n");
  printf("2 - Leer Dato desde la Cola de prioridades\n");
  printf("3 - Imprimir la Cola de prioridades\n");
  printf("4 - Salir\n");
  printf("Su Opcion = ");
}

/**
 * @brief Funciones de archivos
 *
 */

/**
 * @brief crea un arichivo y devuelve su apuntador
 *
 * @return FILE*
 */
Archivo *creaArchivo()
{

  char nombreArchivo[150] = "";
  char modo[5] = "";
  Archivo *ptrNuevoArchivo = malloc(sizeof(Archivo)); // inicializa el puntero al archivo en null

  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo); // ingresa el nombre y formato del archivo
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo); // ingresa el formato de apertura del archivo
  if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, modo)) == NULL)
  {
    printf("No se pudo crear el archivo.\nERROR\n"); // retorna null si no se pudo abrir el archivo
    return NULL;
  }
  else
  {
    ptrNuevoArchivo->cantidadElementos = 0; // establece en cero la cantidad de elementos
    optenerCantidadElementos(ptrNuevoArchivo);
    return ptrNuevoArchivo; // retorna el puntero al archivo si hubo exito
  }
}

/**
 * @brief //crea un arichivo binario y devuelce su apuntador
 *
 * @return FILE*
 */
Archivo *creaArchivoBin()
{

  char nombreArchivo[150] = "";
  char modo[5] = "";
  Archivo *ptrNuevoArchivo = NULL; // inicializa el puntero al archivo en null

  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo); // ingresa el nombre y formato del archivo
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo); // ingresa el formato de apertura del archivo
  if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, modo)) == NULL)
  {
    if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, "wb+")) != NULL)
    {
      ptrNuevoArchivo->cantidadElementos = 0;
      return ptrNuevoArchivo; // retorna el puntero al archivo si hubo exito
    }
    else
    {
      printf("No se pudo Abir Ni crear el archivo");
      return NULL;
    }
  }
  else
  {
    if (strcmp("w", modo) == 0)
    {
      fclose(ptrNuevoArchivo->punteroArchivo);
      ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, "rb+");
      ptrNuevoArchivo->cantidadElementos = 0;
      return ptrNuevoArchivo;
    }
    else
      ptrNuevoArchivo->cantidadElementos = 0;
    return ptrNuevoArchivo; // retorna el puntero al archivo si hubo exito
  }
}

/**
 * @brief Recibe el apuntador a un registro y lo guarda en el archivo
 *
 * @param ptrArchivo Puntero a estructura de Tipo Archivo
 * @param aGuardar Registro a ser guardado en el archivo
 */
void guardaRegistroEnArchivo(Archivo *ptrArchivo, RegistroArchivo *aGuardar)
{

  // si el archivo no ha sido eliminado logicamente
  fseek(ptrArchivo->punteroArchivo, (aGuardar->id - 1) * sizeof(RegistroArchivo), SEEK_SET); // establece el apuntador a la posicion del numero de cuenta del nuevo Registro
  fwrite(aGuardar, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);                  // escribe el contenido del registro nuevo en la direccion especificada
  rewind(ptrArchivo->punteroArchivo);
}

/**
 * @brief Crea un nuevo registro y lo inserta en el archivo
 *
 * @param ptrArchivo Puntero al archivo destino
 */
void nuevoRegistro(Archivo *ptrArchivo)
{

  RegistroArchivo nuevoRegistro = {ptrArchivo->cantidadElementos + 1, 1, {0}}, auxRegistro = {0, 0, {0}};

  nuevoRegistro.Dato = creaRegistro(); // crea un nuevo registro
  nuevoRegistro.estaEliminado = 1;

  fseek(ptrArchivo->punteroArchivo, (ptrArchivo->cantidadElementos + 1) * sizeof(RegistroArchivo), SEEK_SET); // establece el apuntador a la posicion del numero de cuenta del nuevo Registro
  fread(&auxRegistro, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);                                // almacena la lectura del puntero del archivo al registro auxiliar

  if (auxRegistro.id != 0)
  { // si la cuenta del reigistro ya existe, o si existe y no esta esliminado
    printf("\nERROR: La cuenta %d Ya existe\n", auxRegistro.id);
  }
  else
  { // sino, guarda el nuevo registro en esa direccion
    printf("estatus nR: %d \n", nuevoRegistro.estaEliminado);
    imprimeRegistro(&nuevoRegistro.Dato);
    guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistro);
    ptrArchivo->cantidadElementos++;
    printf("\nRegistro Agregado Exitosamente!\n\n");
  }
}

/**
 * @brief Establece en blanco un registro en el archivo (Eliminacion Fisica)
 *
 * @param ptrArchivo Puntero a Estructura de Tipo archivo de la cual se eliminara un
 */
void eliminaRegistro(Archivo *ptrArchivo)
{

  RegistroArchivo registroAux = {0, 0, {0}};

  int id;
  printf("Introduzca el id a Eliminar: ");
  scanf("%d", &id);

  fseek(ptrArchivo->punteroArchivo, (id - 1) * sizeof(RegistroArchivo), SEEK_SET); // situa el apuntador a la direccion del registro a eliminar
  fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);     // lee el registro

  if (registroAux.estaEliminado == -1 || registroAux.id == 0 || registroAux.estaEliminado == 0) // verifica si el archivo ya esta vacio de antemano
  {
    printf("El registro %d no existe", id);
  }
  else // edita el archivo
  {
    registroAux.estaEliminado = -1;
    guardaRegistroEnArchivo(ptrArchivo, &registroAux); // guarda un registro en blanco en la id especificada
    ptrArchivo->cantidadElementos--;
    printf("\n\tRegistro Eliminado Exitosamente\n"); // mensaje de exito
  }
}

/**
 * @brief Inicializar los valores a editar del
 *
 * @param ptrArchivo
 */
void actualizaRegistro(Archivo *ptrArchivo)
{

  RegistroArchivo registroAux;
  int id;
  Registro NuevosDatos;

  printf("\nIntroduzca id del registro a actualizar: "); // este debe ser un identificador para el registro del archivo.
  scanf("%d", &id);                                      // solicita el numero de cuenta a editar

  fseek(ptrArchivo->punteroArchivo, (id - 1) * sizeof(RegistroArchivo), SEEK_SET); // establece el apuntado al registro a editar
  fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);     // lee el registro a editar en el registro auxiliar

  if (registroAux.estaEliminado == 0)
  {
    printf("\nLa cuenta #%d no tiene informacion\n", registroAux.id);
  }
  else
  {
    printf("\nIntroduzaca los nuevos Valores para el registro de ID Nro %d \n", registroAux.id);
    NuevosDatos = creaRegistro();
    registroAux.Dato = NuevosDatos;
    guardaRegistroEnArchivo(ptrArchivo, &registroAux);
    printf("\nRegistro #%d actualizado Correctamente", registroAux.id)
  }
}

/**
 * @brief Crea un archivo de texto con formato para impresión
 * Obs: la definicion del archivo depende de los requerimientos del programa.
 *
 *
 * @param ptrArchivo
 */
void informeTxt(Archivo *ptrArchivo)
{

  FILE *ptrInforme; // apuntador al archivo Resultado

  RegistroArchivo datos = {0, 1, {0}}; // inicializar aqui el registro,

  if ((ptrInforme = fopen("Informe.txt", "w")) == NULL)
    printf("\n\tERROR: No se pudo crear el Archivo\n\n");
  else
  {
    rewind(ptrArchivo->punteroArchivo);                                                             // establece el puntero al principio del archivo
    fprintf(ptrInforme, "%s\t%s\t%s\t%s\t%s\n", "id.", "entero", "nombre", "flotante", "caracter"); // imprime la cabecera. Esto depende de los campos a imprimir del registro
    while (!feof(ptrArchivo->punteroArchivo))
    {

      fread(&datos, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo); // lee los datos en el Registro datos
      if (datos.id != -1)
      {

        /* fprintf(ptrInforme, "%d\t%d\t%s\t%3.f\t%c\n",datos.id, datos.entero, datos.nombre, datos.datoFlotante, datos.caracter); */ // imprime los datos en el arvhivo informe
      }
      else
      {
        printf("No se leyo Nada\n"); // informa que no se pudo leer nada desde el archivo origen
        break;
      }
    }

    fclose(ptrInforme); // cierra el archivo de informe
    printf("\n\tInforme Generado exitosamente!\n\n");
  }
}

/**
 * @brief recibe una Lista y guarda los registros en un archivo desde la cabeza de la lista
 *
 * @param ptrArchivo Puntero a estructura de archivo de destino
 * @param ListaDatos Lista a ser almacenada en el archivo
 */
void guardaDesdeCabezaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos)
{

  Nodo *ptrNodoObjetivo = ListaDatos.cabeza;
  RegistroArchivo nuevoRegistroArc = {0, 0, ptrNodoObjetivo->dato};
  while (ptrNodoObjetivo != NULL)
  {
    guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistroArc);
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
}

/**
 * @brief recibe una Lista y guarda los registros en un archivo desde la cola de la lista
 *
 * @param ptrArchivo Puntero a estructura de archivo de destino
 * @param ListaDatos Lista a ser almacenada en el archivo
 */
void guardaDesdeColaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos)
{
  Nodo *ptrNodoObjetivo = ListaDatos.cola;
  RegistroArchivo nuevoRegistroArc = {0, 0, ptrNodoObjetivo->dato};
  while (ptrNodoObjetivo != NULL)
  {
    guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistroArc);
    ptrNodoObjetivo = ptrNodoObjetivo->ante;
  }
}

/**
 * @brief Despliega un menu para operaciones con archivos
 *
 */
void menuArchivos()
{ // despliega el menu
  printf("Selecciones su opcion\n1- Informe EN archivo txt.\n2-AcualizarUnRegistro\n3-Agregar Un Registro.\n4- Eliminar un registro \n5-Salir Del Programa.\nOpcion=");
}

void optenerCantidadElementos(Archivo *ptrArchivo)
{
  RegistroArchivo registroAux = {0, 0, {0}};
  do
  {
    registroAux.estaEliminado = 0;
    fseek(ptrArchivo->punteroArchivo, (ptrArchivo->cantidadElementos) * sizeof(RegistroArchivo), SEEK_SET); //
    fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);                            // almacena la lectura del puntero del archivo al registro auxiliar
    // printf("Registro id: %d\n Registro estatus %s\n", registroAux.id, registroAux.estaEliminado == 0 ? "Nunca escrito" : "Con datos");

    ptrArchivo->cantidadElementos++;
    if (registroAux.estaEliminado != -1)
      ptrArchivo->registros++; // cuenta la cantidad de registro no eliminados

  } while (registroAux.estaEliminado != 0);

  if (ptrArchivo->cantidadElementos != 0)
    ptrArchivo->cantidadElementos--;
  printf("Cantidad de elementos inicial id: %d\n", ptrArchivo->cantidadElementos);
}