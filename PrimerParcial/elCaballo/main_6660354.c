#include"header_6660354.h"

int main(){   
  int contador = 0, ciclos = 0;
  int casos, p, q, iteradorD;
  scanf("%d", &casos);

  for ( iteradorD = 0; iteradorD < casos; iteradorD++)
  {
  
    srand(time(NULL));
    scanf("%d", &p); /* pfilas */
    scanf("%d", &q); /*  qcolumnas inicializa las dimensiones del tablero */
    int Arreglo[p ][q];

    int filaSig;
    int columSig;
    contador = 1; /* cuenta los pasos */
    while (verifica( p, q, Arreglo) != 0 && contador != 1000){      
      
      int ciclos = 0; /* cada vez que se falla se limpian las casillas */
      int s;
      int t;
      for ( s = 0; s < p; s++ )
      {     
        for ( t = 0; t < q; t++ )
        {
          Arreglo[s][t] = 0;
        }
      }      
       /* Se  coloca el caballo en la esquina superior izquierda cada vez
       se puede poner en cualquier parte */
      int x = 0;
      int y = 0;
      Arreglo[y][x] = 1;

      
      while ( 1000 != ciclos )
      {      
        ciclos++;
        filaSig = rand() % p;
        columSig =  rand() % q;

        if ( 2 == abs(x - filaSig))
        {      
          if ( 1 == abs(y - columSig)){
            /* if( filaSig > 1 && columSig >1 && columSig < q+1 && filaSig < p+1){ */
              if ( 0 == Arreglo[filaSig][columSig] )
              {     
                Arreglo[filaSig][columSig] = ++contador;
                x = filaSig;
                y = columSig;
                ciclos = 0;
              }    
            /* } */
          }
            
        }     

        if ( abs(abs(x) - abs(filaSig)) == 1)
        {  
          if ( abs(abs(y) - abs(columSig)) == 2  )
            /* if( filaSig > 1 && columSig >1 && columSig < q+1 && filaSig < p+1){ */
              if ( 0 == Arreglo[filaSig][columSig] )
              {    
                Arreglo[filaSig][columSig] = ++contador;
                x = filaSig;
                y = columSig;
                ciclos = 0;
              }   
            /* } */
        }   

      } 
    }  

    printf("Escenario #%d\n", iteradorD +1);
    if(verifica( p, q, Arreglo) == 0){
      imprimeCamino(p, q, Arreglo);
      Imprime( p, q, Arreglo);
    }
    else{
      printf("Imposible\n");
    }

    
  }
  
  return 0;
}    

