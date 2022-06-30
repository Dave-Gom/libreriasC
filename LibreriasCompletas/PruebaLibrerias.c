#include"headerDocumentado.h"

void insertarEnCola(Lista *ACargar);
void insertarEnCabeza(Lista *ACargar);

int main()
{
  int opcion;
    Archivo* ptrArchivo = creaArchivo();

  if( ptrArchivo != NULL){
    do
    {
      menuArchivos();
      scanf("%d", &opcion);
      switch (opcion)
      {
        case 1:
          informeTxt( ptrArchivo);
          break;
        case 2:
            actualizaRegistro( ptrArchivo);
            break;
        case 3:
            nuevoRegistro( ptrArchivo);
            break;
        case 4:
            eliminaRegistro( ptrArchivo);
            break;
        case 5:
          printf("Adios...\n");
          break;
        default:
          break;
      }

    } while (opcion != 5);
    
  }


  return 0;
}

/* int main(int argc, char const *argv[])
{
    //modo de uso Funciones de Listas, pilas y colas
  Nodo primero = { 5, NULL, NULL};
  Lista ListaDePrueba = { NULL, NULL, 0};
  int opcion, valor;
  //Nodo elementos[12]; //no se puede declarar un arreglo vacio elementos[], no esta permitido

  do
  {
    despliegaMenuListas();
    scanf("%d", &opcion);
    switch (opcion)
    {
    
    case 1:
        insertarEnCabeza(&ListaDePrueba);
        break;
    case 2:
        insertarEnCola( &ListaDePrueba);
        break;
    case 3:
        printf("El valor extraido es %d", (extraerCabeza(&ListaDePrueba)).valor );
        imprimeDesdeLaCabeza( &ListaDePrueba);
        break;
    case 4: 
        printf("El valor extraido es %d", (extraerCola(&ListaDePrueba)).valor );
        imprimeDesdeLaCabeza(&ListaDePrueba);
        break;
    case 5: 
        // imprimeDesdeLaCabeza(&ListaDePrueba);
        printf("\nimprimiendo desde la cola: ");
        imprimeDesdeLaCola(&ListaDePrueba);
        break;
      default:
        printf("Opcion Invalida. Favor Reinsertar!\n");
        break;
    }
  } while (opcion != 6);
  
  system("pause");
  return 0;
} */


