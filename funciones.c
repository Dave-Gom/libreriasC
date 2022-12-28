#include"header.h"

/**
 * Funciones para testeo
 * 
 */


void arrayAleatorio( int arreglo[], int longitud, int valorLimite){
  /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* incluir stdlib para usar rand() y time() */
  int i,j;
  srand(time(NULL));
  for ( i = 0; i < longitud; i++)
  {
    arreglo[i] = rand() % valorLimite;
  }
  
}

void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite)
{ /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* incluir stdlib para usar rand() y time() */
  int i,j;
  srand(time(NULL));
  for ( i = 0; i < fila; i++)
  {
    for ( j = 0; j < columna; j++)
    {
      arreglo[i][j] = rand() % valLimite;
    }
    
  }
}

int enteroAleatorio(int limite){//devuelve un numero entero positivo, negativo o cero aleatorio

  int valor1 = (rand() % limite);
  int valor2 = (rand() % limite);

  return valor1-valor2;

}

int enteroAleatorioEntre(int limiteInf, int limiteSup){//devuelve un numero aleatorio entre el limite inferior y el superior

  int valor = limiteInf + (rand() % (limiteSup - limiteInf));
  return valor;

}

float flotanteAleatorio(){//devuelve un numero flotante aleatorio
  //INT32_MAX es el limite maximo de los int de 32 bits
  int numerador = enteroAleatorioEntre(1, INT32_MAX) ; //OPTIENE el numerador de forma aleatoria
  int denominador = 1 + enteroAleatorioEntre( 1, INT32_MAX -1); //OPTIENE el denominador de forma aleatoria el valor no puede ser cero
  float flotante = numerador / denominador;

  return flotante;
}

char caracterAleatorio(){ // devuelve un caracter aleatorio 
  char caracter = enteroAleatorioEntre(61, 122) + '0'; //asigna el valor aleatorio la variable
  return caracter;
}

void cadenaAleatoria( char cadena[], int longitud){ //agrega varacteres aleatorios a la cadena
  int i;
  for ( i = 0; i < longitud-1; i++)
  {
    cadena[i] = caracterAleatorio(); //asigna caracteres de forma aleatoria a la cadena
  }
  cadena[longitud -1] = '\0'; // asigna caracter de escape al ultimo caracter de la cadena
}

char *cadenaAleatoriaLongAleatoria(){ //devuelve el apuntador a una cadena de longitud aleatoria
  int longitud = enteroAleatorioEntre(5, 500);
  char Cadena[longitud];
  cadenaAleatoria(Cadena, longitud);
  return &Cadena[0];
}


/**
 * funciones de lab creo
 * 

 */

int resta_errad(int n){
  int res;
  int ult = n%10;
  if(ult == 0){
    res = n/10;
  }
  else
  {
    res = n-1;
  }
  
  return res;
}

/* devuelve uno cero si todos los digitos del anio son diferentes
caso contrario devuelce -1*/
/* funciona para anios de 4 dijitos pero se puede mejorar */
int is_beautifull_year(int anio){
  int unid, dec, cent, uni_mil, ret = 0;

  unid = anio%10;
  dec = ((anio%100) - unid)/10;
  cent = ((anio %1000)- dec*10 - unid)/100;
  uni_mil = ((anio%10000) - cent*100 - dec*10 - unid)/1000;

  if( unid == dec)
    ret = -1;

  if( unid == cent)
    ret = -1;

  if( unid == uni_mil)
    ret = -1;

  if( cent == dec)
    ret = -1;

  if( uni_mil == dec)
    ret = -1;

  if( uni_mil == cent)
    ret = -1;

  return ret;
}


