#include"estructuras.h"

/**
 * @brief Crea un registro nuevo, lee sus valor y devuelve una copia
 * 
 * Obs: Al editar la definicion de registro dependiendo de la necesidad del programa, se edebe editar esta funcion para poder usarla
 * 
 * @return Registro 
 */
Registro creaRegistro(){ // crea un registro nuevo, lee sus valor y devuelve una copia
  
  Registro *ptrNuevoRegistro; // libera espacio en memoria para el nuevo registro

  printf("Funcion Crear Nuevo Registro\n");
  /*   ptrNuevoRegistro->id = 0; */
  printf("Ingrese Numero De los valores del registro: ");
  scanf("%d", &ptrNuevoRegistro->valor);
  /*   printf("Ingrese El nombre del Propietario de la Cuenta: ");
  scanf("%s", ptrNuevoRegistro->nombre);
  printf("ingrese EL estado de la cuenta: ");
  scanf("%lf", &ptrNuevoRegistro->estadoDeCuenta); */


  return *ptrNuevoRegistro; // retorna una copia del registro creado
}

/**
 * @brief libera espacio en memoria para el nuevo registro
 * 
 * @param ptrRegistro Registro a ser liberado
 */
void borraRegistro(Registro *ptrRegistro){
  free(ptrRegistro); //libera espacio en memoria para el nuevo registro
}
