#include<stdio.h>
#include<stdlib.h>

typedef struct rectangulo{
  int lado1;
  int lado2;
}Rectangulo;

int main()
{
  int casosPrueba, i, aux;
  scanf("%d", &casosPrueba);
  char *respuestas[casosPrueba];
  Rectangulo RecUno;
  Rectangulo RecDos;
  for ( i = 0; i < casosPrueba; i++)
  {
    scanf("%d", &aux);
    RecUno.lado1 = aux;
    scanf("%d", &aux);
    RecUno.lado2 = aux;
    scanf("%d", &aux);
    RecDos.lado1 = aux;
    scanf("%d", &aux);
    RecDos.lado2 = aux;
    respuestas[i] = "NO";

    if ( RecUno.lado1 == RecDos.lado1 && RecUno.lado1 == RecUno.lado2 + RecDos.lado2)
    {
        respuestas[i] = "SI";
        printf("Hola mundo\n");
    }
    if ( RecUno.lado1 == RecDos.lado2 && RecDos.lado2 == RecUno.lado2 + RecDos.lado1)
    {
      respuestas[i] = "SI";
      printf("Hola mundo2\n");
    }
    if (RecUno.lado2 == RecDos.lado2 && RecDos.lado2 == RecUno.lado1 + RecDos.lado1)
    {
      respuestas[i] = "SI";
      printf("Hola mundo3\n");
    }
    if (RecUno.lado2 == RecDos.lado1 && RecDos.lado1 == RecUno.lado1 + RecDos.lado2)
    {
      respuestas[i] = "SI";
      printf("Hola mundo4\n");
    }


  }
  
  for ( i = 0; i < casosPrueba; i++)
  {
    printf( "%s", respuestas[i]);
  }
  

  system("pause");
  return 0;
}



