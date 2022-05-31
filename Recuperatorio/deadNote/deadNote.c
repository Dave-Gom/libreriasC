#include"header.h"

int main(int argc, char const *argv[])
{
  int n, m, acum = 0, iterador, aux, nombresEnPag = 0;//define las variables
  scanf("%d", &n);//cantidad de dias
  scanf("%d", &m);//cantidad de nombres por pagina
  int a[n], t[n]; //vectores para almacernar la cantidad de nombres a escribir cadad dia 

  for ( iterador = 0; iterador < n; iterador++) //indica cuantos nombres se escribiran cada dia
  {
    scanf("%d", &aux);
    a[iterador] = aux;
  }

  for ( iterador = 0; iterador < n; iterador++)
  {
    nombresEnPag += a[iterador]; //aumenta la cantidad de nombres en la pagina
    if( nombresEnPag >= m){ // si la cantidad de nombres en la pagina es mayor al limite
      t[iterador] = nombresEnPag / m; //cuenta cuantas veces se excedio el limite
      nombresEnPag = nombresEnPag % m; //escribe los nombres en la pagina actual
    }
  }
  
  for(iterador = 0; iterador<n; iterador++) //imprime el resultado
    printf("%d\t", t[iterador]);
  

  return 0;
}
