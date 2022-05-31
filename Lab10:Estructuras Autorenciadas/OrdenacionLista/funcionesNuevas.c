

void insertaEnOrden( int dato, Lista *listaDestino){

  if(dirMayor(dato, listaDestino) == listaDestino->cabeza){
    insertarEnCabeza(dato, listaDestino);
  }
  else
  {
    if (dirMayor(dato, listaDestino) == listaDestino->cola)
    {
      insertarEnCola(dato, listaDestino);
    }
    else
    {
      /* insertaAntesDe(dirMayor(dato, listaDestino) , dato); */
    }
    
  }
    
  
}

Nodo *dirMayor(int Dato, Lista *listaDestino){ //encuentra la direccion del primer nodo que contenga un dato mayor al valor actual
  Nodo *ptrNodoEvaluado = listaDestino->cabeza;
  while (ptrNodoEvaluado != NULL)
  {
    if(ptrNodoEvaluado->dato > Dato){
      return ptrNodoEvaluado;
    }
    else
      ptrNodoEvaluado = ptrNodoEvaluado->sig;
  }

  return NULL;
  
}


/* void insertaAntesDe( Nodo *nodoMayor, int dato){ //inserta en la lista, detras del nodo especificado
  Nodo *ptrNuevoNodo = creaNodo(dato);

  ptrNuevoNodo->sig = nodoMayor; //asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; //asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
  nodoMayor->ante->sig = ptrNuevoNodo;
  nodoMayor->ante = ptrNuevoNodo;

} */