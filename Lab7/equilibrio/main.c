#include"header.h"

void inicializaVector( Vector *V, int valorInicial);
void cargarVector( Vector *V);
int FuerzasEnEquilibrio(Vector Fuerzas[], int cantidad);

void main()
{



  int cantidadFuerzas, i, x, y, z;
  scanf("%d", &cantidadFuerzas);

  Vector Fuerzas[cantidadFuerzas];

  for ( i = 0; i < cantidadFuerzas; i++)
  {
    inicializaVector( &Fuerzas[i], 0);
  }
  

  for ( i = 0; i < cantidadFuerzas; i++)
  {
    cargarVector(&Fuerzas[i]);
  }

  if( FuerzasEnEquilibrio(Fuerzas, cantidadFuerzas) == 0){
    printf("SI");
  }
  else
  {
    printf("NO");
  }
}


void inicializaVector( Vector *V, int valorInicial){
  V->x = valorInicial;
  V->y = valorInicial;
  V->z = valorInicial;
}

void cargarVector( Vector *V){
  int aux;
  printf("Ingrese la componente de la fuerza en x: ");
  scanf("%d", &aux);
  V->x = aux;
  printf("Ingrese la componente de la fuerza en Y: ");
  scanf("%d", &aux);
  V->y= aux;
  printf("Ingrese la componente de la fuerza en z: ");
  scanf("%d", &aux);
  V->x = aux;
}


int FuerzasEnEquilibrio(Vector Fuerzas[], int cantidad){
  int i = 0, x = 0, y = 0 , z = 0, bandera = 0;
  for ( i = 0; i < cantidad; i++)
  {
    x += Fuerzas[i].x;
    y += Fuerzas[i].y;
    z += Fuerzas[i].z;
  }
  
  return x+y+z;
}
