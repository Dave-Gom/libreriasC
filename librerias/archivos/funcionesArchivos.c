#include"archivos.h"


/**
 * @brief crea un arichivo y devuelve su apuntador
 * 
 * @return FILE* 
 */
Archivo *creaArchivo(){ 

  char nombreArchivo[150] = "";
  char modo[5] = "";
  Archivo *ptrNuevoArchivo = NULL; //inicializa el puntero al archivo en null
  
  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo);//ingresa el nombre y formato del archivo
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo); //ingresa el formato de apertura del archivo
  if( (ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, modo)) == NULL){
    printf("No se pudo crear el archivo.\nERROR\n");//retorna null si no se pudo abrir el archivo
    return NULL;
  }
  else
  {
    ptrNuevoArchivo->cantidadElementos = 0; //establece en cero la cantidad de elementos
    return ptrNuevoArchivo; //retorna el puntero al archivo si hubo exito
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
  Archivo *ptrNuevoArchivo = NULL; //inicializa el puntero al archivo en null
  
  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo);//ingresa el nombre y formato del archivo
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo); //ingresa el formato de apertura del archivo
  if( (ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, modo)) == NULL){
    if( (ptrNuevoArchivo = fopen(nombreArchivo, "wb+")) != NULL){
      ptrNuevoArchivo->cantidadElementos = 0;
      return ptrNuevoArchivo; //retorna el puntero al archivo si hubo exito
    }
    else
    {
      printf("No se pudo Abir Ni crear el archivo");
      return NULL;
    }
    
  }
  else
  {
    if(strcmp("w", modo) == 0){
      fclose(ptrNuevoArchivo->punteroArchivo);
      ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, "rb+");
      ptrNuevoArchivo->cantidadElementos = 0;
      return ptrNuevoArchivo;
    }
    else
      ptrNuevoArchivo->cantidadElementos = 0;
      return ptrNuevoArchivo; //retorna el puntero al archivo si hubo exito
  }
  
}

/**
 * @brief Recibe el apuntador a un registro y lo guarda en el archivo
 * 
 * @param ptrArchivo Puntero a estructura de Tipo Archivo
 * @param aGuardar Registro a ser guardado en el archivo
 */
void guardaRegistroEnArchivo( Archivo *ptrArchivo, RegistroArchivo *aGuardar)
{
  if(aGuardar->estaEliminado == 0){ //si el archivo no ha sido eliminado logicamente
    fseek( ptrArchivo->punteroArchivo, ( aGuardar->id -1 ) *sizeof( RegistroArchivo ), SEEK_SET );//establece el apuntador a la posicion del numero de cuenta del nuevo Registro
    fwrite( aGuardar, sizeof(  RegistroArchivo ), 1, ptrArchivo->punteroArchivo ); //escribe el contenido del registro nuevo en la direccion especificada
    rewind(ptrArchivo->punteroArchivo);
  }
  else{
    printf("No se puede Guardar un archivo dado de Baja");  
  }
}


/**
 * @brief Crea un nuevo registro y lo inserta en el archivo
 * 
 * @param ptrArchivo Puntero al archivo destino
 */
