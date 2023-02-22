#include"header.h"

int main(){
  
  int n,k, i;

  scanf("%d", &n);
  scanf("%d", &k);

  for( i = 1; i<=k; i++){
    n = resta_errad(n);
  }

  printf("%d", n);
  return 0;
} 


