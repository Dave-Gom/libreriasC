#include<stdio.h>
void copiaConArreglo( char *s1, const char *s2);
void copiaConApunta( char *s1, const char *s2);


int main(){

  char cadena1[10];
  char *cadena2 = "hola";
  char cadena3[10];
  char cadena4[] = "adios";

  copiaConArreglo( cadena1, cadena2);
  printf("Cadena1 = %s\n", cadena1);

  copiaConApunta( cadena3, cadena4);
  printf( "cadena3 = %s\n", cadena3);


  system("pause");
  return 0;
}

void copiaConArreglo( char *copia, const char *copiado){
  int i;

  for ( i = 0; ( copia[i] = copiado[i]) != '\0'; i++)
  {
    /* no realiza nada en el cuerpo */
  }
  
}

void copiaConApunta( char *copia, const char *copiado){
  for ( ; (*copia = *copiado) != '\0'; copia++, copiado++)  {
    /* no realiza nada en el cuerpo */
  }
  
}