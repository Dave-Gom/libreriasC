#include<stdio.h>
#include<stdlib.h>

typedef struct triangulo{ /* define un triangulo con lado de longitud a, b, c */
  int mayor;
  int menor;
  int mediano;
}Triangulo;

int main()
{
  int suma = 0, a, b, c;
  Triangulo unTriangulo;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if( a> b && a>c && b>c){
    unTriangulo.mayor = a;
    unTriangulo.mediano = b;
    unTriangulo.menor = c;
  }
  if( (a> b && a>c && c>b) || (a>b && b==c)){
    unTriangulo.mayor = a;
    unTriangulo.mediano = c;
    unTriangulo.menor = b;
  }
  if( (b>a && b>c && a>c)|| (b>a && b==c)){
    unTriangulo.mayor = b;
    unTriangulo.mediano = a;
    unTriangulo.menor = c;
  }
  if( c>a && c>b && a>b){
    unTriangulo.mayor =c;
    unTriangulo.mediano = a;
    unTriangulo.menor = b;
  }
  if( (c>a && c>b && b>a) || (c>a && a==b)){
    unTriangulo.mayor =c;
    unTriangulo.mediano = b;
    unTriangulo.menor = a;
  }

  while ( unTriangulo.mediano == unTriangulo.mayor - unTriangulo.menor || unTriangulo.mediano < unTriangulo.mayor - unTriangulo.menor)
  {
    suma += 1;
    unTriangulo.menor += 1;
  }
  

  printf("%d", suma);



  return 0;
}
