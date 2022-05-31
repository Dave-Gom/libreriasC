#include"header.h"

int numeroCompuesto(int n, int a, int b)
{
  int bandera = 0;
  //devuelve 1 si el numero n esta compuesto por a y/o b

   if( n % a == 0)
      bandera = 1;
    else
    {
      if( (n%a)%b==0){
        bandera = 1;
      }
      
    }

    if(n % b == 0)
      bandera = 1;
    else
    {
      if( (n%b)%a == 0)
        bandera= 1;
    }

  return bandera;
}
