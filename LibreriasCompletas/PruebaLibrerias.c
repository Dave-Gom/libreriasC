#include "headerDocumentado.h"

void insertarEnCola(Lista *ACargar);
void insertarEnCabeza(Lista *ACargar);
void despliegaMenuListasYArchivos();
int main()
{
  int opcion;
  Lista ColaParaArchivos = {NULL, NULL, 0};

  do
  {
    despliegaMenuListasYArchivos();
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      insertarEnCabeza(&ColaParaArchivos);
      break;
    case 2:
      insertarEnCola(&ColaParaArchivos);
      break;
    case 3:
      imprimeCopiaRegistro(extraerCabeza(&ColaParaArchivos));
      break;
    case 4:
      imprimeCopiaRegistro(extraerCola(&ColaParaArchivos));
    case 5:
      imprimeDesdeLaCabeza(&ColaParaArchivos);
      break;

    default:
      break;
    }
  } while (opcion != 5);

  return 0;
}

void despliegaMenuListasYArchivos()
{

  printf("Que desea Hacer?\n");
  printf("Opciones:\n");
  printf("1 - Insertar en la Cabeza de la lista Lista\n");
  printf("2 - Insertar en la Cola de la Lista\n");
  printf("3 - Extraer de la cabeza la Lista\n");
  printf("4 - Extraer de la cola la Lista\n");
  printf("5 - Imprimir la Lista\n");
  printf("6 - Salir\n");
  printf("Su Opcion = ");
}