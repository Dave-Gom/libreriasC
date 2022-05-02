#include<stdio.h>
#include<stdlib.h>

void actualizaRegistro( FILE *ptrF);
void nuevoRegistro( FILE *prtF);
void eliminaRegistro( FILE *ptrF);
FILE *creaArchivo();
void menuArchivos();
void leeConEspacios( char cadena[] );
void informeTxt( FILE *prtF);



typedef struct registroArchivo //registro de archivos
{
  int id;//Por convencion mia y de las db en general todos lor registros llevaran una id con Primary key
  /* Aqui deben ir los Argumentos del registro */
  int numeroCuenta;
  char nombre[60];
  double estadoDeCuenta;

}Registro;

typedef struct nodoArchivo
{
  Registro dato;
  struct nodoArchivo *sig;
  struct nodoArchivo *ant;
}NodoArchivo;

Registro creaRegistro(); //crea un nuevo registro y devuelve el apuntador a este

int main()
{
  int opcion;
  FILE *ptrArchivo = NULL;
  ptrArchivo = creaArchivo();
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

void menuArchivos(){ //despliega el menu
  printf("Selecciones su opcion\n1- Informe EN archivo txt.\n2-AcualizarUnRegistro\n3-Agregar Un Registro.\n4- Eliminar un registro \n5-Salir Del Programa.\nOpcion=");
}

FILE *creaArchivo(){

  char nombreArchivo[150] = "";
  char modo[5] = "";
  FILE *ptrNuevoArchivo = NULL;
  
  printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
  scanf("%s", nombreArchivo);
  printf("\nIngrese el codigo del Modo de apertura del archivo: ");
  scanf("%s", modo);
  if( (ptrNuevoArchivo = fopen(nombreArchivo, modo)) == NULL){
    printf("No se pudo crear el archivo.\nERROR\n");
    return NULL;
  }
  else
  {
    return ptrNuevoArchivo;
  }
  
}


Registro creaRegistro(){ // crea un registro nuevo, lee sus valor y devuelve una copia

  Registro *ptrNuevoRegistro = malloc( sizeof( Registro)); // libera espacio en memoria para el nuevo registro

  printf("Funcion Crear Nuevo Registro\n");
  ptrNuevoRegistro->id = 0;
  printf("Ingrese Numero De cuenta: ");
  scanf("%d", &ptrNuevoRegistro->numeroCuenta);
  printf("Ingrese El nombre del Propietario de la Cuenta: ");
  scanf("%s", ptrNuevoRegistro->nombre);
  printf("ingrese EL estado de la cuenta: ");
  scanf("%lf", &ptrNuevoRegistro->estadoDeCuenta);

  return *ptrNuevoRegistro; // retorna una copia del registro creado
}



void nuevoRegistro( FILE *ptrArchivo){

  Registro nuevoRegistro, auxRegistro = { 0, 0, "", 0};

  nuevoRegistro = creaRegistro(); // crea un nuevo registro 

  fseek( ptrArchivo, (nuevoRegistro.numeroCuenta) * sizeof(Registro), SEEK_SET); //establece el apuntador a la posicion del numero de cuenta del nuevo Registro
  fread( &auxRegistro, sizeof( Registro ), 1, ptrArchivo ); //almacena la lectura del puntero del archivo al registro auxiliar

  if( auxRegistro.numeroCuenta != 0 ){ // si la cuenta del reigistro ya existe
    printf("\nERROR: La cuenta %d Ya existe\n", auxRegistro.numeroCuenta);
  }
  else{ //sino, guarda el nuevo registro en esa direccion
    fseek( ptrArchivo, (nuevoRegistro.numeroCuenta) * sizeof(Registro), SEEK_SET);  //establece el apuntador a la posicion del numero de cuenta del nuevo Registro
    fwrite( &nuevoRegistro, sizeof( Registro ), 1, ptrArchivo ); //escribe el contenido del registro nuevo en la direccion especificada
    printf("\nRegistro Agregado Exitosamente!\n\n");
    rewind(ptrArchivo);
  }

}

void actualizaRegistro(FILE * ptrArchivo){
  /* inicializar los valores a editar del  */

  Registro registroAux;
  int cuenta;
  double transaccion;

  printf("Introduzca los el numero de cuenta para actualizar: ");
  scanf("%d", &cuenta);

  fseek(ptrArchivo, (cuenta)*sizeof(Registro), SEEK_SET);

  fread( &registroAux, sizeof(Registro), 1, ptrArchivo);

  if( registroAux.numeroCuenta == 0 ){
    printf("\nLa cuenta #%d no tiene informacion\n", registroAux.numeroCuenta);
  }
  else
  {
    printf( "Numero de cuenta: %d\nNombre Titular: %s\nSaldo: %lf\n\n",
      registroAux.numeroCuenta,
      registroAux.nombre, registroAux.estadoDeCuenta 
    );
    printf("Intruduzca el cargo (+) o el pago (-): ");//Aqui debe ingresarse los campos a modificar
    scanf("%lf", &transaccion);
    registroAux.estadoDeCuenta = registroAux.estadoDeCuenta + transaccion;
    printf("\n Cuenta actualizada Correctamente!\nSaldo actual:%lf\n\n", registroAux.estadoDeCuenta);
    fseek(ptrArchivo, (cuenta)*sizeof(Registro), SEEK_SET);
    fwrite( &registroAux, sizeof( Registro), 1, ptrArchivo);

  }
  
}

void eliminaRegistro(FILE *ptrArchivo){

  Registro registroAux;
  Registro regEnBlanco = { 0, 0, "", 0}; // tambien podemos hacer un borrado Logico estableciendo en valor de la id a -1

  int numeroCuenta;
  printf("Introduzca el numero de Cuenta a Eliminar: ");
  scanf("%d", &numeroCuenta);

  fseek( ptrArchivo, ( numeroCuenta - 1) * sizeof( Registro), SEEK_SET);
  fread(&registroAux, sizeof(Registro), 1, ptrArchivo);

  if (registroAux.id == 0 && registroAux.numeroCuenta == 0)
  {
    printf("La cuenta %d no existe", numeroCuenta);
  }
  else
  {
    fseek( ptrArchivo, ( numeroCuenta - 1) * sizeof( Registro), SEEK_SET);
    fwrite(&regEnBlanco, sizeof(Registro), 1, ptrArchivo);
    printf("\n\tRegistro Eliminado Exitosamente\n");
  }
  
}

/* crea un archivo de texto con formato para impresión */
void informeTxt(FILE *ptrArchivo){

  FILE *ptrInforme; //apuntador al archivo Resultado

  Registro datos = { 0, 0, "", 0};//inicializa


  if( (ptrInforme = fopen("Informe.txt", "w")) == NULL )
    printf("\n\tERROR: No se pudo crear el Archivo\n\n");
  else
  {
    rewind(ptrArchivo);//establece el puntero al principio del archivo
    fprintf(ptrInforme, "%s\t%s\t%s\t%s\n","No.","CTA", "Titular","Estado de Cuenta");//imprime la cabecera

    while (!feof(ptrArchivo))
    {
      fread(&datos, sizeof(Registro), 1, ptrArchivo);//lee los datos en el Registro datos

      if( datos.numeroCuenta != 0){
        fprintf(ptrInforme, "%d\t%d\t%s\t%lf\n", datos.id, datos.numeroCuenta, datos.nombre, datos.estadoDeCuenta); //escribe con formato en el archivo de informe
      }

    }
    
    fclose(ptrInforme);//cierra el archivo de informe
    printf("\n\tInforme Generado exitosamente!\n\n");
  }
  
}