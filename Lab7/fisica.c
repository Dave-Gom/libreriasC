#include<stdio.h>
#include<stdlib.h>

typedef struct vector{
  int x;
  int y;
  int z;
}Vector;

int main()
{

  Vector FuerzaResultante = { 0, 0, 0};


  int cantidadFuerzas, i, x, y, z;
  scanf("%d", &cantidadFuerzas);

  for ( i = 0; i < cantidadFuerzas; i++)
  {
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    FuerzaResultante.x += x;
    FuerzaResultante.y += y;
    FuerzaResultante.y += y;

  }

  if(FuerzaResultante.x  == 0  && FuerzaResultante.y  == 0 && FuerzaResultante.z  == 0){
    printf("SI");
  }
  else
  {
    printf("NO");
  }
  return 0;
}

