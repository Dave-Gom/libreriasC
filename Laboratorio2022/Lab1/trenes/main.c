#include<stdio.h>

void main(){
  int n, a, b, x, y, llega_en, dist, ubi, mova = 0, movb = 0;

  scanf("%d", &n);
  scanf("%d", &a);
  scanf("%d", &x);
  scanf("%d", &b);
  scanf("%d", &y);
  mova = a;
  movb = b;
  for (int i =0; i<n; i++){

    
    mova++;
    movb--;
    
    if( mova > n)
      mova = 1;

    if( movb < 1)
      movb = n;

    if( mova == movb){
      printf("SI");
      break;
    }

    

    if( mova == x){
      printf("NO");
      break;
    }

    if( movb == y){
      printf("NO");
      break;
    }
  }

  system("pause");
}