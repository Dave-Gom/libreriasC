#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){

  int pruebas, i, j, s, cont;
  char nuemero[6];
  char acum[15] = "";
  char aux[15] = "";
  int nuevos[6] = {0};
  scanf("%d", &pruebas);
  int result[pruebas];
  char auxcad[2] = "";
  for(i = 0; i<pruebas ; i++){
    scanf("%s", nuemero );
    for( j = 0; j< strlen(nuemero); j++ ){
      strcat(auxcad, nuemero[j]);
      cont = atoi(auxcad );
      itoa(aux, cont + 1, 10);
      strcat(acum, aux);
      auxcad[0] = "";
    }
    result[i] = atoi(acum);
    for( s = 0 ; s < 15; s++){
      acum[s] = "";
    }
  }

  for(i = 0; i<pruebas; i++){
    printf("%d", result[i]);
  }
  system("pause");
}