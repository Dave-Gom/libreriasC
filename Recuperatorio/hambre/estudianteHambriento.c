#include"header.h"

int main(int argc, char const *argv[])
{
  int G = 7,P = 3,x, bandera = 0, n, i;
  scanf("%d", &n);
  int resultados[n];
  for ( i = 0; i < n; i++)
  {
    scanf("%d", &x);
    resultados[i] = numeroCompuesto(x, 7, 3);
    
  }
  
  for ( i = 0; i < n; i++)
  {
    printf(  resultados[i] == 1? "SI\n": "NO\n");
  }
  

  return 0;
}

