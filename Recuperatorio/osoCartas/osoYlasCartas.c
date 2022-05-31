#include"header.h"

int main(int argc, char const *argv[])
{
  int cartas[5];
  int sumaSinCarta[5];
  int i, j,contadorCartas = 0, sumaCartas=0;

  for ( i = 0; i < 5; i++)
  {
    scanf("%d", &cartas[i]);
    sumaSinCarta[i] = -1;
    sumaCartas+=cartas[i];
  }
  



  for ( i = 0; i < 5; i++)
  {
    contadorCartas = 0;
    for ( j = 0; j < 5; j++)
    {
      if( cartas[j] == cartas[i] )
      {
        contadorCartas++; //amenta el contador de veces que encontro una carta
      }

    }
   
    if(contadorCartas>1) //si encontro la carta actual mas de una vez
    {
      if(contadorCartas < 3)
      {
        sumaSinCarta[i] = sumaCartas - (contadorCartas * cartas[i]);
      }
      else
      {
        sumaSinCarta[i] = sumaCartas - (3 * cartas[i]);
      }
      
    }
    else
    {
      sumaSinCarta[i] = sumaCartas;
    }
    
    
    
  }

  
  printf("%d", menor(sumaSinCarta, 5));

  return 0;
}