int calc_pasos(int dist){
  int pos = 0, pasos = 0 ,x = dist;
  while (pos != x)
  {
    if(pos+5 <= x){
      pasos++;
      pos+=5;
      break;
    }
    if(pos+4 <= x){
      pasos++;
      pos+=4;
      break;
    }
    if(pos+3 <= x){
      pasos++;
      pos+=3;
      break;
    }
    if(pos+2 <= x){
      pasos++;
      pos+=2;
      break;
    }
    if(pos+1 <= x){
      pasos++;
      pos+=1;
      break;
    }
  }

  return pasos;
}

/* devuelve la minnima cantidad de pasos necesarios para subir la cima de una escalera teniendo en cuenta que se pueden tomar pasos de 1 o 2 escalonnes a la vez */
int sube_escalera( int n ){
  if( n < 0 )
    return 0;
  if( n == 0 )
    return 1;
  return sube_escalera(n-1) + sube_escalera(n-2);
}


/**
 * @brief funciones de Arreglos
 * 
 */



/* retorna la posicion de un valor dentro de un arreglo, -1 si el 
no se encuentra */
int busqueda_lineal(  int arreglo[], const int longitud, int valorABuscar){
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

/* retorna el mayor elemento de un arreglo */
int mayor( int arreglo[], const int longitud){

  int mayor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      mayor=arreglo[i];

    if( arreglo[i]>mayor)
      mayor = arreglo[i];

  }

  return mayor;
}

/* retorna el menor elemento de un arreglo */
int menor( int arreglo[], const int longitud){

  int menor, i;
  for(i=0; i<longitud; i++){

    if(i==0)
      menor=arreglo[i];

    if( arreglo[i]<menor)
      menor = arreglo[i];

  }

  return menor;
}

/* ordenamiento burbuja ascendente */
void burbujaAsc( int arreglo[], const int longitud){
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


/* inicializa una matriz a cero */
void iniciaMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j;
  for(i=0; i<fila; i++){
    for(j=0; j<colum; j++)
      matriz[i][j]= 0;
  }
}

/* Busqueda binaria */

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


//



/* genera un interador que carga valores en un arrego de dimension dada */
void cargaVector( int arreglo[], const int lenght){
  int iterador, valor;

  for(iterador = 0; iterador<lenght; iterador ++){
    scanf("%d", &valor);
    arreglo[iterador]=valor;
  }

}

/* verifica si el valor actual y el pasado suman una cantidad dada */
int agendador(int arreglo1[], const int dim, const int dias){

  int persecutor = 0, adelantado, contador = 0;
  for( adelantado =1; adelantado<dim; adelantado++)
  {
    while( arreglo1[adelantado]+arreglo1[persecutor] < dias){
      arreglo1[adelantado]++; 
      contador++;   
    }
    persecutor++;
  }

  return contador;
}

void copia_arreglo( int origen[], int destino[], const int dim){
  int i;
  for( i= 0; i<dim; i++){
    destino[i]=origen[i];
  }
}

void cargaMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j, aux;
  for(i=0; i<fila; i++){
    for(j=0; j<colum; j++){
      scanf("%d", &aux);
      matriz[i][j]= aux;
    }

  }
}

void imprimeArreglo( int arreglo[], const int longitud){
  int i;
  for(i = 0; i<longitud; i++){
    printf(" %d\t", arreglo[i]);
  }
}

/* separa los digitos de un entero en un arrayy */
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

/* inicia en cero todos los elementos de un arreglo */
void iniciaArreglo( int arreglo[], const int lingitud){
  int i;
  for(i = 0; i<lingitud; i++){
    arreglo[i] = 0;
  }
}

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



void quickSort( double array[], int inicio, int fin){
  int i,j,central;
  double pivote;
  central = (inicio + fin)/2;
  pivote = array[central];
  double temporal;
  do
  {
    while (array[i] < pivote) i++;
    while (array[j] > pivote) j++;

    if( i <= j){

      temporal = array[i];
      array[i] = array [j];
      array[j] = temporal;
      i++;
      j--;

    }
    
  } while (i<=j);

  if( inicio <= j){
    quickSort(array, inicio, j);
  }

  if( i< fin){
    quickSort( array, i, fin);
  }

}

