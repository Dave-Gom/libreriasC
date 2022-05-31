#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"ColasDePrioridad.h"





int main(int argc, char const *argv[])
{
  int cantidadPrioridades = 4;
  ColaDePrioridad ColaDePrioridadDePrueba = CreaColaPrioridad(cantidadPrioridades);
  int opcion;
  despliegaMenuColasDePrioridad();
  scanf("%d", &opcion);
  while ( opcion != 4){
    switch (opcion)
    {
    case 1:
      insertarDatosEnColaDePriridad(&ColaDePrioridadDePrueba);
      break;
    
    case 2:
      leerColaDePrioridads(&ColaDePrioridadDePrueba);
      break;
    case 3:
      imprimirColaDePrioridad(ColaDePrioridadDePrueba);
    
    default:
      break;
    }
    despliegaMenuColasDePrioridad();
    scanf("%d", &opcion);
  }
  
  return 0;
}