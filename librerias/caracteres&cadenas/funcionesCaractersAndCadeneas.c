#include"CaractersAndStrings.h"




/**
 * @brief Recibe un caracter y devuelve su valor entero 
 * 
 * @param caracter Caracter a ser convertido
 * @return int 
 */
int charToInt( char caracter){
  return caracter - '0';
}

/**
 * @brief Convierte un entero a digito
 * 
 * @param numero Entero a ser convertido
 * @return char 
 */
char enteroACaracter(int numero){
    return numero + '0';
}


/**
 * @brief Imprime recursivamente los caracteres de una cadena en orden inverso
 * 
 * @param ptrS Puntero a la cadena
 */
void inverso( const char * const ptrS )
{
  /* si es el final de la cadena */
  if ( ptrS[ 0 ] == '\0' ) { /* caso base */
    return; 
  } /* fin de if */ 
  else { /* si no es el final de la cadena */ 
    inverso( &ptrS[ 1 ] ); /* paso recursivo */
    putchar( ptrS[ 0 ] ); /* utiliza putchar para desplegar los caracteres */
  } /* end else */
} /* fin de la función inverso */


/**
 * @brief Lee una cadena con espacios por medio de la funcion getchar
 * 
 * @param cadena Cadena Destino
 */
void leeConEspacios( char cadena[] ){
  char c;
  int i = 0;
  while ( (c = getchar() ) != '\n' )
  {
    cadena[i++] = c;
  } 
  
}


/**
 * @brief Separa las palabras de un enunciado en un array
 * 
 * @param array Array destino
 * @param enunciado Cadena a ser Spliteada
 * @param separador Caracter separador
 */
void separaParabrasEnArray( char *array[], char enunciado[], char separador[])
{

  int i;
  char *ptrToken = strtok(enunciado, separador);

  while ( ptrToken != NULL)
  {
    array[i++] = ptrToken;
    ptrToken = strtok( NULL, separador);
  }

}

/**
 * @brief Retorna letras de la A a la H para rempresentar las columnas del tablero de ajedrez
 * 
 * @param val Posicion en el tablero
 * @return char 
 */
char getLetra(int val){ 
  switch (val)
  {
  case 1:
    return 'a';
    break;
  case 2:
    return 'b';
    break;
  case 3:
    return 'c';
    break;
  case 4:
    return 'd';
    break;
  case 5:
    return 'e';
    break;
  case 6:
    return 'f';
    break;
  case 7:
    return 'g';
    break;
  case 8:
    return 'h';
    break;
  default:
    return 'x';
    break;
  }
}

/**
 * @brief Devuelve la cantidada de apariciones de cada vocal en una cadena
 * 
 * @param exp Cadena a evaluar
 */
void vocales( char exp[])
{
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
      printf("La vocal %c no existe o no tiene repeticion\n", vocalesstr[i]);
    }
    
  }
}

/**
 * @brief Emite un mensaje con la posicion de primera a paricion de un caracter en una cadena
 * 
 * @param exp Cadena a evaluar
 * @param p Caracter buscado
 */
void primeraAparicion ( char exp[], char p)
{
  int i;
  for(i = 0; i< strlen(exp); i++){
    if( exp[i] == p){
      printf("%c aparece en la posicion %d\n", p, i);
      break;
    }
  }
}
