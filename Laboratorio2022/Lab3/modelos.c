#include<stdio.h>
#define TAMANIO 10



int cantidadHermososEnArreglo(int arreglo[], int);
void cargaVector( int arreglo[], int lenght);

void main(){
  int modelos[TAMANIO] = {0};
  int compras[10] = {0};
  int t, n, iterador;
  scanf("%d", &t);
  for( iterador = 0; iterador<t; iterador++ ){
    printf("cantidad ");
    scanf("%d", &n);
    cargaVector( modelos , n);
    compras[iterador] = cantidadHermososEnArreglo( modelos , n);
    
  }

  for( iterador = 0; iterador<t; iterador++ ){
    printf("%d\n", compras[iterador]);
  }
  
  system("pause");
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
          if( (j+1) % (i+1) == 0 && arreglo[i]<arreglo[j] ){
            contador++;
            printf( "i= %d  j=%d \n", arreglo[i], arreglo[j]);
          }
        }
      }
    }
  }

}


void cargaVector( int arreglo[], int lenght){
  int iterador, valor;

  for(iterador = 0; iterador<lenght; iterador ++){
    scanf("%d", &valor);
    arreglo[iterador]=valor;
  }

}