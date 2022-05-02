#include"header_6660354.h"

void Imprime( int filas, int columnas, int Matriz[][columnas]){
  int i;
  int j;

  printf("\n\nEste es el tablero:\n\n ");
  for ( i = 0; i < filas; i++ )
  { 
    for ( j = 0; j < columnas; j++)
    { 
      printf(" %d\t",  Matriz[i][j]);
    } 
    printf("\n\n\n");
  }

  printf("\n\n\n");
} 

int verifica(int fila, int col, int matriz[][col]){
  int i, j;
  for( i = 0;i<fila; i++){
    for ( j = 0; j < col; j++)
    {
      if( matriz[i][j] == 0){
        return -1;
      }
    }
  }

  return 0;
}

void imprimeCamino( int fila, int col, int a[][col]) /* imprime el camino que recorrio una en una matriz */
{
  int i, j, elem;
  for(elem = 1; elem <= fila*col +1; elem++){
    for ( i = 0; i < fila; i++)
    {
      for ( j = 0; j < col; j++)
      {
        if( a[i][j] == elem){
          printf("%c%d ", getLetra(i+1), j);
        }
      }
    }
  }
}

char getLetra(int val){ /* letras de la A a la H para rempresentar las columnas del tablero de ajedrez */
  switch (val)
  {
  case 1:
    return 'a';
    break;
  case 2:
    return 'b';
    break;
  case 3:
    return 'c';
    break;
  case 4:
    return 'd';
    break;
  case 5:
    return 'e';
    break;
  case 6:
    return 'f';
    break;
  case 7:
    return 'g';
    break;
  case 8:
    return 'h';
    break;
  default:
    return 'x';
    break;
  }
}