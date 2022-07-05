#include"header.h"

int main(int argc, char const *argv[])
{
  int dato;
  Lista listaDeEnteros = { NULL, NULL, 0}; //inicializo la lista
  scanf("%d", &dato);
  while ( dato != -1)
  {
    insertaEnOrden(dato, &listaDeEnteros); //utimilzamos el ordenamiento por seleccion
    scanf("%d", &dato);
  } 

  imprimeDesdeLaCabeza(&listaDeEnteros);
}
