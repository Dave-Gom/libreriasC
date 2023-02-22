#include<stdio.h>
void copiaPrimerafilaEnMatriz( const int fila, const int colum, int matriz[][colum] );
void imprimeMatriz(const int fila, const int colum, int matriz[][colum] );
void main(){
  int n, t, i, j, l, mayor, contador = 0, anterior;
  scanf("%d", &t);
  scanf("%d", &n);
  int matriz[n][t];
  copiaPrimerafilaEnMatriz(n,t,matriz);
  mayor =0;
  for( l = 0 ; l<n ; l++){
    anterior = matriz[0][l];
    contador = 0;
    for(i = 0; i<t; i++){

      if( i = 0){
        j = l;
      }
      else  {
        j = 0;
      }
     
      for(j; j<n; i++){
        if( matriz[i][j]> anterior){
          contador++;
          anterior = matriz[i][j];
        }
      }
    }
    if( contador > mayor){
      mayor = contador;
    }
  }

  imprimeMatriz(n,t,matriz);
  printf("\n%d\n", mayor);
  system("pause");
}

void copiaPrimerafilaEnMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j, aux;
  for (j = 0; j<colum; j++){  
    scanf("%d", &aux);
    matriz[0][j]= aux;
  }

  for(i=1; i<fila; i++){
    for(j=0; j<colum; j++){
      matriz[i][j] = matriz[0][j];
    }
  }
}

void imprimeMatriz(const int fila, const int colum, int matriz[][colum] ){
  int i,j;
  
  for(i=0; i<fila; i++){
    for(j=0; j<colum; j++){
      printf("%d", matriz[i][j]);
    }
  }
}