/* recibe un digito char del 0 al 9 y devuelve su valor entero */
int charToInt( char caracter){
  return caracter - '0';
}

/* entero a char */
char enteroACaracter(int numero){
    return numero + '0';
}


/* imprime recursivamente los caracteres de una cadena en orden inverso */
void inverso( const char * const ptrS )
{
  /* si es el final de la cadena */
  if ( ptrS[ 0 ] == '\0' ) { /* caso base */
    return; 
  } /* fin de if */ 
  else { /* si no es el final de la cadena */ 
    inverso( &ptrS[ 1 ] ); /* paso recursivo */
    putchar( ptrS[ 0 ] ); /* utiliza putchar para desplegar los caracteres */
  } /* end else */
} /* fin de la función inverso */

/* lee una cadena con espacios */
void leeConEspacios( char cadena[] ){
  char c;
  int i = 0;
  while ( (c = getchar() ) != '\n' )
  {
    cadena[i++] = c;
  } 
  
}


/* separa las palabras de un enunciado en un array
los argumentos son ( el array contenedor, el enunciado a dividir, el separador )
 */
void separaParabrasEnArray( char *array[], char enunciado[], char separador[])
{

  int i;
  char *ptrToken = strtok(enunciado, separador);

  while ( ptrToken != NULL)
  {
    array[i++] = ptrToken;
    ptrToken = strtok( NULL, separador);
  }

}


int verificaCeros(int fila, int col, int matriz[][col])  /* Verifica la existencia  de ceros en una matriz, si existe, devuelce -1 si no existen devuelce cero */
{  int i, j;
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

void imprimeCamino( int fila, int col, int a[][col]) /* imprime el camino que recorrio una en una matriz */
{
  int i, j, elem;
  for(elem = 1; elem <= fila*col +1; elem++){
    for ( i = 0; i < fila; i++)
    {
      for ( j = 0; j < col; j++)
      {
        if( a[i][j] == elem){
          printf("%c%d ", getLetra(i+1), j);
        }
      }
    }
  }
}

char getLetra(int val){ /* letras de la A a la H para rempresentar las columnas del tablero de ajedrez */
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


void primeraAparicion ( char exp[], char p) //devuelce la posicion de primera a paricion de un caracter en una cadena
{
  int i;
  for(i = 0; i< strlen(exp); i++){
    if( exp[i] == p){
      printf("%c aparece en la posicion %d\n", p, i);
      break;
    }
  }
}

void vocales( char exp[])//devuelve la cantidada de apariciones de cada vocal en una cadena
{
  int cantidadAparicion[5] = {0}; /* posiciones 0 = a , 1 = e,... 4 = u */
  char vocalesstr[] = "aeiou";
  int longitud, i;
  longitud = strlen(exp);
  for ( i = 0; i < longitud; i++)
  {
    if( exp[i] == 'a' || exp[i] == 'A'){
      cantidadAparicion[0]++;
    }
    if( exp[i] == 'e' || exp[i] == 'E'){
      cantidadAparicion[1]++;
    }
    if( exp[i] == 'i' || exp[i] == 'I'){
      cantidadAparicion[2]++;
    }
    if( exp[i] == 'o' || exp[i] == 'O'){
      cantidadAparicion[3]++;
    }
    if( exp[i] == 'u' || exp[i] == 'U'){
      cantidadAparicion[4]++;
    }
    
  }
  
  for(i = 0; i< 5; i++){
    if( cantidadAparicion[i] != 0){
      printf("la vocal %c aparece %d veces \n su pocentaje de aparicion es %d prociento\n", vocalesstr[i], cantidadAparicion[i], 100*(cantidadAparicion[i]/longitud) );
    }
    else
    {
      printf("La vocal %c no existe o no tiene repeticion\n", vocalesstr[i]);
    }
    
  }
}

void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna])//lee solo digitos del 0 al 9 a una matriz dada
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

