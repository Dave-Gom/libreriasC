#include"ordenamiento.h"

/**
 * @brief Ordenamiento de intercambio. Ordena un array en orden ascendente por el metodo de intercambio de variables
 * 
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void ordIntecambio( int arreglo[], int longitud)
{
  int i, //iterador
  j, //iterador
  aux; //contenedor temporal del valor

  for ( i = 0; i < longitud -1; i++) //inicia desde la primera posicion del arreglo hasta la posicion longitud -1
  {
    for ( j = i+1; j < longitud; j++) //inicia desde la segunda posicion de arreglo hasta la ultima posicion
    {
      if (arreglo[i] > arreglo[j]) //si el arreglo de la segunda pisicon i > al de posicion j los intercambia
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
void ordSeleccion( int arreglo[], int longitud) //ejemplo joyanes
{
  printf("seleccion\n");
  int indiceMenor,//pos menor
   i,//iterador
   j;//iterador
  double aux;//contenedor temporal
  for ( i = 0; i < longitud -1; i++)
  {
    indiceMenor = i; //inicial el menor elemento en el principio de cada iteracion

    for ( j = i+1; j < longitud; j++) //empieza a buscar una posicion despues de la posicion de i
    {
      if( arreglo[j] < arreglo[indiceMenor])
        indiceMenor = j; /* situa el elemento menor */
    }
    
    if( i!= indiceMenor){ /* si existia un elemento menor lo intercambia por la posicion actual del puntero */
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
void ordSeleccionRecusiva( int arreglo[], int longitud)
{
  int aux,//contenedor temporal
   posicionMenor;//posicion del elemento menor
  if( longitud >1){
    posicionMenor = posMenor( arreglo, longitud); //determina la posicion del menor elemento del arreglo
    /* intercambia el arreglo de la posicion inicial con el menor  */
    aux = arreglo[0];
    arreglo[0] = arreglo[posicionMenor];
    arreglo[posicionMenor] = aux;
    /*  */

    ordSeleccionRecusiva( &arreglo[1], longitud-1); //recursion con el array a partir de la posicion dos 
  }
}


/**
 * @brief Ordena un arreglo de forma ascendente por el metodo de burbuja
 * 
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void burbuja_asc( int arreglo[], const int longitud){
  int pasadas, i, almacenador;

  for( pasadas = 0; pasadas < longitud; pasadas ++){
    for(i=0; i< longitud -1; i++){
      if( arreglo[i+1]<arreglo[i]){
        almacenador = arreglo[i];
        arreglo[i] = arreglo[i+1];
        arreglo[i+1] = almacenador;
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
void burbuja_des( int arreglo[], const int longitud){
  int pasadas, i, almacenador;

  for( pasadas = 0; pasadas < longitud; pasadas ++){
    for(i=0; i< longitud -1; i++){
      if( arreglo[i+1]>arreglo[i]){
        almacenador = arreglo[i];
        arreglo[i] = arreglo[i+1];
        arreglo[i+1] = almacenador;
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
void quickSort( double array[], int inicio, int fin){
  int i,//iterador
  j, //iterador
  central; //indicador del centro del array
  double pivote;
  central = (inicio + fin)/2; //ubica el centro del array
  pivote = array[central]; //ubica en el valor pivote el valor del elemento central del array
  double temporal;
  do
  {
    while (array[i] < pivote) i++; //ubica el primer elemento menor que el pivote
    while (array[j] > pivote) j++; //ubica el primer elemento mayor que el pivote

    if( i <= j){ //si la posicion del primer elemento mayo y menor, el menr es menor o igual al mayor

      //intercambia los valores
      temporal = array[i];
      array[i] = array [j];
      array[j] = temporal;
      i++; //incrementa la posicion del elemento menor
      j--; //decrementa la posicion del elemento mayor

    }
    
  } while (i<=j); 

  if( inicio <= j){ //si el inico es menor o igual a la posicion del primer elemento mayor al pivote
    quickSort(array, inicio, j); //recursadesde el inicio hasta la posicion
  }

  if( i< fin){//si el inico es menor o igual a la posicion del primer elemento mayor al pivote
    quickSort( array, i, fin); //recursa desde la posicion hasta el fin
  }

}