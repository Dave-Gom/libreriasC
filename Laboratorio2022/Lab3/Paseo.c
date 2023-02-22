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

