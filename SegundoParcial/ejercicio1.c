#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

typedef struct registroArchivo //registro de archivos
{

    char nombre[60];
    char fecha_entrada[15];
    double puntaje;

}Registro;

typedef struct NODO{ //los nodos tendran un registro dentro para mayor 
  Registro dato;
  struct NODO *sig;
  struct NODO  *ante;
}Nodo; //define un alias para una estructura NODO

typedef struct {
  Nodo *cabeza;
  Nodo *cola;
  int cantidadElem;
}Cola; //Una lista doblemente enlazada puede ser una Pila o una Cola dependiendo de como se carguen y lean los Nodos

Nodo *creaNodo(Registro dato);
void insertarEnCola( Cola *listaDestino);
Registro creaRegistro();
int listaEstaVacia(Cola ListaVal);
void menu();
void imprimeDesdeLaCabeza(const Cola *listaObjetivo);
void imprimeRegistro(Registro datos);
void guardaEnarchivo(Cola );
Registro extraerCabeza(Cola *listaObjetivo);

int main(int argc, char const *argv[])
{
    Cola ColaDeEmpleados = {NULL, NULL, 0};
    int opcion;
    do
    {
        menu();
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            insertarEnCola(&ColaDeEmpleados);
            break;
        case 2:
            printf("Guardando...\n");
            guardaEnarchivo(ColaDeEmpleados);
            break;
        case 3:
            imprimeDesdeLaCabeza(&ColaDeEmpleados);
            break;
        default:
            printf("\nOpcion No Valida\n");
            break;
        }
    } while (opcion != 4);

    insertarEnCola(&ColaDeEmpleados);

    printf("Hola Mundo");
    return 0;
}

Nodo *creaNodo( Registro dato)
{ // crea un nodo de una lista y devuelve su direccion en memoria
  Nodo *nuevoNodo = malloc( sizeof ( Nodo));
  if( nuevoNodo != NULL){
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ante = NULL;
    return nuevoNodo;
  }
  else
  {
    printf("No de pudo crear el Nuevo Nodo, Memoria insuficiente");
    return NULL;
  }

}


void insertarEnCola( Cola *listaDestino)
{ //Inserta Por la cola de la lista (tabien valido para Colas)
   /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
  Nodo *ptrNuevoNodo = creaNodo(creaRegistro());

  if( ptrNuevoNodo != NULL ){
    listaDestino->cantidadElem++;

    if(listaEstaVacia( *listaDestino) == -1){ //si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
      listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
    }
    else{ // si la lista no esta vacia
      ptrNuevoNodo->ante = listaDestino->cola; //asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
      listaDestino->cola->sig = ptrNuevoNodo; //asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
      listaDestino->cola = ptrNuevoNodo; //asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
    }
  }
}

Registro creaRegistro()
{
    Registro NuevoRegistro;
    scanf("%s", NuevoRegistro.nombre);
    scanf("%s", NuevoRegistro.fecha_entrada);
    scanf("%lf", &NuevoRegistro.puntaje);

    return NuevoRegistro;
}

int listaEstaVacia( Cola ListaVal)
{ //retorna -1 si la lista esta vacia, 0 en caso contrario
  if(ListaVal.cabeza == NULL && ListaVal.cola == NULL){
    return -1;
  }
  else{
    return 0;
  }
} 

void menu()
{
    printf("\n Menu \n");
    printf("Ingrese Su opcion:\n");
    printf("1- Cargar empleado");
    printf("2- Guardar los 5 mejores puntajes");
    printf("3- Imprimir cola");
    printf("4 - Salir");
}

void imprimeDesdeLaCabeza( const Cola *listaObjetivo)
{ //imprime una lista desde la cabeza (tambien valido para una Cola)
  printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  while ( ptrNodoObjetivo != NULL)
  {
    imprimeRegistro(ptrNodoObjetivo->dato); //imprimie el registro asociado al nodo
    printf(" -> ");
    ptrNodoObjetivo = ptrNodoObjetivo->sig;
  }
  printf("NULL\n");
}

void imprimeRegistro(Registro datos)
{
  printf("{ %s| %s |%.3f }", datos.nombre, datos.fecha_entrada, datos.puntaje); //aqui imprimir el registro dependiendo de los datos que se especifiquen arriba
}

void guardaEnarchivo(Cola ColaObjetivo)
{
    FILE *ptrArchivo = NULL;
    Registro RegAux;
    int i;
    if ((ptrArchivo = fopen("Mejores.dat", "w")) != NULL)
    {
        for ( i = 0; i < 5; i++)
        {
            if(listaEstaVacia(ColaObjetivo)== -1){
                break;
            }
            RegAux = extraerCabeza( &ColaObjetivo);
            fprintf(ptrArchivo,  "%s\t%s\t%.3f\n", RegAux.nombre, RegAux.fecha_entrada, RegAux.puntaje);
        }
    }
    else
    {
        printf("No se pudo Crear el archivo");
    }
    fclose(ptrArchivo);
}

Registro extraerCabeza( Cola *listaObjetivo)
{ //no se necesita leer ni imprimir nada, simplemente saca  una apertura de parentesis de la pila //para otros casos se puede retornar el valor contenido en el nodo Cabeza
  
  Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
  listaObjetivo->cabeza = ptrNodoObjetivo->sig;
  listaObjetivo->cantidadElem--; //resta uno a la cantidad de elementos de la pila
  if(listaObjetivo->cantidadElem == 0)
    listaObjetivo->cola = NULL;

  return ptrNodoObjetivo->dato;
}