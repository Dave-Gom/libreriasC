#include"header.h"


int main(int argc, char const *argv[])
{
  int i = 0, bandera = 0;
  char cadena[100];
  printf("Inicio: ");
  leeConEspacios(cadena);


  Pila parentesis = {NULL, NULL, 0};

  while (cadena[i] != '\0' && cadena[i] != '\n')
  {
    if(cadena[i] == '('){
      insertarEnCabeza( cadena[i], &parentesis);// si encuentra apertura de parentesis agrega a la pila
    }
    if(cadena[i] == ')'){
      if(parentesis.cantidadElem == 0){ // si encuentra una cierre de parentesis y la pila esta vacia retorna bandera 1 
        bandera = 1;
        break;
      }
      else {
        extraerCabeza( &parentesis);

      }
    }
    i++;
  }

  if(parentesis.cantidadElem != 0){
    bandera = 1;
  }

  if(bandera == 0){
    printf("SI\n");
  }
  else
    printf("NO\n");
  

  return 0;
}