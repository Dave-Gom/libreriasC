#include"header.h"

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

int cantidadHermososEnArreglo (int arreglo[], int dim){

  int  i, j, contador = 1;
  if( dim == 1){
    contador = 1;
  }
  else{
    for( i = 0; i<dim; i++){
      for( j = i+1; j< dim; j++){
        if( i!=0){
          if( (j+1) % (i+1) == 0 && arreglo[i]<arreglo[j] && (i+1)!=0){
            contador++;
          }
        }
      }
    }
  }

  return contador;
}

void imprimeArreglo( int arreglo[], int longitud){
  int i;
  for(i = 0; i<longitud; i++){
    printf("%d", arreglo[i]);
  }
}