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
caso contrario devuelce -1 */
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
void cargaVector( int arreglo[], int lenght){
  int iterador, valor;

  for(iterador = 0; iterador<lenght; iterador ++){
    scanf("%d", &valor);
    arreglo[iterador]=valor;
  }

}

/* verifica si el valor actual y l pasado suman una cantidad dada */
int agendador(int arreglo1[], int dim, int dias){

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

void copia_arreglo( int origen[], int destino[], int dim){
  int i;
  for( i= 0; i<dim; i++){
    destino[i]=origen[i];
  }
}