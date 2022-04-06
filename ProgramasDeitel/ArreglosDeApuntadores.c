#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/* Baraja cartas */

void baraja( int wMazo[][13]);
void reparte( const int wMarzo[][13], const char *wCara[], const char *wPalo[] );

int main(){

/* inicializa palo, un arreglo de apuntadores a cadenas */
  const char *palo[4] = { "Corazones", "Diamantes", "Treboles", "Espadas"};

/* inicializa el arreglo de apuntadores a cadenas "cara" */
  const char *cara[13] = { "As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho","Nueve", "Diez", "Jota", "Reina", "Rey"};

  int mazo[4][13] = {0};/* inicializa el mazo */

  srand( time(0)); /* semilla del generador de numeros aleatorios */

  baraja( mazo);
  reparte( mazo, cara, palo);
  
  system("pause");
  return 0;
}

void baraja( int wMazo[][13]){
  int fila, columna, carta;

  /* para cada una de las 52 cartas elije de forma aleatoria un espacion hasta encontrar un espacio vacio */
  for ( carta = 0; carta < 52; carta++)
  {
    do
    {
      fila = rand() %4;
      columna = rand() %13;
    } while (wMazo[fila][columna] != 0); /* si mazo[fila][columna] no es igual a cero, busca de forma aleatoria otra posicion */
    
    wMazo[fila][columna] = carta;
  }
  
}

void reparte( const int wMazo[][13], const char *wCara[], const char *wPalo[]){
  int carta, fila, columna, bandera;
  for ( carta = 1; carta <= 52; carta++)
  {
    
    for ( fila = 0; fila <= 3; fila++)
    {
      bandera=0;
      for ( columna = 0; columna <= 12; columna++)
      {

        if (wMazo[fila][columna] ==carta)
        {
          printf("%6s de %-0s%c", wCara[columna], wPalo[fila], carta %2 == 0? '\n': '\t');
          bandera =1;
          break;
        }
        if( bandera == 1){
          break;
        }
      }
    }
    
  }
  
}