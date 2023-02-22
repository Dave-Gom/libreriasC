#include"header.h"


int main(int argc, char const *argv[])
{
  int i = 0, banderaParentesis = 0, banderaCorchete = 0, banderaLlaves = 0;
  char cadena[15];
  scanf("%s", cadena);


  Pila parentesis = {NULL, NULL, 0};

  banderaParentesis = simbolosValanceados(cadena, parentesis, '(', ')');
  banderaCorchete = simbolosValanceados(cadena, parentesis, '[', ']');
  banderaLlaves = simbolosValanceados(cadena, parentesis, '{', '}');


  if( banderaCorchete == 1 || banderaLlaves == 1 || banderaParentesis == 1){
    printf("NO\n");
  }
  else
    printf("SI\n");
  

  return 0;
}
