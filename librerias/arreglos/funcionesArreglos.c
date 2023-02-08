#include"arreglos.h"

/* FUNCIONES CON ARREGLOS UNIDIMENSIONALES */

/**
 * @brief Retorna el Mayor valor almacenado en un arreglo de enteros
 * 
 * @param arreglo Arreglo 
 * @param longitud Dimension del arreglo
 * @return int 
 */
int mayor( int arreglo[], const int longitud){

  int mayor, //valor mayor almacenado
   i; //iterador
  for(i=0; i<longitud; i++){

    if(i==0)
      mayor=arreglo[i];

    if( arreglo[i]>mayor)
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
int menor( int arreglo[], const int longitud){

  int menor,//valor menor del array
   i; //iterador
  for(i=0; i<longitud; i++){

    if(i==0)
      menor=arreglo[i]; //asigna el primer elemento como menor

    if( arreglo[i]<menor) //si encueltra un elemento que sea menor 
      menor = arreglo[i]; //asigna ese valor a la variable menor

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
void copia_arreglo( int origen[], int destino[], const int dim){
  int i; //iterador
  for( i= 0; i<dim; i++){
    destino[i]=origen[i];
  }
}

/**
 * @brief Imprimie un arreglo unidimensional separado por tabulaciones
 * 
 * @param arreglo Arreglo a ser impreso
 * @param longitud Dimension del arreglo
 */
void imprimeArreglo( int arreglo[], const int longitud){
  int i;
  for(i = 0; i<longitud; i++){
    printf(" %d\t", arreglo[i]);
  }
}

/**
 * @brief Asigna el valor inicial 0 a todas las posiciones del arreglo
 * 
 * @param arreglo Arreglo a ser inicializado
 * @param lingitud Dimension del arreglo
 */
void iniciaArreglo( int arreglo[], const int lingitud){
  int i;
  for(i = 0; i<lingitud; i++){
    arreglo[i] = 0;
  }
}

/**
 * @brief Carga valores en un arrego de dimension dada
 * 
 * @param arreglo Arreglo a ser cargado
 * @param lenght Dimension del Areglo
 */
void cargaVector( int arreglo[], const int lenght){
  int iterador, valor;

  for(iterador = 0; iterador<lenght; iterador ++){
    scanf("%d", &valor);
    arreglo[iterador]=valor;
  }

}

/**
 * @brief Retorna la posicion del menor elemento de un arreglo
 * 
 * @param arreglo Arreglo en el que se buscara
 * @param longitud Dimension del arreglo
 * @return int 
 */
int posMenor( const int arreglo[], const int longitud){

  int menor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      menor=i;

    if( arreglo[i]<arreglo[menor])
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
int posMayor( const int arreglo[], const int longitud){

  int mayor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      mayor=i;

    if( arreglo[i]>arreglo[mayor])
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
int esMonotona( int array[], int dim)
{
  int i;//iterador
  int bandera = 0; //su valor determina si es o no monotona
  int primerValor; //primer valor del arreglo
  for ( i = 0; i < dim; i++)
  {
    if( i == 0)
      primerValor = array[i];

    if(array[i] != primerValor){
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
void iniciaMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j;
  for(i=0; i<fila; i++){
    for(j=0; j<colum; j++)
      matriz[i][j]= 0;
  }
}

/**
 * @brief Carga valores en una matriz de dimensiones dadas
 * 
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser cargada
 */
void cargaMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j, aux;
  for(i=0; i<fila; i++){
    for(j=0; j<colum; j++){
      scanf("%d", &aux);
      matriz[i][j]= aux;
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
void copiaPrimerafilaEnMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j, aux;
  /* solicita que  si ingrese la primera fila del arreglo */
  for (j = 0; j<colum; j++){  
    scanf("%d", &aux);
    matriz[0][j]= aux;
  }

  /* copia los valores de la primera fila en el resto de la matriz */
  for(i=1; i<fila; i++){
    for(j=0; j<colum; j++){
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
int hayCerosEnMatriz(int fila, int col, int matriz[][col])
{  
  int i, j;
  for( i = 0;i<fila; i++){
    for ( j = 0; j < col; j++)
    {
      if( matriz[i][j] == 0){
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
int esHermosa( int fila, int columna, int matriz[][columna])  
{
  
  int isBeauty = 0; //presuponemos que es hermmosa
  if(fila != columna){
    printf("No es Cuadrada\n");
    return 1; //para se hermosa debe ser cuadrada

  }
  int i;
  int sumadeFilas[fila];
  int sumadeColumnas[columna];

  sumaDeColumnas( fila,  columna,  matriz, sumadeColumnas);
  sumaDeFilas( fila,  columna,  matriz, sumadeFilas);

  if( sumadeColumnas[0] != sumadeFilas[0] || esMonotona(sumadeColumnas, fila) != 0 || esMonotona(sumadeColumnas, columna) != 0)
      return -1; //si la condicion de arriba se cumple sabemos que no es monotna y devolvemos -1
  

  if (sumaDiagonalPrincipal(fila, columna, matriz) != sumaDiagonalSecundaria(fila, columna, matriz))
  {
    return -1; //si la condicion de arriba se cumple sabemos que no es monotna y devolvemos -1
  }
  
  return isBeauty;
}

/**
 * @brief Agrega en una Arreglo la suma de cada Columan de una matriz
 * 
 * @param fila Cantidad de filas
 * @param col Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @param sumaCol Arreglo de sumas
 */
void sumaDeColumnas(int fila, int col , int matriz[][col], int sumaCol[]) 
{
  int i, j, acum = 0;
  for(i = 0; i< col; i++){
    for ( j = 0; j < fila; j++)
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
void sumaDeFilas(int fila, int col , int matriz[][col], int sumaFilas[])
{
  int i, j, acum = 0;
  for(i = 0; i< fila; i++){
    for ( j = 0; j < col; j++)
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
  for ( i = 0; i < fila; i++)
  {
    for ( j = 0; j < columna; j++)
    {
      if ( i == j)
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
  if( fila != columna)
    return 'x';
  

  int i,j, acum = 0;
  for ( i = 0; i < fila; i++)
  {
    for ( j = 0; j < columna; j++)
    {
      if( i+j == fila-1)
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
void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]){
  int i;
  int j;

  /* printf("\n\nEste es el tablero:\n\n "); */
  for ( i = 0; i < filas; i++ )
  { 
    for ( j = 0; j < columnas; j++)
    { 
      printf(" %d\t",  Matriz[i][j]);
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

  int i,j;
  int val;
  for( i = 0; i< fila; i++){
    for( j = 0; j < columna ; j++){
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
void digitosInt( int arreglo[], int valor){
  int longitud = 9; /* un int solo puede almacenar numeros de hasta 9 digios */
  int cont = 0, digito;
  while(valor!=0)
  {
  digito=valor%10;
  arreglo[cont] = digito;
  valor=valor/10;
  cont++;
  }
}