void nuevoRegistro( Archivo *ptrArchivo){

  RegistroArchivo nuevoRegistro, auxRegistro = { 0, 1, {0}};

  nuevoRegistro.Dato = creaRegistro(); // crea un nuevo registro 

  fseek( ptrArchivo->punteroArchivo, (nuevoRegistro.id -1) * sizeof(RegistroArchivo), SEEK_SET); //establece el apuntador a la posicion del numero de cuenta del nuevo Registro
  fread( &auxRegistro, sizeof( RegistroArchivo ), 1, ptrArchivo->punteroArchivo ); //almacena la lectura del puntero del archivo al registro auxiliar

  if( auxRegistro.id != 0 && auxRegistro.estaEliminado != 1 ){ // si la cuenta del reigistro ya existe, o si existe y no esta esliminado
    printf("\nERROR: La cuenta %d Ya existe\n", auxRegistro.id);
  }
  else{ //sino, guarda el nuevo registro en esa direccion

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
void eliminaRegistro(Archivo *ptrArchivo){

  RegistroArchivo registroAux; 
  RegistroArchivo regEnBlanco = { 0, 0 , {0} }; // tambien podemos hacer un borrado Logico estableciendo en valor de la id a -1

  int id;
  printf("Introduzca el id a Eliminar: ");
  scanf("%d", &id); 

  fseek( ptrArchivo->punteroArchivo, ( id - 1) * sizeof( RegistroArchivo), SEEK_SET);//situa el apuntador a la direccion del registro a eliminar
  fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);//lee el registro

  if (registroAux.estaEliminado == 1) //verifica si el archivo ya esta vacio de antemano
  {
    printf("El registro %d no existe", id);
  }
  else //edita el archivo
  {
    regEnBlanco.id = id;
    guardaRegistroEnArchivo(ptrArchivo, &regEnBlanco);//guarda un registro en blanco en la id especificada
    ptrArchivo->cantidadElementos--;
    printf("\n\tRegistro Eliminado Exitosamente\n");//mensaje de exito
  }
  
}

/**
 * @brief Inicializar los valores a editar del  
 * 
 * @param ptrArchivo 
 */
void actualizaRegistro( Archivo * ptrArchivo){


  RegistroArchivo registroAux;
  int id;
  Registro NuevosDatos;

  printf("Introduzca id del registro a actualizar"); //este debe ser un identificador para el registro del archivo.
  scanf("%d", &id); //solicita el numero de cuenta a editar

  fseek(ptrArchivo->punteroArchivo, (id -1 )*sizeof(RegistroArchivo), SEEK_SET); //establece el apuntado al registro a editar
  fread( &registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo); //lee el registro a editar en el registro auxiliar

  if( registroAux.estaEliminado == 1 ){ 
    printf("\nLa cuenta #%d no tiene informacion\n", registroAux.id);
  }
  else
  {
    imprimeRegistro(registroAux.Dato); //imprime el registro
    printf("Introduzaca los nuevos Valores\n");
    NuevosDatos = creaRegistro();
    registroAux.Dato = NuevosDatos;
    guardaRegistroEnArchivo(ptrArchivo, &registroAux);
  }
  
}



/**
 * @brief Crea un archivo de texto con formato para impresión 
 * Obs: la definicion del archivo depende de los requerimientos del programa.
 * 
 * 
 * @param ptrArchivo 
 */
void informeTxt(Archivo *ptrArchivo){

  FILE *ptrInforme; //apuntador al archivo Resultado

  RegistroArchivo datos = { 0, 1, {0}}; //inicializar aqui el registro,

  if( (ptrInforme = fopen("Informe.txt", "w")) == NULL )
    printf("\n\tERROR: No se pudo crear el Archivo\n\n");
  else
  {
    rewind(ptrArchivo);//establece el puntero al principio del archivo
    fprintf(ptrInforme, "%s\t%s\t%s\t%s\t%s\n","id.","entero", "nombre","flotante","caracter");//imprime la cabecera. Esto depende de los campos a imprimir del registro
    while (!feof(ptrArchivo)){

      fread(&datos, sizeof(RegistroArchivo), 1, ptrArchivo);//lee los datos en el Registro datos
      if( datos.id != -1){

        /* fprintf(ptrInforme, "%d\t%d\t%s\t%3.f\t%c\n",datos.id, datos.entero, datos.nombre, datos.datoFlotante, datos.caracter); */  //imprime los datos en el arvhivo informe

      }else
      {
        printf("No se leyo Nada\n");//informa que no se pudo leer nada desde el archivo origen
        break;
      }

    }
    
    fclose(ptrInforme);//cierra el archivo de informe
    printf("\n\tInforme Generado exitosamente!\n\n");
  }
  
}

/**
 * @brief recibe una Lista y guarda los registros en un archivo desde la cabeza de la lista
 * 
 * @param ptrArchivo Puntero a estructura de archivo de destino
 * @param ListaDatos Lista a ser almacenada en el archivo
 */
void guardaDesdeCabezaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos){

  Nodo *ptrNodoObjetivo = ListaDatos.cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    guardaRegistroEnArchivo( ptrArchivo, &ptrNodoObjetivo->dato);
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
}


/**
 * @brief recibe una Lista y guarda los registros en un archivo desde la cola de la lista
 * 
 * @param ptrArchivo Puntero a estructura de archivo de destino
 * @param ListaDatos Lista a ser almacenada en el archivo
 */
void guardaDesdeColaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos){
  Nodo *ptrNodoObjetivo = ListaDatos.cola;
  while ( ptrNodoObjetivo != NULL)
  {
    guardaRegistroEnArchivo( ptrArchivo, &ptrNodoObjetivo->dato);
    ptrNodoObjetivo = ptrNodoObjetivo->ante;
  }
}
