#include<stdio.h>

void main(){
  int m, n, a, b, div, pagan, destruir, construir;

  scanf("%d", &m);
  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &b);

  if( m % n != 0){
    if( (n % 2) == 0){
      div = n/2;
    }
    else{
      div = (n/2) - 0.5;
    }
    
    construir = a * (n-div);
    destruir = b * div;

    if( construir > destruir )
      pagan = destruir;
    else  
      pagan = construir;
   
  }
  else{

      /* son iguales */
      pagan = 0 ;
   
  }

  printf("%d", pagan);


}