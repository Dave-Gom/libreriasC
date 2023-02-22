#include<stdio.h>

int main(){
  int contador = 0, marcos, luis, bianca, problemas;

  scanf("%d", &problemas);

  for( int i = 0; i < problemas; i++){
    scanf("%d", &marcos);
    scanf("%d", &luis);
    scanf("%d", &bianca);
    
    if ((marcos + luis +bianca) > 1){
      contador++;
    }
  }

  printf("%d", contador);
  return 0;
}