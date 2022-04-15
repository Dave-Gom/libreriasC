#include<stdio.h>

void main(){
  
  /* int array[] = {2, 3, 7, 20, 100, 120, 150, 200, 5000};
  int *p = array;
  printf("%d\n", **A[1]); */

  float x;
  x = 2%2+2*2-2/2;
  printf("%d", f(5));


  system("pause");
}

int busquedaBinaria( int arreglo[], int valBuscado, int inicio, int fin){
  int central;
  int contador = 0;
  while( inicio <= fin){
    contador++;
    central = ( inicio + fin)/2;

    if( valBuscado == arreglo[central]){
      return contador;
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

int f(int n){
  if(n == 0 || n==1){
    return 1;
  }
  else
  {
    return 3* f(n-2) + 2 * f(n-1);
  }
  
}