int esHermosa( int fila, int columna, int matriz[][columna])  //retorna cero si la matriz es hermosa, 1 en caso contario
{
  /* para que una matriz sea hermosa, 
  la suma de todas sus filas, debe ser igual a la suma de todas sus comumnas es igual a la suma de sus diagonales */

  
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
  for ( i = 0; i < columna; i++)
  {
    if( sumadeColumnas[i] != sumadeFilas[i])
      return 1;
  }

  if (sumaDiagonalPrincipal(fila, columna, matriz) != sumaDiagonalSecundaria(fila, columna, matriz))
  {
    return -1;
  }
  
  return isBeauty;
}



void sumaDeColumnas(int fila, int col , int matriz[][col], int sumaCol[]) /* devuelve en un array la suma de todas las filas de la matriz */
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

void sumaDeFilas(int fila, int col , int matriz[][col], int sumaFilas[]) /* devuelve en un array la suma de todas las filas de la matriz */
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

void ordIntecambio( int arreglo[], int longitud)
{
  int i, j, aux;

  for ( i = 0; i < longitud -1; i++)
  {
    for ( j = i+1; j < longitud; j++)
    {
      if (arreglo[i] > arreglo[j])
      {
        aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
      }
      
    }
    
  }
  
}

void ordSeleccionRecusiva( int arreglo[], int longitud)
{
  int aux, posicionMenor;
  if( longitud >1){
    posicionMenor = posMenor( arreglo, longitud);
    aux = arreglo[0];
    //printf("%d\n", arreglo[posicionMenor]);
    arreglo[0] = arreglo[posicionMenor];
    arreglo[posicionMenor] = aux;
    ordSeleccionRecusiva( &arreglo[1], longitud-1);
  }
}

/* retorna la posicion  del menor elemento de un arreglo */
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

