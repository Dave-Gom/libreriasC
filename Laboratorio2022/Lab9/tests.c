#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>


typedef struct rectangulo
{
  int a,b,c,d;
}Rectangulo;

typedef struct corrdenada{
  int x,y;
}Coordenada;

void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]);
void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite);
void separaEnSubMatrices(Rectangulo rectanguloDim, int fila, int columna, int matriz[fila][columna]);

int main(int argc, char const *argv[])
{
  int m,n,q,i, cantidad, aux; //define las variables
  scanf("%d", &m);
  scanf("%d", &n);
  scanf("%d", &q);
  int tablero[m][n];
  matrizAleatoria(m,n,tablero, 2);
  imprimeMatrizFormat(m,n,tablero);
  Rectangulo rectangulosPrueba;//array de rectangulos 
  int resultados[q];

    rectangulosPrueba.a = 0;//1 y1
    rectangulosPrueba.b = 1;//2 x2
    rectangulosPrueba.c = 4;//5 y5
    rectangulosPrueba.d = 1;// x2

    separaEnSubMatrices( rectangulosPrueba,  m,  n,  tablero);

  return 0;
}


void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite)
{ /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
  /* El valor limite nunca se alcanza */
  /* incluir stdlib para usar rand() y time() */
  int i,j;
  srand(time(NULL));
  for ( i = 0; i < fila; i++)
  {
    for ( j = 0; j < columna; j++)
    {
      arreglo[i][j] = rand() % valLimite;
    }
    
  }
}


void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]){
  int i;
  int j;

  /* printf("\n\nEste es el tablero:\n\n "); */
  for ( i = 0; i < filas; i++ )
  { 

    for ( j = 0; j < columnas; j++)
    { 
      printf(" %d\t",  Matriz[i][j]);
    } 
    printf("\n");
  }

  printf("\n");
} 

void separaEnSubMatrices(Rectangulo rectanguloDim, int fila, int columna, int matriz[fila][columna]){
  int cantidadFilas = rectanguloDim.c - rectanguloDim.a +1, 
  cantidadColumnas = rectanguloDim.d-rectanguloDim.b +1,
  i,
  j,
  a = rectanguloDim.a ,
  b = rectanguloDim.b ,
  c = rectanguloDim.c ,
  d = rectanguloDim.d, 
  iniFila, 
  iniCol; //inicializa variables

  if(a+c<fila) //calculo el punto de inicio de lectura de filas e columna en nuestra matriz
    iniFila = c-a-1;
  else 
    iniFila = a+c-fila;

  if(b+d<columna)
    iniCol = b-d-1;
  else 
    iniCol = c+d-columna; /* fijarme BIen */

  printf("\nInicioF: %d \tInicioC %d", iniFila, iniCol);

  int subMatriz[cantidadFilas][cantidadColumnas];
  for ( i = 0; i < cantidadFilas; i++)
  {
    for ( j = 0; j < cantidadColumnas; j++)
    {
      subMatriz[i][j] = matriz[iniFila + i][iniCol + j];
      printf("%d\n", matriz[iniFila + i][iniCol + j]);
    }
    
  }

  imprimeMatrizFormat(cantidadFilas, cantidadColumnas, subMatriz); 
  
}
