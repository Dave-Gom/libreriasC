#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"./../estructurasAutoreferenciadas/ListasEnlazadas/listas.h"

typedef struct ESTRUCTURAARCHIVOS{
  int cantidadElementos;
  FILE *punteroArchivo;
}Archivo;

typedef struct REGISTRORARCHIVO{
  unsigned int id;
  int estaEliminado;
  Registro Dato;
}RegistroArchivo;

RegistroArchivo creaRegistroArchivo();
Archivo *creaArchivo();
Archivo *creaArchivoBin(); //crea un archivo binario, si se especifica rb+ y el archivo no existe, primero lo crea y luego abre el archivo para actualizacion binaria
void guardaRegistroEnArchivo( Archivo *ptrArchivo, RegistroArchivo *aGuardar);
void nuevoRegistro( Archivo *prtF);
void eliminaRegistro( Archivo *ptrF);
void actualizaRegistro( Archivo *ptrF);
void informeTxt( Archivo *prtF);//imprime un informe del archiv en txt
void guardaColaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos);//recibe una Lista y guarda los registros en un archivo desde la cabeza de la listavoid menuArchivos();