/* david emmanuel gomez arca 6660354 0972411806 */
#include"fun_60354.h"

int main()  /* inicio de porgrama */
{
  
  printf("Bienvenido!\n");
  int opcion;
  do
  {
    menu();
    scanf("%d", &opcion);

    switch (opcion)
    {
      case 1:
        opcion1();
        break;
      case 2:
        opcion2();
      case 3:
        break;
      default:
        printf("Opcion No valida\n Reingresar \n");
        break;
    }

  } while (opcion != 3);
  
  system("pause");
  return 0;
}

void menu(){
  printf("%s\n%s\n%s\n%s\n", "Ingrese su opcion", "Opcion 1: Programa de texto", "Opcion 2: Programa de Matriz magica", "Opcion 3: Salir");
}

void opcion1(){
  char expresion[80];


  scanf ("%s", expresion);
  printf("%s\n" ,expresion);
 
  apariciones(expresion);
  vocales( expresion);


}

void apariciones( char expresion[]){
  aparicion( expresion, 'p');
  aparicion( expresion, 'r');
  aparicion( expresion, 'c');
  aparicion( expresion, 'e');
  aparicion( expresion, 'o');
}

void aparicion ( char exp[], char p){
  int i;
  for(i = 0; i< strlen(exp); i++){
    if( exp[i] == p){
      printf("%c aparece en la posicion %d\n", p, i);
      break;
    }
  }
}

void vocales( char exp[]){
  int cantidadAparicion[5] = {0}; /* posiciones 0 = a , 1 = e,... 4 = u */
  char vocalesstr[] = "aeiou";
  int longitud, i;
  longitud = strlen(exp);
  for ( i = 0; i < longitud; i++)
  {
    if( exp[i] == 'a' || exp[i] == 'A'){
      cantidadAparicion[0]++;
    }
    if( exp[i] == 'e' || exp[i] == 'E'){
      cantidadAparicion[1]++;
    }
    if( exp[i] == 'i' || exp[i] == 'I'){
      cantidadAparicion[2]++;
    }
    if( exp[i] == 'o' || exp[i] == 'O'){
      cantidadAparicion[3]++;
    }
    if( exp[i] == 'u' || exp[i] == 'U'){
      cantidadAparicion[4]++;
    }
    
  }
  
  for(i = 0; i< 5; i++){
    if( cantidadAparicion[i] != 0){
      printf("la vocal %c aparece %d veces \n su pocentaje de aparicion es %d prociento\n", vocalesstr[i], cantidadAparicion[i], 100*(cantidadAparicion[i]/longitud) );
    }
    else
    {
      printf("La vocan %c no existe o no tiene repeticion\n", vocalesstr[i]);
    }
    
  }
}


void opcion2(){
  int mat[3][3] = {0};
  int i = 0 , j = 0;
  int val;
  for( i = 0; i< 3; i++){
    for( j = 0; j <3 ; j++){
      scanf("%d", &val);
      while (val < 0 || val > 9)
      {
        printf("alor incorrecto reingrese");
        scanf("%d", &val);
        
      }
      mat[i][j] = val;
    }
  }
}