#include"header.h"



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
  
  return cantidadRecHermosos(filaSub, columanSub, submatriz);

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