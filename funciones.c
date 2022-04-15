#include"header.h"

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

/* devuelve la minnima cantidad de pasos necesarios para subir la cima de una escalera teniendo en cuenta que se pueden tomar pasos de 1 o 2 escalonnes a la vez */
int sube_escalera( int n ){
  if( n < 0 )
    return 0;
  if( n == 0 )
    return 1;
  return sube_escalera(n-1) + sube_escalera(n-2);
}

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


/* recibe un digito char del 0 al 9 y devuelve su valor entero */
int charToInt( char caracter){
  return caracter - '0';
}

/* entero a char */
char enteroACaracter(int numero){
    return numero + '0';
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

