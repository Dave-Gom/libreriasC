#include"header.h"



int main(int argc, char const *argv[])
{
  int m,n,q,i, cantidad, aux; //define las variables
  scanf("%d", &m);
  scanf("%d", &n);
  scanf("%d", &q);
  int tablero[m][n];
  cargaMatriz(m,n,tablero);
  Rectangulo rectangulosPrueba[q];//array de rectangulos 
  int resultados[q];
  for ( i = 0; i < q; i++)
  {
    // printf("ingrese rectangulo\n");
    scanf("%d", &aux);
    rectangulosPrueba[i].a = aux;
    scanf("%d", &aux);
    rectangulosPrueba[i].b = aux;
    scanf("%d", &aux);
    rectangulosPrueba[i].c = aux;
    scanf("%d", &aux);
    rectangulosPrueba[i].d = aux;
    
  }

  for ( i = 0; i < q; i++)
  {
    resultados[i] = rectangulosHermosos( rectangulosPrueba[i], m, n ,tablero );
  }
  
  for ( i = 0; i < q; i++)
  {
    printf("%d", resultados[i]);
  }
  

  return 0;
}
