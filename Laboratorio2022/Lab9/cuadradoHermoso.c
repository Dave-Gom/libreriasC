#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct rectangulo
{
  int a,b,c,d;
}Rectangulo;

typedef struct corrdenada{
  int x,y;
}Coordenada;

void cargaMatriz( const int fila, const int colum, int matriz[][colum] );
int rectangulosHermosos( Rectangulo rectanguloDim, int fila, int columna, int matriz[fila][columna]);
void imprimeMatrizFormat( int filas, int columnas, int Matriz[][columnas]);
void izquierda(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);
void derecha(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);

void arriba(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);
void abajo(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion);
int cantidadRecHermosos(int fila, int columna, int matriz[fila][columna]);


int main(int argc, char const *argv[])
{
  int m,n,q,i, cantidad, aux; //define las variables
  scanf("%d", &m);
  scanf("%d", &n);
  scanf("%d", &q);
  int tablero[m][n];
  cargaMatriz(m,n,tablero);
  Rectangulo rectangulosPrueba[q];//array de rectangulos 
  int resultados[q];
  for ( i = 0; i < q; i++)
  {
    // printf("ingrese rectangulo\n");
    scanf("%d", &aux);
    rectangulosPrueba[i].a = aux;
    scanf("%d", &aux);
    rectangulosPrueba[i].b = aux;
    scanf("%d", &aux);
    rectangulosPrueba[i].c = aux;
    scanf("%d", &aux);
    rectangulosPrueba[i].d = aux;
    
  }
  imprimeMatrizFormat(m,n,tablero);
  for ( i = 0; i < q; i++)
  {
    resultados[i] = rectangulosHermosos( rectangulosPrueba[i], m, n ,tablero );
  }
  
  for ( i = 0; i < q; i++)
  {
    printf("%d\n", resultados[i]);
  }
  

  return 0;
}


void cargaMatriz( const int fila, const int colum, int matriz[][colum] ){
  int i,j, aux;
  for(i=0; i<fila; i++){
    for(j=0; j<colum; j++){
      scanf("%d", &aux);
      matriz[i][j]= aux;
    }
  }
}

int rectangulosHermosos( Rectangulo rectanguloDim, int fila, int columna, int matriz[fila][columna]){

  int i,j,a,b,c,d,ini, iniCol, contador = 0;
  a = rectanguloDim.a ;
  b = rectanguloDim.b ;
  c = rectanguloDim.c ;
  d = rectanguloDim.d ;

  int filaSub = (b)-(a -1);
  int columanSub = (d)-(c-1);
  int submatriz[filaSub][columanSub];
  if(a+b<fila)
    ini = b-a-1;
  else 
    ini = a+b-fila;

  if(c+d<columna)
    iniCol = d-c-1;
  else 
    iniCol = c+d-fila;

  for ( i = 0; i < filaSub ; i++)
  {
    for ( j = 0; j < columanSub ; j++)
    {
      submatriz[i][j] =  matriz[ini + i][iniCol + j];
    }
    
  }
  imprimeMatrizFormat(filaSub, columanSub, submatriz);
  return 1;
  //return cantidadRecHermosos(filaSub, columanSub, submatriz);

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

int cantidadRecHermosos(int fila, int columna, int matriz[fila][columna]){
  int contador = 0,i,j;
  Coordenada pos;
  for ( i = 0; i < fila; i++)
  {
    for ( j = 0; j < columna; j++)
    {
      pos.x = j;
      pos.y = i;
      // if(matriz[i][j]==0)
      //   contador++;
      
      izquierda(fila, columna, matriz, &contador, pos);
      derecha(fila, columna, matriz, &contador, pos);
      arriba(fila, columna, matriz, &contador, pos);
      abajo(fila, columna, matriz, &contador, pos);

    }
    
  }
  return contador;
}

void izquierda(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion){
  if(posicion.x -1 >=0){

    if(matriz[posicion.x][posicion.y] == 0){
      Coordenada NuevaPos = {posicion.x -1, posicion.y};
      izquierda(fila, columna, matriz, contador,NuevaPos );
      *contador = *contador + 1;

    }

  }
  
}

void derecha(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion){
  if(posicion.x +1 <columna){
    if(matriz[posicion.x][posicion.y] == 0){
      Coordenada NuevaPos = {posicion.x +1, posicion.y};
      derecha(fila, columna, matriz, contador,NuevaPos );
      *contador = *contador + 1;
    }

  }
  
}
void abajo(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion){
  if(posicion.y+1<fila){
    if(matriz[posicion.x][posicion.y] == 0){
      Coordenada NuevaPos = {posicion.x, posicion.y+1};
      abajo(fila, columna, matriz, contador,NuevaPos );
      *contador = *contador + 1;

    }

  }
  
}

void arriba(int fila, int columna, int matriz[fila][columna], int *contador, Coordenada posicion){
  if(posicion.x-1>=0){
    if(matriz[posicion.x][posicion.y] == 0){
      Coordenada NuevaPos = {posicion.x, posicion.y+1};
      abajo(fila, columna, matriz, contador,NuevaPos );
      *contador = *contador + 1;

    }

  }
  
}