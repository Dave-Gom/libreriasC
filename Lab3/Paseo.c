#include"header.h"



void main(){

  int k,n, i, min_paseos;
  scanf("%d", &n);
  scanf("%d", &k);
  int b[n];
  int a[n];

  cargaVector(a, n);
  copia_arreglo( a, b, n);

  min_paseos = agendador(b, n, k);

  printf("%d\n", min_paseos);

  for(i=0; i<n; i++){
    printf("%d", b[i]);
  }

}

void cargaVector( int arreglo[], int lenght){
  int iterador, valor;

  for(iterador = 0; iterador<lenght; iterador ++){
    scanf("%d", &valor);
    arreglo[iterador]=valor;
  }

}

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

