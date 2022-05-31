/**
 * @brief Funciones de Manipulacion de Listas Enlazadas
 * 
 * @author Dave Gomez
 */


#include"listas.h"


/**
 * @brief Crea un nodo de una lista y devuelve su direccion en memoria
 * 
 * @param dato Dato a ser insertado en el Nodo, dependiendo del tipo de nodo puede ser un Registro, entero, cadena, o cualquier tipo de dato
 * @return Nodo* 
 * 
 * @author Dave Gomez
 */
Nodo *creaNodo( Registro dato){ 
  Nodo *nuevoNodo = malloc( sizeof ( Nodo));
  if( nuevoNodo != NULL){
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
int listaEstaVacia( Lista ListaVal){ 
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){ //si la cabeza y la cola son iguales a NULL
    return -1;
  }
  else{
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
void insertarDatoEnCabeza( Registro dato, Lista *listaDestino){ 
  Nodo *ptrNuevoNodo = creaNodo(dato); //crea el nodo con el dato

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else{ // si la lista no esta vacia
      ptrNuevoNodo->sig = listaDestino->cabeza; //asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
      listaDestino->cabeza->ante = ptrNuevoNodo; //asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
      listaDestino->cabeza = ptrNuevoNodo; //asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
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
void insertarDatoEnCola( Registro dato, Lista *listaDestino){
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
  Nodo *ptrNuevoNodo = creaNodo(dato);

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else{ // si la lista no esta vacia
      ptrNuevoNodo->ante = listaDestino->cola; //asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
      listaDestino->cola->sig = ptrNuevoNodo; //asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
      listaDestino->cola = ptrNuevoNodo; //asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
    }
  }
}

/**
 * @brief Extrae un el dato de la cabeza de la lista y lo retorna
 * 
 * @param listaObjetivo Lista objetivo
 * @return Registro 
 * 
 * @author Dave Gomez
 */
Registro extraerCabeza( Lista *listaObjetivo){ 
  Nodo *ptrNodoObjetivo;
  Registro Dato; //contenedor Auxiliar
  ptrNodoObjetivo = listaObjetivo->cabeza;

  Dato = ptrNodoObjetivo->dato; 
  listaObjetivo->cabeza = ptrNodoObjetivo->sig;
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la lista
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cola = NULL;
  

  free(ptrNodoObjetivo); //libera el espacio en memoria ocupado por el nodo extraido
  return Dato;

}


/**
 * @brief Extrae un el dato de la cola de la lista y lo retorna
 * 
 * @param listaObjetivo Lista objetivo
 * @return Registro 
 * 
 * @author Dave Gomez
 */
Registro extraerCola( Lista *listaObjetivo){ 
  Nodo *ptrNodoObjetivo;
  Registro Dato; //contenedor Auxiliar
  ptrNodoObjetivo = listaObjetivo->cola; //direccion de memoria del nodo a extraer

  Dato = ptrNodoObjetivo->dato; //asigna el dato de la cola al registro contenedor
  listaObjetivo->cola = ptrNodoObjetivo->ante; //asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida
  
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la lista
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cabeza = NULL;
  else
    listaObjetivo->cola->sig = NULL; //elimina la direccion de memoria del apuntador siguiente de la cola actual
  
  free(ptrNodoObjetivo); //libera el espacio en memoria ocupado por el nodo extraido
  return Dato;

}

/**
 * @brief Imprime una lista desde la cabeza (tambien valido para una Cola)
 * 
 * @param listaObjetivo Lista a ser impresa
 * 
 * @author Dave Gomez
 */
void imprimeDesdeLaCabeza( const Lista *listaObjetivo){ 
  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    imprimeRegistro(ptrNodoObjetivo->dato); //imprimie el registro asociado al nodo
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
void imprimeDesdeLaCola( const Lista *listaObjetivo){ 

  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cola;
  while ( ptrNodoObjetivo != NULL)
  {
    imprimeRegistro(ptrNodoObjetivo->dato); //imprimie el registro asociado al nodo
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
void imprimeRegistro(Registro datos){
  /* printf("{ %d|%d|%s|%.3f|%c }", datos.id, datos.entero, datos.nombre, datos.datoFlotante, datos.caracter); */ //aqui imprimir el registro dependiendo de los datos que se especifiquen arriba
}

/**
 * @brief Retorna la direccion del primer nodo que contenga un dato mayor al valor recibido como parametro
 * 
 * @param Dato Entero que sera comparado
 * @param listaDestino Lista en la que se buscara
 * @return Nodo* 
 * 
 * @author Dave Gomez
 */
Nodo *dirMayor(int Dato, Lista *listaDestino){ 
  Nodo *ptrNodoEvaluado = listaDestino->cabeza;
  while (ptrNodoEvaluado != NULL)
  {
    if(ptrNodoEvaluado->dato.valor > Dato){ //compara el valor 
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
void insertaDatoAntesDe( Nodo *nodoMayor, Registro dato){
  
  Nodo *ptrNuevoNodo = creaNodo(dato);

  ptrNuevoNodo->sig = nodoMayor; //asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; //asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
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
void insertaNodoAntesDe( Nodo *nodoMayor, Nodo *ptrNuevoNodo){

  ptrNuevoNodo->sig = nodoMayor; //asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; //asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
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
void insertaEnOrden( Registro dato, Lista *listaDestino){

  Nodo *ptrNuevoNodo = creaNodo(dato);

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else
    {
      Nodo *ptrNodoMayor = dirMayor(dato.valor, listaDestino);
      if(ptrNodoMayor == listaDestino->cabeza){
        insertarEnCabeza(dato, listaDestino);
      }
      else
      {
        if (ptrNodoMayor != NULL)
        {
          insertaAntesDe(ptrNodoMayor , dato);
        }
        else
        {
          insertarEnCola(dato, listaDestino);
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
void despliegaMenu(){

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