void ordSeleccion( int arreglo[], int longitud) //ejemplo joyanes
{
  printf("seleccion\n");
  int indiceMenor, i,j;
  double aux;
  for ( i = 0; i < longitud -1; i++)
  {
    indiceMenor = i;

    for ( j = i+1; j < longitud; j++)
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
 * @brief 
 * 
 * @param datos 
 * @return * Estructuras Autoreferenciadass
 */


/* void imprimeRegistro(Registro datos){
  printf("{ %d|%d|%s|%.3f|%c }", datos.id, datos.entero, datos.nombre, datos.datoFlotante, datos.caracter); //aqui imprimir el registro dependiendo de los datos que se especifiquen arriba
}

int listaEstaVacia( Lista ListaVal){ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
} */

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

void insertarEnCabeza( Registro dato, Lista *listaDestino){ //Inserta Por la cabeza de la lista (tambien valido para pila)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
   /* obs: para una pila, si inserto desde la cabeza tambien debo leer desde la cabeza */
  Nodo *ptrNuevoNodo = creaNodo(dato);

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

void imprimeDesdeLaCabeza( const Lista *listaObjetivo){ //imprime una lista desde la cabeza (tambien valido para una Cola)
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

void imprimeDesdeLaCola( const Lista *listaObjetivo){ //imprime una lista desde la Cola (tambien valido para una Pila)
  /* obs: para una pila, si leo desde la cola es porque cargue los datos desde la cola */

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

void despliegaMenu(){ // Operaciones basicas con Listas
  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Lista\n");
  printf("2 - Imprimir la Lista\n");
  printf("3 - Salir\n");
  printf("Su Opcion = ");

}

Registro extraerCabeza( Lista *listaObjetivo){ 
  Nodo *ptrNodoObjetivo;
  Registro Dato; //contenedor Auxiliar
  ptrNodoObjetivo = listaObjetivo->cabeza;

  Dato = ptrNodoObjetivo->dato; 
  listaObjetivo->cabeza = ptrNodoObjetivo->sig;
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la lista
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cola = NULL;
  
  return Dato;

}

/**
 * FUnciones de archivos
 * 
 * 
 * 
 */

void menuArchivos(){ //despliega el menu
  printf("Selecciones su opcion\n1- Informe EN archivo txt.\n2-AcualizarUnRegistro\n3-Agregar Un Registro.\n4- Eliminar un registro \n5-Salir Del Programa.\nOpcion=");
}

FILE *creaArchivo(){ //crea un arichivo y devuelce su apuntador

  char nombreArchivo[150] = "";
  char modo[5] = "";
  FILE *ptrNuevoArchivo = NULL; //inicializa el puntero al archivo en null
  
  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo);//ingresa el nombre y formato del archivo
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo); //ingresa el formato de apertura del archivo
  if( (ptrNuevoArchivo = fopen(nombreArchivo, modo)) == NULL){
    printf("No se pudo crear el archivo.\nERROR\n");//retorna null si no se pudo abrir el archivo
    return NULL;
  }
  else
  {
    return ptrNuevoArchivo; //retorna el puntero al archivo si hubo exito
  }
  
}


Registro creaRegistro(){ // crea un registro nuevo, lee sus valor y devuelve una copia

  Registro *ptrNuevoRegistro = malloc( sizeof( Registro)); // libera espacio en memoria para el nuevo registro

  printf("Funcion Crear Nuevo Registro\n");
  ptrNuevoRegistro->id = 0;
  printf("Ingrese Numero De cuenta: ");
  scanf("%d", &ptrNuevoRegistro->numeroCuenta);
  printf("Ingrese El nombre del Propietario de la Cuenta: ");
  scanf("%s", ptrNuevoRegistro->nombre);
  printf("ingrese EL estado de la cuenta: ");
  scanf("%lf", &ptrNuevoRegistro->estadoDeCuenta);

  return *ptrNuevoRegistro; // retorna una copia del registro creado
}


void nuevoRegistro( FILE *ptrArchivo){

  Registro nuevoRegistro, auxRegistro = { 0, 0, "", 0};

  nuevoRegistro = creaRegistro(); // crea un nuevo registro 

  fseek( ptrArchivo, (nuevoRegistro.numeroCuenta) * sizeof(Registro), SEEK_SET); //establece el apuntador a la posicion del numero de cuenta del nuevo Registro
  fread( &auxRegistro, sizeof( Registro ), 1, ptrArchivo ); //almacena la lectura del puntero del archivo al registro auxiliar

  if( auxRegistro.numeroCuenta != 0 ){ // si la cuenta del reigistro ya existe
    printf("\nERROR: La cuenta %d Ya existe\n", auxRegistro.numeroCuenta);
  }
  else{ //sino, guarda el nuevo registro en esa direccion
    fseek( ptrArchivo, (nuevoRegistro.numeroCuenta) * sizeof(Registro), SEEK_SET);  //establece el apuntador a la posicion del numero de cuenta del nuevo Registro
    fwrite( &nuevoRegistro, sizeof( Registro ), 1, ptrArchivo ); //escribe el contenido del registro nuevo en la direccion especificada
    printf("\nRegistro Agregado Exitosamente!\n\n");
    rewind(ptrArchivo);
  }

}

void actualizaRegistro(FILE * ptrArchivo){
  /* inicializar los valores a editar del  */

  Registro registroAux;
  int cuenta;
  double transaccion;

  printf("Introduzca los el numero de cuenta para actualizar: ");
  scanf("%d", &cuenta); //solicita el numero de cuenta a editar

  fseek(ptrArchivo, (cuenta)*sizeof(Registro), SEEK_SET); //establece el apuntado al registro a editar

  fread( &registroAux, sizeof(Registro), 1, ptrArchivo); //lee el registro a editar en el registro auxiliar

  if( registroAux.numeroCuenta == 0 ){ // si el registro auxiliar tiene cuenta cero esta vacio
    printf("\nLa cuenta #%d no tiene informacion\n", registroAux.numeroCuenta);
  }
  else
  {
    printf( "Numero de cuenta: %d\nNombre Titular: %s\nSaldo: %lf\n\n",
      registroAux.numeroCuenta,
      registroAux.nombre, registroAux.estadoDeCuenta 
    ); //Imprime con formato los datos de la cuenta
    printf("Intruduzca el cargo (+) o el pago (-): ");//Aqui debe ingresarse los campos a modificar
    scanf("%lf", &transaccion);//solicita el ingreso del valor a modificar
    /**
     * aqui se podrian editar los campos que deseemos
     * 
     * 
     */

    registroAux.estadoDeCuenta = registroAux.estadoDeCuenta + transaccion;

    fseek(ptrArchivo, (cuenta)*sizeof(Registro), SEEK_SET); //situa el apuntador a la direccion del registro a editar
    fwrite( &registroAux, sizeof( Registro), 1, ptrArchivo); // escribe el registro auxiliar ya editado en la direccion
    printf("\n Cuenta actualizada Correctamente!\nSaldo actual:%lf\n\n", registroAux.estadoDeCuenta); //mensaje de exito


  }
  
}

void eliminaRegistro(FILE *ptrArchivo){ //establece en blanco un registro en el archivo

  Registro registroAux; 
  Registro regEnBlanco = { 0, 0, "", 0}; // tambien podemos hacer un borrado Logico estableciendo en valor de la id a -1

  int numeroCuenta;
  printf("Introduzca el numero de Cuenta a Eliminar: ");
  scanf("%d", &numeroCuenta); //solicita el numero de cuenta a eliminar

  fseek( ptrArchivo, ( numeroCuenta - 1) * sizeof( Registro), SEEK_SET);//situa el apuntador a la direccion del registro a eliminar
  fread(&registroAux, sizeof(Registro), 1, ptrArchivo);//lee el registro

  if (registroAux.id == 0 && registroAux.numeroCuenta == 0) //verifica si el archivo ya esta vacio de antemano
  {
    printf("La cuenta %d no existe", numeroCuenta);
  }
  else //edita el archivo
  {
    fseek( ptrArchivo, ( numeroCuenta - 1) * sizeof( Registro), SEEK_SET);
    fwrite(&regEnBlanco, sizeof(Registro), 1, ptrArchivo);
    printf("\n\tRegistro Eliminado Exitosamente\n");//mensaje de exito
  }
  
}


/* crea un archivo de texto con formato para impresión */
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

void guardaColaEnArchivo(FILE *ptrArchivo, Lista ListaDatos){
  Nodo *ptrNodoObjetivo = ListaDatos.cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    guardaRegistroEnArchivo( ptrArchivo, &ptrNodoObjetivo->dato);
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
}

void extraerCabeza( Pila *listaObjetivo){ //no se necesita leer ni imprimir nada, simplemente saca  una apertura de parentesis de la pila //para otros casos se puede retornar el valor contenido en el nodo Cabeza
  
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  listaObjetivo->cabeza = ptrNodoObjetivo->sig;
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la pila
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cola = NULL;

}

void insertaEnOrden( Registro dato, Lista *listaDestino){

  Nodo *ptrNuevoNodo = creaNodo(dato);

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else
    {
      Nodo *ptrNodoMayor = dirMayor(dato, listaDestino);
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

void insertaAntesDe( Nodo *nodoMayor, Registro dato){ //inserta en la lista, detras del nodo especificado
  
  Nodo *ptrNuevoNodo = creaNodo(dato);

  ptrNuevoNodo->sig = nodoMayor; //asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
  ptrNuevoNodo->ante = nodoMayor->ante; //asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
  nodoMayor->ante->sig = ptrNuevoNodo;
  nodoMayor->ante = ptrNuevoNodo;

}