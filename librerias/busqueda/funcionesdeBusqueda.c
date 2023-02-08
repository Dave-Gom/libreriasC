#include"busqueda.h"


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
int busquedaLineal(  int arreglo[], const int longitud, int valorABuscar){
  int i, bandera = 0;
  for ( i = 0; i< longitud; i++){
    if(arreglo[i] == valorABuscar){
      bandera = 1;
      break;
    }
  }

  if(bandera == 0)
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
int busquedaBinaria( int arreglo[], int valBuscado, int inicio, int fin){
  int central;
  while( inicio <= fin){

    central = ( inicio + fin)/2;

    if( valBuscado == arreglo[central]){
      return central;
    }
    else if( valBuscado < arreglo[central]){
      fin = central -1;
    }
    else
    {
      inicio = central +1;
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
int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha){
    if (izquierda > derecha) return -1;
 
    int indiceDeLaMitad = ((izquierda + derecha) / 2);
 
    int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
    if (busqueda == valorQueEstaEnElMedio){
        return indiceDeLaMitad;
    }
    
    if (busqueda < valorQueEstaEnElMedio){
        // Entonces está hacia la izquierda
        derecha = indiceDeLaMitad - 1;
    }else{
        // Está hacia la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}
