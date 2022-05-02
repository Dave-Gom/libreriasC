#include"pruebas.h"

typedef struct DATO{ //aqui definir los datos a almacenarse en la lista
  int id;
  int entero; //entero
  char *nombre; //nombre
  float datoFlotante; //doble
  char caracter; //caracter

}Registro;


typedef struct NODO{
  Registro dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Lista; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

Nodo *creaNodo( Registro dato); // crea un nodo de una lista y devuelve su direccion en memoria
Registro creaRegistroAleatorio();// crea un registro nuevo, lee sus valor y devuelve una copia
void guardaRegistroEnArchivo( FILE *ptrArchivo, Registro *aGuardar);
FILE *creaArchivoBin(); 
void informeTxt(FILE *ptrArchivo);
void insertarEnCola( Registro dato, Lista *listaDestino);//Inserta Por la cola de la lista (tabien valido para Colas)
int listaEstaVacia( Lista ListaVal);
void imprimeRegistro(Registro datos);
void imprimeDesdeLaCabeza( const Lista *listaObjetivo);

void insertaEnListaDesdeArchivo(Lista *, FILE*);//carga los registros del archivo en una lista, pila o cola dependiendo de como se trate la lista enlazada
void cargaRegistrosAleatoriosEnArchivo( FILE *ptrArchivo);
void guardaColaEnArchivo(FILE *ptrArchivo, Lista ListaDatos);

int main()
{
  int cantidad;

  FILE *archivoPrueba = creaArchivoBin();
  Lista ListaO = {NULL, NULL, 0};
  FILE *archivoDos = NULL;
  if(archivoPrueba != NULL){
    cargaRegistrosAleatoriosEnArchivo(archivoPrueba);
    printf("Cargado con exito\n");
    informeTxt(archivoPrueba);
    insertaEnListaDesdeArchivo(&ListaO, archivoPrueba);
    imprimeDesdeLaCabeza(&ListaO);
    archivoDos = fopen("archivoDos", "w");
    guardaColaEnArchivo( archivoDos, ListaO);
  }
  return 0;
}

Nodo *creaNodo( Registro dato){ // crea un nodo de una lista y devuelve su direccion en memoria
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

void cargaRegistrosAleatoriosEnArchivo( FILE *ptrArchivo){
  int cantidad, iterador;
  Registro nuevoRegistro = { -1, 0, "", 0.0, '\n'};//inicializo los valore -1 para indicar registro vacio;
  printf("Ingrese la cantidad de datos a ingresar:");
  scanf("%d", &cantidad);
  for ( iterador = 0; iterador < cantidad; iterador++)
  {
    nuevoRegistro = creaRegistroAleatorio();
    nuevoRegistro.id = iterador;
    guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistro); //guardo el registro en el archivo
  }
  
}

Registro creaRegistroAleatorio(){ // crea un registro nuevo con datos aleatorios y devuelve una copia

  Registro *ptrNuevoRegistro = malloc( sizeof( Registro)); // libera espacio en memoria para el nuevo registro
  ptrNuevoRegistro->entero = enteroAleatorio(INT32_MAX);
  ptrNuevoRegistro->datoFlotante = flotanteAleatorio();
  ptrNuevoRegistro->nombre = cadenaAleatoriaLongAleatoria();
  ptrNuevoRegistro->caracter = caracterAleatorio();
  printf("cadena aleatoria: %s\n", ptrNuevoRegistro->nombre);
  return *ptrNuevoRegistro; // retorna una copia del registro creado
}

void guardaRegistroEnArchivo( FILE *ptrArchivo, Registro *aGuardar)
{

    fseek( ptrArchivo, ( aGuardar->id ) *sizeof( Registro ), SEEK_SET );//establece el apuntador a la posicion del numero de cuenta del nuevo Registro
    fwrite( aGuardar, sizeof(  Registro ), 1, ptrArchivo ); //escribe el contenido del registro nuevo en la direccion especificada
}

FILE *creaArchivoBin()
{ //crea un arichivo y devuelce su apuntador

  char nombreArchivo[150] = "";
  char modo[5] = "";
  FILE *ptrNuevoArchivo = NULL; //inicializa el puntero al archivo en null
  
  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo);//ingresa el nombre y formato del archivo
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo); //ingresa el formato de apertura del archivo
  if( (ptrNuevoArchivo = fopen(nombreArchivo, modo)) == NULL){
    if( (ptrNuevoArchivo = fopen(nombreArchivo, "wb+")) == NULL)
      return ptrNuevoArchivo; //retorna el puntero al archivo si hubo exito
    else
    {
      printf("No se pudo Abir Ni crear el archivo");
      return NULL;
    }
    
  }
  else
  {
    if(strcmp("w", modo) == 0){
      fclose(ptrNuevoArchivo);
      ptrNuevoArchivo = fopen(nombreArchivo, "rb+");
      return ptrNuevoArchivo;
    }
    else
      return ptrNuevoArchivo; //retorna el puntero al archivo si hubo exito
  }
  
}

/* crea un archivo de texto con formato para impresión */
void informeTxt(FILE *ptrArchivo){

  FILE *ptrInforme; //apuntador al archivo Resultado

  Registro datos = { -1, 0, "", 0.0, '\n'};//inicializa

  if( (ptrInforme = fopen("Informe.txt", "w")) == NULL )
    printf("\n\tERROR: No se pudo crear el Archivo\n\n");
  else
  {
    rewind(ptrArchivo);//establece el puntero al principio del archivo
    fprintf(ptrInforme, "%s\t%s\t%s\t%s\t%s\n","id.","entero", "nombre","flotante","caracter");//imprime la cabecera
    while (!feof(ptrArchivo)){

      fread(&datos, sizeof(Registro), 1, ptrArchivo);//lee los datos en el Registro datos
      if( datos.id != -1){

        fprintf(ptrInforme, "%d\t%d\t%s\t%3.f\t%c\n",datos.id, datos.entero, datos.nombre, datos.datoFlotante, datos.caracter);//imprime los datos en el arvhivo informe

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

void insertaEnListaDesdeArchivo(Lista *ptrListaObjetivo, FILE* ptrArchivoFuente){//carga los registros del archivo en una lista, pila o cola dependiendo de como se trate la lista enlazada
  Registro datos = {-1, 0, "", 0.0 ,'\n'};//inicializa el registro datos
  
  rewind(ptrArchivoFuente);
  while (!feof(ptrArchivoFuente))
  {
    fread(&datos, sizeof(Registro), 1, ptrArchivoFuente);
    if( datos.id != -1){
      insertarEnCola( datos, ptrListaObjetivo);
    }
  }
  

}

void insertarEnCola( Registro dato, Lista *listaDestino){ //Inserta Por la cola de la lista (tabien valido para Colas)
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

/* Estructuras de datos Listas, Pilas y Colas */
int listaEstaVacia( Lista ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
}

void imprimeRegistro(Registro datos){
  printf("{ %d|%d|%s|%.3f|%c }", datos.id, datos.entero, datos.nombre, datos.datoFlotante, datos.caracter);
}

void imprimeDesdeLaCabeza( const Lista *listaObjetivo){ //imprime una lista desde la cabeza (tambien valido para una Cola)
  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    imprimeRegistro(ptrNodoObjetivo->dato);
    printf("-> ");
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
  printf("NULL\n");
}

void guardaColaEnArchivo(FILE *ptrArchivo, Lista ListaDatos){
  Nodo *ptrNodoObjetivo = ListaDatos.cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    guardaRegistroEnArchivo( ptrArchivo, &ptrNodoObjetivo->dato);
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
}