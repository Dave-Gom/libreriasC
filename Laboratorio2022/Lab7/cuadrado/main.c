#include"header.h"


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
         
    }
    if ( RecUno.lado1 == RecDos.lado2 && RecDos.lado2 == RecUno.lado2 + RecDos.lado1)
    {
      respuestas[i] = "SI";
      
    }
    if (RecUno.lado2 == RecDos.lado2 && RecDos.lado2 == RecUno.lado1 + RecDos.lado1)
    {
      respuestas[i] = "SI";

    }
    if (RecUno.lado2 == RecDos.lado1 && RecDos.lado1 == RecUno.lado1 + RecDos.lado2)
    {
      respuestas[i] = "SI";

    }


  }
  
  for ( i = 0; i < casosPrueba; i++)
  {
    printf( "%s", respuestas[i]);
  }
  

  return 0;
}



