#include "headerDocumentado.h"

/* FUNCIONES CON ARREGLOS UNIDIMENSIONALES */

/**
 * @brief Retorna el Mayor valor almacenado en un arreglo de enteros
 *
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int mayor(int arreglo[], const int longitud)
{

    int mayor, // valor mayor almacenado
        i;     // iterador
    for (i = 0; i < longitud; i++)
    {

        if (i == 0)
            mayor = arreglo[i]; // asigna el primer elemento siempre como elemento mayor en principio

        if (arreglo[i] > mayor)
            mayor = arreglo[i];
    }

    return mayor;
}

/**
 * @brief retorna la cantidad de elementos diferentes en un array
 *
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int cantidadElementosDiferentes(int arreglo[], const int longitud)
{
    int contador = 0, i, cantidad;
    int dimension = longitud;
    for (i = 0; i < longitud; i++)
    {
        cantidad = cantidadAparicionElemento(arreglo[i], &arreglo[i], dimension);
        if (cantidad == 1)
        {
            contador++;
        }
        dimension--;
    }

    return contador;
}

/**
 * @brief retorna la cantidad de apariciones de un elemento en un array
 *
 * @param valor
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int cantidadAparicionElemento(int valor, int arreglo[], int longitud)
{
    int i = 0;
    int contador = 0;
    for (i = 0; i < longitud; i++)
    {
        if (valor == arreglo[i])
            contador++;
    }
    return contador;
}

/**
 * @brief retorna la suma de todos los elementos de un array
 *
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int sumaElementosArray(int arreglo[], int longitud)
{
    int s = 0;
    int i = 0;
    for (i = 0; i < longitud; i++)
    {
        s += arreglo[i];
    }
    return s;
}

/**
 * @brief copia los elementos unicos de un array en otro
 *
 * @param arrayOrigen Arreglo del que se copiaran los elementos
 * @param dimensionOrigen dimension del elemento origen
 * @param arrayDestino Arreglo que recibira la copia de los elementos
 *
 * @author David Gomez
 */
void arraySimplificado(int arrayOrigen[], int dimensionOrigen, int arrayDestino[])
{
    int contador = 0, i, cantidad;
    int dimension = dimensionOrigen;
    for (i = 0; i < dimensionOrigen; i++)
    {
        cantidad = cantidadAparicionElemento(arrayOrigen[i], &arrayOrigen[i], dimension);
        if (cantidad == 1)
        {
            arrayDestino[contador] = arrayOrigen[i];
            contador++;
        }
        dimension--;
    }
    ordSeleccion(arrayDestino, contador);
}

/**
 * @brief Retorna el menor valor almacenado en un arreglo de enteros
 *
 * @param arreglo Arreglo
 * @param longitud Dimension del arreglo
 * @return int
 */
int menor(int arreglo[], const int longitud)
{

    int menor, // valor menor del array
        i;     // iterador
    for (i = 0; i < longitud; i++)
    {

        if (i == 0)
            menor = arreglo[i]; // asigna el primer elemento como menor

        if (arreglo[i] < menor) // si encueltra un elemento que sea menor
            menor = arreglo[i]; // asigna ese valor a la variable menor
    }

    return menor;
}

/**
 * @brief Copia los elemenots del arreglo origen al arreglo destino
 *
 * @param origen Arreglo del que se copiaran los elementos
 * @param destino Arreglo que recibira la copia de los elementos
 * @param dim dimension de ambos arreglos (Debe ser igual)
 */
void copiaArreglo(int origen[], int destino[], const int dim)
{
    int i; // iterador
    for (i = 0; i < dim; i++)
    {
        destino[i] = origen[i];
    }
}

/**
 * @brief Imprimie un arreglo unidimensional separado por tabulaciones
 *
 * @param arreglo Arreglo a ser impreso
 * @param longitud Dimension del arreglo
 */
void imprimeArreglo(int arreglo[], const int longitud)
{
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf(" %d\t", arreglo[i]);
    }
    printf("\n");
}

/**
 * @brief Imprimie un arreglo unidimensional separado por tabulaciones
 *
 * @param arreglo Arreglo a ser impreso
 * @param longitud Dimension del arreglo
 */
void imprimeArregloFloat(float arreglo[], const int longitud)
{
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf(" %f\t", arreglo[i]);
    }
    printf("\n");
}

/**
 * @brief Asigna el valor inicial 0 a todas las posiciones del arreglo
 *
 * @param arreglo Arreglo a ser inicializado
 * @param lingitud Dimension del arreglo
 */
void iniciaArreglo(int arreglo[], const int lingitud)
{
    int i;
    for (i = 0; i < lingitud; i++)
    {
        arreglo[i] = 0;
    }
}

/**
 * @brief Carga valores en un arrego de dimension dada
 *
 * @param arreglo Arreglo a ser cargado
 * @param lenght Dimension del Areglo
 */
void cargaVector(int arreglo[], const int lenght)
{
    int iterador, valor;

    for (iterador = 0; iterador < lenght; iterador++)
    {
        scanf("%d", &valor);
        arreglo[iterador] = valor;
    }
}

/**
 * @brief Retorna la posicion del menor elemento de un arreglo
 *
 * @param arreglo Arreglo en el que se buscara
 * @param longitud Dimension del arreglo
 * @return int
 */
int posMenor(const int arreglo[], const int longitud)
{

    int menor, i;
    for (i = 0; i < longitud; i++)
    {

        if (i == 0)
            menor = i;

        if (arreglo[i] < arreglo[menor])
            menor = i;
    }
    return menor;
}

/**
 * @brief Retorna la posicion del mayor elemento de un arreglo
 *
 * @param arreglo Arreglo en el que se buscara
 * @param longitud Dimension del arreglo
 * @return int
 */
int posMayor(const int arreglo[], const int longitud)
{

    int mayor, i;
    for (i = 0; i < longitud; i++)
    {

        if (i == 0)
            mayor = i;

        if (arreglo[i] > arreglo[mayor])
            mayor = i;
    }
    return mayor;
}

/**
 * @brief Retorna 0 si un array es Monotono.
 *
 * Para que una array sea monotono, todos sus valores deben ser iguales
 *
 * @param array Arreglo a ser evaluado
 * @param dim Dimension del arreglo
 * @return int
 */
bool esMonotona(int array[], int dim)
{
    int i;              // iterador
    int bandera = true; // su valor determina si es o no monotona
    int primerValor;    // primer valor del arreglo
    for (i = 0; i < dim; i++)
    {
        if (i == 0)
            primerValor = array[i];

        if (array[i] != primerValor)
        {
            bandera = false;
            break;
        }
    }

    return bandera;
}

/* FUNCIONES CON ARREGLOS MULTIDIMINSIONALES (MATRICES) */

/**
 * @brief Asigna el valor inicial 0 a todas las posiciones de la matriz
 *
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser inicializada
 */
void iniciaMatriz(const int fila, const int colum, int matriz[][colum])
{
    int i, j;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < colum; j++)
            matriz[i][j] = 0;
    }
}

/**
 * @brief Carga valores en una matriz de dimensiones dadas
 *
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser cargada
 */
void cargaMatriz(const int fila, const int colum, int matriz[][colum])
{
    int i, j, aux;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < colum; j++)
        {
            scanf("%d", &aux);
            matriz[i][j] = aux;
        }
    }
}

/**
 * @brief Leer la primera fila de una matriz y asigna los mismos valore a las demas filas
 *
 * @param fila Cantidad de filas de la matriz
 * @param colum Cantidad de columnas de la matriz
 * @param matriz Matriz a ser cargada
 */
void copiaPrimerafilaEnMatriz(const int fila, const int colum, int matriz[][colum], bool introducePrimeraLinea)
{
    int i, j, aux;
    /* solicita que  si ingrese la primera fila del arreglo */
    if (introducePrimeraLinea)
    {
        for (j = 0; j < colum; j++)
        {
            scanf("%d", &aux);
            matriz[0][j] = aux;
        }
    }

    /* copia los valores de la primera fila en el resto de la matriz */
    for (i = 1; i < fila; i++)
    {
        for (j = 0; j < colum; j++)
        {
            matriz[i][j] = matriz[0][j];
        }
    }
}

/**
 * @brief Verifica la existencia  de ceros en una matriz, si existe, devuelce -1 si no existen devuelce cero
 *
 * @param fila Cantidad de filas de la matriz
 * @param col Cantidad de comlumnas de la matriz
 * @param matriz Matriz a ser verificada
 * @return int
 */
bool hayCerosEnMatriz(int fila, int col, int matriz[][col])
{
    int i, j;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (matriz[i][j] == 0)
            {
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief retorna cero si la matriz es hermosa, -1 en caso contario.
 *
 * Para que una matriz sea hermosa, la suma de todas sus filas, debe ser igual a la suma de todas sus columnas e igual a la suma de sus diagonales
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de Comlumnas
 * @param matriz Matriz a ser evaluada
 * @return int
 */
bool esHermosa(int fila, int columna, int matriz[][columna])
{

    if (fila != columna)
    {
        printf("No es Cuadrada\n");
        return false; // para se hermosa debe ser cuadrada
    }
    int i;
    int sumadeFilas[fila];
    int sumadeColumnas[columna];

    sumaDeColumnas(fila, columna, matriz, sumadeColumnas);
    sumaDeFilas(fila, columna, matriz, sumadeFilas);

    if (sumadeColumnas[0] != sumadeFilas[0] || esMonotona(sumadeColumnas, fila) || esMonotona(sumadeColumnas, columna))
        return false; // si la condicion de arriba se cumple sabemos que no es monotna y devolvemos -1

    if (sumaDiagonalPrincipal(fila, columna, matriz) != sumaDiagonalSecundaria(fila, columna, matriz) != sumadeColumnas[0])
    {
        return false;
    }

    return true;
}

/* Funciones de busqueda */

/**
 * @brief Retorna la posicion de un valor dentro de un arreglo, -1 si el valor no se encuentra en el arreglo
 *
 * @param arreglo Arreglo en el cual se buscara
 * @param longitud Longitud del arreglo
 * @param valorABuscar Valor buscado
 * @return int
 *
 * @author Dave Gomez
 */
int busquedaLineal(int arreglo[], const int longitud, int valorABuscar)
{
    int i, bandera = 0;
    for (i = 0; i < longitud; i++)
    {
        if (arreglo[i] == valorABuscar)
        {
            bandera = 1;
            break;
        }
    }

    if (bandera == 0)
        i = -1;

    return i;
}

/**
 * @brief Retorna la posicion de un valor dentro de un arreglo, -1 si el valor no se encuentra en el arreglo por el metodo de la busqueda binaria de forma iterativa
 * obs: Solo funciona en arreglos ordenados
 *
 * @param arreglo Arreglo en el cual se buscara
 * @param valBuscado Valor buscado
 * @param inicio Inicio de posicion a buscar
 * @param fin Fin de Posicion a buscar
 * @return int
 *
 * @author Dave Gomez
 */
int busquedaBinaria(int arreglo[], int valBuscado, int inicio, int fin)
{
    int central;
    while (inicio <= fin)
    {

        central = (inicio + fin) / 2;

        if (valBuscado == arreglo[central])
        {
            return central;
        }
        else if (valBuscado < arreglo[central])
        {
            fin = central - 1;
        }
        else
        {
            inicio = central + 1;
        }
    }

    return -1;
}

/**
 * @brief Retorna la posicion de un valor dentro de un arreglo, -1 si el valor no se encuentra en el arreglo por el metodo de la busqueda binaria de forma recursiva
 *
 * @author Dave Gomez
 * @param arreglo Arreglo en el cual se buscara
 * @param busqueda Valor buscado
 * @param izquierda Inicio de posicion a buscar
 * @param derecha Fin de Posicion a buscar
 * @return int
 *
 * @author Dave Gomez
 *
 */

int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha)
{
    if (izquierda > derecha)
        return -1;

    int indiceDeLaMitad = ((izquierda + derecha) / 2);

    int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
    if (busqueda == valorQueEstaEnElMedio)
    {
        return indiceDeLaMitad;
    }

    if (busqueda < valorQueEstaEnElMedio)
    {
        // Entonces está hacia la izquierda
        derecha = indiceDeLaMitad - 1;
    }
    else
    {
        // Está hacia la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(arreglo, busqueda, izquierda, derecha);
}

/**
 * @brief Agrega en una Arreglo la suma de cada Columan de una matriz
 *
 * @param fila Cantidad de filas
 * @param col Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @param sumaCol Arreglo de sumas
 */
void sumaDeColumnas(int fila, int col, int matriz[][col], int sumaCol[])
{
    int i, j, acum = 0;
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < fila; j++)
        {
            acum += matriz[j][i];
        }
        sumaCol[i] = acum;
        acum = 0;
    }
}

/**
 * @brief Agrega a un array la suma de todas las filas de la matriz
 *
 * @param fila Cantidad de filas
 * @param col Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @param sumaFilas Arreglo de sumas
 */
void sumaDeFilas(int fila, int col, int matriz[][col], int sumaFilas[])
{
    int i, j, acum = 0;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < col; j++)
        {
            acum += matriz[i][j];
        }
        sumaFilas[i] = acum;
        acum = 0;
    }
}

/**
 * @brief Retorna el valor de la suma de la diagonal principal de una matriz
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @return int
 */
int sumaDiagonalPrincipal(int fila, int columna, int matriz[][columna])
{
    int i, j, acum = 0;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            if (i == j)
            {
                acum += matriz[i][j];
                break;
            }
        }
    }
    return acum;
}

/**
 * @brief Retorna el valor de la suma de la diagonal secundaria de una matriz
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de Columnas
 * @param matriz Matriz a ser sumada
 * @return int
 */
int sumaDiagonalSecundaria(int fila, int columna, int matriz[][columna])
{
    /* trabajamos con matrices cuadradas, lo que implica que fila == comulna */
    if (fila != columna)
        return 'x';

    int i, j, acum = 0;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            if (i + j == fila - 1)
            {
                acum += matriz[i][j];
                break;
            }
        }
    }
    printf("\n");
    return acum;
}

/**
 * @brief Imprimie una matriz formateada en forma de Table
 *
 * @param filas Cantidad de filas
 * @param columnas Cantidad de columnas
 * @param Matriz Matriz a ser impresa
 */
void imprimeMatrizFormat(int filas, int columnas, int Matriz[][columnas])
{
    int i;
    int j;

    /* printf("\n\nEste es el tablero:\n\n "); */
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf(" %d\t", Matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

/**
 * @brief Imprimie una matriz formateada en forma de Table
 *
 * @param filas Cantidad de filas
 * @param columnas Cantidad de columnas
 * @param Matriz Matriz a ser impresa
 */
void imprimeMatrizFloatFormat(int filas, int columnas, float Matriz[][columnas])
{
    int i;
    int j;

    /* printf("\n\nEste es el tablero:\n\n "); */
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf(" %f\t", Matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

/**
 * @brief Lee solo digitos del 0 al 9 a una matriz dada
 *
 * @param fila Cantidad de filas
 * @param columna Cantidad de columnas
 * @param mat Matriz a ser cargada
 */
void cargaMatrizDeDigitos(int fila, int columna, int mat[][columna])
{

    int i, j;
    int val;
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            scanf("%d", &val);
            while (val < 0 || val > 9)
            {
                printf("valor incorrecto reingrese");
                scanf("%d", &val);
            }
            mat[i][j] = val;
        }
    }
}

/**
 * @brief Separa los digitos de un entero en un array
 *
 * @param arreglo Arreglo destino
 * @param valor Entero a ser spliteado
 */
void digitosInt(int arreglo[], int valor)
{
    int longitud = 9; /* un int solo puede almacenar numeros de hasta 9 digios */
    int cont = 0, digito;
    while (valor != 0)
    {
        digito = valor % 10;
        arreglo[cont] = digito;
        valor = valor / 10;
        cont++;
    }
}

/* Funciones de caracteres y cadenas */

/**
 * @brief Recibe un caracter y devuelve su valor entero
 *
 * @param caracter Caracter a ser convertido
 * @return int
 */
int charToInt(char caracter)
{
    return caracter - '0';
}

/**
 * @brief Convierte un entero a digito
 *
 * @param numero Entero a ser convertido
 * @return char
 */
char enteroACaracter(int numero)
{
    return numero + '0';
}

/**
 * @brief Imprime recursivamente los caracteres de una cadena en orden inverso
 *
 * @param ptrS Puntero a la cadena
 */
void inverso(const char *const ptrS)
{
    /* si es el final de la cadena */
    if (ptrS[0] == '\0')
    { /* caso base */
        return;
    } /* fin de if */
    else
    {                      /* si no es el final de la cadena */
        inverso(&ptrS[1]); /* paso recursivo */
        putchar(ptrS[0]);  /* utiliza putchar para desplegar los caracteres */
    }                      /* end else */
} /* fin de la función inverso */

/**
 * @brief Lee una cadena con espacios por medio de la funcion getchar
 *
 * @param cadena Cadena Destino
 */
void leeConEspacios(char cadena[])
{
    char c;
    int i = 0;
    fflush(stdin);
    while ((c = getchar()) != '\n')
    {
        cadena[i++] = c;
    }
    cadena[i] = '\0';
}

/**
 * @brief Separa las palabras de un enunciado en un array
 * @attention el array debe ser definido con una longitud estatica, ej: char *array[100] = {NULL};
 * @param array Array destino
 * @param enunciado Cadena a ser Spliteada
 * @param separador Caracter separador
 * @return int La longitud del array generado
 */
int separaParabrasEnArray(char *array[], char enunciado[], char separador[])
{
    int i = 0;
    char texto[strlen(enunciado)];
    strcpy(texto, enunciado);
    char *ptrToken = strtok(texto, separador);
    while (ptrToken != NULL)
    {
        array[i] = ptrToken;
        ptrToken = strtok(NULL, separador);
        i++;
    }
    return i;
}

/**
 * @brief Retorna letras de la A a la H para rempresentar las columnas del tablero de ajedrez
 *
 * @param val Posicion en el tablero
 * @return char
 */
char getLetra(int val)
{
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
void vocales(char exp[])
{
    int cantidadAparicion[5] = {0}; /* posiciones 0 = a , 1 = e,... 4 = u */
    char vocalesstr[] = "aeiou";
    int longitud, i;
    longitud = strlen(exp);
    for (i = 0; i < longitud; i++)
    {
        if (exp[i] == 'a' || exp[i] == 'A')
        {
            cantidadAparicion[0]++;
        }
        if (exp[i] == 'e' || exp[i] == 'E')
        {
            cantidadAparicion[1]++;
        }
        if (exp[i] == 'i' || exp[i] == 'I')
        {
            cantidadAparicion[2]++;
        }
        if (exp[i] == 'o' || exp[i] == 'O')
        {
            cantidadAparicion[3]++;
        }
        if (exp[i] == 'u' || exp[i] == 'U')
        {
            cantidadAparicion[4]++;
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (cantidadAparicion[i] != 0)
        {
            printf("la vocal %c aparece %d veces \n su pocentaje de aparicion es %d prociento\n", vocalesstr[i], cantidadAparicion[i], 100 * (cantidadAparicion[i] / longitud));
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
void primeraAparicion(char exp[], char p)
{
    int i;
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == p)
        {
            printf("%c aparece en la posicion %d\n", p, i);
            break;
        }
    }
}

/* Funciones de Ordenamiento */

/**
 * @brief Ordenamiento de intercambio. Ordena un array en orden ascendente por el metodo de intercambio de variables
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void ordIntecambio(int arreglo[], int longitud)
{
    int i,   // iterador
        j,   // iterador
        aux; // contenedor temporal del valor

    for (i = 0; i < longitud - 1; i++) // inicia desde la primera posicion del arreglo hasta la posicion longitud -1
    {
        for (j = i + 1; j < longitud; j++) // inicia desde la segunda posicion de arreglo hasta la ultima posicion
        {
            if (arreglo[i] > arreglo[j]) // si el arreglo de la segunda pisicon i > al de posicion j los intercambia
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }
}

/**
 * @brief Ordena un Array por el metodo de seleccion. Ejemplo del libro Joyanes
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 *
 * @author David Gomez
 */
void ordSeleccion(int arreglo[], int longitud) // ejemplo joyanes
{
    int indiceMenor, // pos menor
        i,           // iterador
        j;           // iterador
    double aux;      // contenedor temporal
    for (i = 0; i < longitud - 1; i++)
    {
        indiceMenor = i; // inicial el menor elemento en el principio de cada iteracion

        for (j = i + 1; j < longitud; j++) // empieza a buscar una posicion despues de la posicion de i
        {
            if (arreglo[j] < arreglo[indiceMenor])
                indiceMenor = j; /* situa el elemento menor */
        }

        if (i != indiceMenor)
        { /* si existia un elemento menor lo intercambia por la posicion actual del puntero */
            aux = arreglo[i];
            arreglo[i] = arreglo[indiceMenor];
            arreglo[indiceMenor] = aux;
        }
    }
}

/**
 * @brief Ordena un arreglo por el metodo de seleccion. Desarrollo propio, adaptado para desarrollarse de forma recursiva
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 *
 * @author David Gomez
 */
void ordSeleccionRecusiva(int arreglo[], int longitud)
{
    int aux,           // contenedor temporal
        posicionMenor; // posicion del elemento menor
    if (longitud > 1)
    {
        posicionMenor = posMenor(arreglo, longitud); // determina la posicion del menor elemento del arreglo
        /* intercambia el arreglo de la posicion inicial con el menor  */
        aux = arreglo[0];
        arreglo[0] = arreglo[posicionMenor];
        arreglo[posicionMenor] = aux;
        /*  */

        ordSeleccionRecusiva(&arreglo[1], longitud - 1); // recursion con el array a partir de la posicion dos
    }
}

/**
 * @brief Ordena un arreglo de forma ascendente por el metodo de burbuja
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void burbujaAsc(int arreglo[], const int longitud)
{
    int pasadas, i, almacenador;

    for (pasadas = 0; pasadas < longitud; pasadas++)
    {
        for (i = 0; i < longitud - 1; i++)
        {
            if (arreglo[i + 1] < arreglo[i])
            {
                almacenador = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = almacenador;
            }
        }
    }
}

/**
 * @brief Ordena un arreglo de forma descendente por el metodo de burbuja
 *
 * @param arreglo Arreglo a ser ordeneado
 * @param longitud Dimension del arreglo
 */
void burbuja_des(int arreglo[], const int longitud)
{
    int pasadas, i, almacenador;

    for (pasadas = 0; pasadas < longitud; pasadas++)
    {
        for (i = 0; i < longitud - 1; i++)
        {
            if (arreglo[i + 1] > arreglo[i])
            {
                almacenador = arreglo[i];
                arreglo[i] = arreglo[i + 1];
                arreglo[i + 1] = almacenador;
            }
        }
    }
}

/**
 * @brief Ordena un arreglo de forma ascendente por el metodo de ordenacion rapida (Quicksort)
 *
 * @param array Arreglo a ser ordenado
 * @param inicio Inicio de rango a ordenar
 * @param fin Fin de rango a ordenar
 */
void quickSortD(double array[], int inicio, int fin)
{
    int i = 0,   // iterador
        j = 0,   // iterador
        central; // indicador del centro del array
    double pivote;
    central = (inicio + fin) / 2; // ubica el centro del array
    pivote = array[central];      // ubica en el valor pivote el valor del elemento central del array
    double temporal;
    do
    {
        while (array[i] < pivote)
            i++; // ubica el primer elemento menor que el pivote
        while (array[j] > pivote)
            j++; // ubica el primer elemento mayor que el pivote

        if (i <= j)
        { // si la posicion del primer elemento mayo y menor, el menr es menor o igual al mayor

            // intercambia los valores
            temporal = array[i];
            array[i] = array[j];
            array[j] = temporal;
            i++; // incrementa la posicion del elemento menor
            j--; // decrementa la posicion del elemento mayor
        }

    } while (i <= j);

    if (inicio <= j)
    {                                 // si el inico es menor o igual a la posicion del primer elemento mayor al pivote
        quickSortD(array, inicio, j); // recursadesde el inicio hasta la posicion
    }

    if (i < fin)
    {                              // si el inico es menor o igual a la posicion del primer elemento mayor al pivote
        quickSortD(array, i, fin); // recursa desde la posicion hasta el fin
    }
}

/**
 * @brief Ordena un arreglo de forma ascendente por el metodo de ordenacion rapida (Quicksort)
 * @param array
 * @param izquierda
 * @param derecha
 *
 * @author David Gomez
 */
void quickSortI(int arreglo[], int izquierda, int derecha)
{
    int izq, der, temporal, pivote;
    izq = izquierda;
    der = derecha;
    pivote = arreglo[(izq + der) / 2];

    do
    {
        while (arreglo[izq] < pivote && izq < derecha)
            izq++;

        while (pivote < arreglo[der] && der > izquierda)
            der--;

        if (izq <= der)
        {
            temporal = arreglo[izq];
            arreglo[izq] = arreglo[der];
            arreglo[der] = temporal;
            izq++;
            der--;
        }
    } while (izq < der);

    if (izquierda < der)
    {
        quickSortI(arreglo, izquierda, der);
    }
    if (derecha > izq)
    {
        quickSortI(arreglo, izq, derecha);
    }
}

/**
 * @brief Ordena un array por el medodo de Mezcla
 * @param array
 * @param longitud
 *
 * @author David Gomez
 */
void mergeSortArrays(int array[], int longitud)
{
    int medio = longitud / 2;
    if (longitud != 1)
    {
        mergeSortArrays(&array[0], medio);
        mergeSortArrays(&array[medio], longitud - medio);
    }
    mezclaEnOrden(&array[0], medio, &array[medio], longitud % 2 == 0 ? medio : medio + 1, array);
}

/**
 * @brief Combina dos arrays ordenados en un unico array ya ordenado
 * @param array1
 * @param dim1
 * @param array2
 * @param dim2
 * @param arrayDestino
 *
 * @author David Gomez
 */
void mezclaEnOrden(int array1[], int dim1, int array2[], int dim2, int arrayDestino[])
{
    int i1 = 0, i2 = 0, iAux = 0;
    int arrayAux[dim1 + dim2];

    while (i1 < dim1 || i2 < dim2)
    {
        if (i1 < dim1 && array1[i1] <= array2[i2])
        {
            arrayAux[iAux] = array1[i1];
            i1++;
        }
        else if (i2 < dim2)
        {
            arrayAux[iAux] = array2[i2];
            i2++;
        }
        else
        {
            arrayAux[iAux] = array1[i1];
            i1++;
        }
        iAux++;
    }

    copiaArreglo(arrayAux, arrayDestino, dim1 + dim2);
}

/**
 * @brief  Ingrese la fecha en formato dd/mm/aaaa
 *
 * @param array[] arreglo a ser ordenado
 * @param dimension dimension del arreglo
 *
 * @author David Gomez
 */
void ordenaArrayConArboles(int array[], int dimension)
{
    Arbol *Arbol = malloc(sizeof(*Arbol));
    cargaArregloEnArbol(Arbol, array, dimension);
    inOrdenArray(Arbol->Raiz, array, dimension);
    free(Arbol);
}

/**
 * @brief  Ingrese la fecha en formato dd/mm/aaaa
 *
 * @param cadena
 */
void leeFechaFormat(char cadena[])
{
    int dias, mes, anio;
    printf("\n Ingrese la fecha en formato dd/mm/aaaa\n");

    printf("Dias: ");
    scanf("%d", &dias); // lee los dias de la fecha
    while (dias > 30 || dias < 1)
    {
        // mientras este en un rango no valido
        printf("\nFecha incorrecta, favor reinsertar.\n");
        printf("Dias: ");
        scanf("%d", &dias); // lee los dias de la fecha
    }

    printf("Mes: ");
    scanf("%d", &mes);
    while (mes > 12 || mes < 1)
    {
        // mientras este en un rango no valido
        printf("\nFecha incorrecta, favor reinsertar.\n");
        scanf("%d", &mes);
        printf("Mes: ");
    }

    printf("Año: ");
    scanf("%d", &anio);
    while (anio > 2022 || anio < 1900)
    {
        // mientras este en un rango no valido
        printf("\nFecha incorrecta, favor reinsertar.\n");
        printf("Año: ");
        scanf("%d", &anio);
    }

    sprintf(cadena, "%d/%d/%d\n", dias, mes, anio);
}

/**
 * @brief  Ingrese la fecha en formato dd/mm/aaaa
 *
 * @param cadena
 * @author David Gomez
 */
void enteroAString(int valor, char *cadena)
{
    sprintf(cadena, "%d", valor);
}

/**
 * @brief  Ingrese la fecha en formato dd/mm/aaaa
 *
 * @param *palabras[] array de palabras a ser impreso
 * @param longitud int longitud del array
 *
 * @return void
 * @author David Gomez
 */
void imprimeArrayDePalabras(char *palabras[], int longitud)
{
    int i = 0;
    for (i = 0; i < longitud; i++)
    {
        printf("%s\t", palabras[i]);
    }
}

/**
 * @brief Recibe una cadena cuenta cuantas palabras hay en base a un separador
 * @param palabras
 * @param separador
 * @return int
 *
 * @author David Gomez
 */
int cantidadDePalabras(char palabras[], char separador[])
{
    int i = 0;
    char texto[strlen(palabras)];
    strcpy(texto, palabras);
    char *ptrToken = strtok(texto, separador);
    while (ptrToken != NULL)
    {
        ptrToken = strtok(NULL, separador);
        i++;
    }
    return i;
}

/**
 * @brief Recibe un array de palabras  e inicializa todos los punteros a null
 * @param palabras
 * @param longitudArray
 *
 * @author David Gomez
 */
void inicializaArrayPalabras(char *palabras[], int longitudArray)
{
    int i;
    for (i = 0; i < longitudArray; i++)
    {
        palabras[i] = NULL;
    }
}

/* Funciones de Pruebas y generacion aleatoria */

/**
 * @brief Genera numeros aleatorios desde el cero hasta un valor especificado
 * incluir stdlib para usar rand() y time()
 * @param arreglo Arreglo en que se cargaran los numero
 * @param longitud longitud del arreglo
 * @param valorLimite valor techo
 *
 * @author Dave Gomez
 */
void arrayAleatorio(int arreglo[], int longitud, int valorLimite)
{
    int i, j;
    srand(time(0));
    for (i = 0; i < longitud; i++)
    {
        arreglo[i] = rand() % valorLimite;
    }
}

/**
 * @brief Inicializa una matriz con valores aleatorios del 0 a valor especificado
 *
 * @param fila cantidad de filas
 * @param columna cantidad de columnas
 * @param arreglo matriz a ser cargada
 * @param valLimite valor maximo
 */
void matrizAleatoria(int fila, int columna, int arreglo[][columna], int valLimite)
{ /*Inicializa una matriz con valores aleatorios del 0 a valor especificado */
    /* incluir stdlib para usar rand() y time() */
    int i, j;
    srand(time(NULL));
    for (i = 0; i < fila; i++)
    {
        for (j = 0; j < columna; j++)
        {
            arreglo[i][j] = rand() % valLimite;
        }
    }
}

/**
 * @brief devuelve un numero entero positivo, negativo o cero aleatorio
 *
 * @param limite valor maximmo
 * @return int
 */
int enteroAleatorio(int limite)
{ // devuelve un numero entero positivo, negativo o cero aleatorio
    int valor1 = (rand() % limite);
    int valor2 = (rand() % limite);

    return valor1 - valor2;
}

/**
 * @brief devuelve un numero aleatorio entre el limite inferior y el superior
 *
 * @param limiteInf limite inferior
 * @param limiteSup limite Superior
 * @return int
 */

int enteroAleatorioEntre(int limiteInf, int limiteSup)
{ // devuelve un numero aleatorio entre el limite inferior y el superior
    // srand(time(NULL));
    int valor = limiteInf + (rand() % (limiteSup - limiteInf));
    return valor;
}

/**
 * @brief devuelve un numero flotante aleatorio INT32_MAX es el limite maximo de los int de 32 bits
 *
 * @return float
 */
float flotanteAleatorio()
{ // devuelve un numero flotante aleatorio
    // INT32_MAX es el limite maximo de los int de 32 bits
    int numerador = enteroAleatorio(INT_MAX);                   // OPTIENE el numerador de forma aleatoria
    int denominador = 1 + enteroAleatorioEntre(1, INT_MAX - 1); // OPTIENE el denominador de forma aleatoria el valor no puede ser cero
    float flotante = numerador / denominador;

    return flotante;
}

/**
 * @brief  devuelve un caracter aleatorio
 *
 * @return char
 */
char caracterAleatorio()
{                                                       // devuelve un caracter aleatorio
    char caracter = enteroAleatorioEntre(40, 80) + '0'; // asigna el valor aleatorio la variable
    return caracter;
}

/**
 * @brief agrega varacteres aleatorios a la cadena
 *
 * @param cadena
 * @param longitud
 */
void cadenaAleatoria(char *cadena, int longitud)
{
    int i;
    for (i = 0; i < longitud - 1; i++)
    {
        cadena[i] = caracterAleatorio(); // asigna caracteres de forma aleatoria a la cadena
    }
    // cadena[longitud - 1] = '\n'; // asigna caracter de escape al ultimo caracter de la cadena
}

/**
 * @brief devuelve el apuntador a una cadena de longitud aleatoria (siempre liberar la memoria despues de usar el dato, ex: free(char*))
 *
 * @return char*
 */
char *cadenaAleatoriaLongAleatoria()
{ // devuelve el apuntador a una cadena de longitud aleatoria
    int longitud = enteroAleatorioEntre(0, CHAR_MAX);
    char *Cadena = (char *)malloc(longitud);
    cadenaAleatoria(Cadena, longitud);
    return Cadena;
}

/* Registros y Estructuras */

/**
 * @brief Crea un registro nuevo, lee sus valor y devuelve una copia
 *
 * Obs: Al editar la definicion de registro dependiendo de la necesidad del programa, se edebe editar esta funcion para poder usarla
 *
 * @return Registro
 */
Registro creaRegistro()
{ // crea un registro nuevo, lee sus valor y devuelve una copia

    printf("\n** Crea un Registro **\n");
    Registro *ptrNuevoRegistro = malloc(sizeof(Registro)); // libera espacio en memoria para el nuevo registro
    printf("Ingresa el valor a ser insertado en el Registro: ");
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
void borraRegistro(Registro *ptrRegistro)
{
    free(ptrRegistro); // libera espacio en memoria para el nuevo registro
}

void imprimeRegistro(Registro *ptrRegistro)
{
    printf("%d", ptrRegistro->valor);
}

/**
 * @brief Imprime una copia de un registro
 *
 * @param ptrRegistro
 */
void imprimeCopiaRegistro(Registro ptrRegistro)
{
    printf("%d", ptrRegistro.valor);
}

/* Listas Enlazadas */

/**
 * @brief Funciones de Manipulacion de Listas Enlazadas
 *
 * @author Dave Gomez
 */

/**
 * @brief Crea un nodo de una lista y devuelve su direccion en memoria
 *
 * @param dato Dato a ser insertado en el Nodo, dependiendo del tipo de nodo puede ser un Registro, entero, cadena, o cualquier tipo de dato
 * @return Nodo*
 *
 * @author Dave Gomez
 */

Nodo *creaNodo(Registro dato)
{
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo != NULL)
    {
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

/**
 * @brief Retorna -1 si la lista esta vacia, 0 en caso contrario
 *
 * @param ListaVal Lista a ser Evaluada
 * @return bool
 *
 * @author Dave Gomez
 */
bool listaEstaVacia(Lista ListaVal)
{
    if (ListaVal.cabeza == NULL && ListaVal.cola == NULL)
    { // si la cabeza y la cola son iguales a NULL
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Crea un nodo y lo inserta en la cabeza de la lista (tambien valido para pila)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}.
 * Obs: para una pila, si inserto desde la cabeza tambien debo leer desde la cabeza.
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarDatoEnCabeza(Registro dato, Lista *listaDestino)
{
    Nodo *ptrNuevoNodo = creaNodo(dato); // crea el nodo con el dato

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                              // si la lista no esta vacia
            ptrNuevoNodo->sig = listaDestino->cabeza;  // asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
            listaDestino->cabeza->ante = ptrNuevoNodo; // asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
            listaDestino->cabeza = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief Crea un nodo y lo inserta en cola de la lista (tabien valido para Colas)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarDatoEnCola(Registro dato, Lista *listaDestino)
{
    /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
    Nodo *ptrNuevoNodo = creaNodo(dato);

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                            // si la lista no esta vacia
            ptrNuevoNodo->ante = listaDestino->cola; // asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
            listaDestino->cola->sig = ptrNuevoNodo;  // asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
            listaDestino->cola = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief crea un registro y lo inserta en la cabeza de la lista
 *
 * @param ACargar
 */
void insertarEnCabeza(Lista *ACargar)
{
    int valor;
    Registro RegistroAInsertar = creaRegistro();
    insertarDatoEnCabeza(RegistroAInsertar, ACargar);
}

/**
 * @brief crea un registro y lo inserta en la cola de la lista
 *
 * @param ACargar
 */
void insertarEnCola(Lista *ACargar)
{
    int valor;
    Registro RegistroAInsertar = creaRegistro();
    insertarDatoEnCola(RegistroAInsertar, ACargar);
}

/**
 * @brief Extrae un el dato de la cabeza de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return Registro
 *
 * @author Dave Gomez
 */
Registro extraerCabeza(Lista *listaObjetivo)
{

    Registro Dato = {0}; // contenedor Auxiliar
    if (listaEstaVacia(*listaObjetivo))
    {

        Nodo *ptrNodoObjetivo;

        ptrNodoObjetivo = listaObjetivo->cabeza;

        Dato = ptrNodoObjetivo->dato;
        listaObjetivo->cabeza = ptrNodoObjetivo->sig;
        listaObjetivo->cabeza->ante = NULL; // asigna null al puntero anterior del nodo cabeza
        listaObjetivo->cantidadElem--;      // resta uno a la cantidad de elementos de la lista
        if (listaObjetivo->cantidadElem == 0)
            listaObjetivo->cola = NULL;

        free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    }
    else
        printf("\nLa lista esta vacia\n");

    return Dato; // retorna una copia del registro extraido
}

/**
 * @brief Extrae un el dato de la cola de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return Registro
 *
 * @author Dave Gomez
 */
Registro extraerCola(Lista *listaObjetivo)
{
    Nodo *ptrNodoObjetivo;
    Registro Dato;                         // contenedor Auxiliar
    ptrNodoObjetivo = listaObjetivo->cola; // direccion de memoria del nodo a extraer

    Dato = ptrNodoObjetivo->dato;                // asigna el dato de la cola al registro contenedor
    listaObjetivo->cola = ptrNodoObjetivo->ante; // asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida

    listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
    if (listaObjetivo->cantidadElem == 0)
        listaObjetivo->cabeza = NULL;
    else
        listaObjetivo->cola->sig = NULL; // elimina la direccion de memoria del apuntador siguiente de la cola actual

    free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    return Dato;
}

/**
 * @brief Imprime una lista desde la cabeza (tambien valido para una Cola)
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaCabeza(const Lista *listaObjetivo)
{
    printf("\nLa lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    Nodo *ptrNodoObjetivo = listaObjetivo->cabeza;
    while (ptrNodoObjetivo != NULL)
    {
        imprimeRegistro(&ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->sig;
    }
    printf("NULL\n");
}

/**
 * @brief imprime una lista desde la Cola (tambien valido para una Pila)
 * Obs: para una pila, si leo desde la cola es porque cargue los datos desde la cola
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaCola(const Lista *listaObjetivo)
{

    printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    Nodo *ptrNodoObjetivo = listaObjetivo->cola;
    while (ptrNodoObjetivo != NULL)
    {
        imprimeRegistro(&ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->ante;
    }
    printf("NULL\n");
}

/**
 * @brief Imprime El registro Recibido
 * Obs: como los registros pueden variar segun la necesidad se debe editar aqui los espeficicadores de conversion y los parametros a imprimir
 *
 * @param datos Registro a Imprimir
 *
 * @author Dave Gomez
 */

/**
 * @brief Retorna la direccion del primer nodo que contenga un dato mayor al valor recibido como parametro
 *
 * @param Dato Entero que sera comparado
 * @param listaDestino Lista en la que se buscara
 * @return Nodo*
 *
 * @author Dave Gomez
 */
Nodo *dirMayor(int Dato, Lista *listaDestino)
{
    Nodo *ptrNodoEvaluado = listaDestino->cabeza;
    while (ptrNodoEvaluado != NULL)
    {
        if (ptrNodoEvaluado->dato.valor > Dato)
        { // compara el valor
            return ptrNodoEvaluado;
        }
        else
            ptrNodoEvaluado = ptrNodoEvaluado->sig;
    }

    return NULL;
}

/**
 * @brief Inserta un dato recibido en la lista, detras del nodo especificado
 *
 * @param nodoMayor Direccion de memoria del Nodo del cual se insertara el dato Antes
 * @param dato Dato a ser insertado
 *
 * @author Dave Gomez
 */
void insertaDatoAntesDe(Nodo *nodoMayor, Registro dato)
{

    Nodo *ptrNuevoNodo = creaNodo(dato);

    ptrNuevoNodo->sig = nodoMayor;        // asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
    ptrNuevoNodo->ante = nodoMayor->ante; // asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
    nodoMayor->ante->sig = ptrNuevoNodo;
    nodoMayor->ante = ptrNuevoNodo;
}

/**
 * @brief Inserta un Nodo detras de otro especificado
 *
 * @param nodoMayor Direccion de memoria del Nodo del cual se insertara el dato Antes
 * @param dato Dato a ser insertado
 *
 * @author Dave Gomez
 */
void insertaNodoAntesDe(Nodo *nodoMayor, Nodo *ptrNuevoNodo)
{

    ptrNuevoNodo->sig = nodoMayor;        // asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
    ptrNuevoNodo->ante = nodoMayor->ante; // asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
    nodoMayor->ante->sig = ptrNuevoNodo;
    nodoMayor->ante = ptrNuevoNodo;
}

/**
 * @brief Inserta un Dato en una Lista dependidendo de Su orden
 *
 * @param dato
 * @param listaDestino
 *
 * @author Dave Gomez
 */
void insertaEnOrden(Registro dato, Lista *listaDestino)
{

    Nodo *ptrNuevoNodo = creaNodo(dato);
    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;
        if (listaEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {
            Nodo *ptrNodoMayor = dirMayor(dato.valor, listaDestino);
            if (ptrNodoMayor == listaDestino->cabeza)
            {
                insertarDatoEnCabeza(dato, listaDestino);
            }
            else
            {
                if (ptrNodoMayor != NULL)
                {
                    insertaNodoAntesDe(ptrNodoMayor, ptrNuevoNodo);
                }
                else
                {
                    insertarDatoEnCola(dato, listaDestino);
                }
            }
        }
    }
}

/**
 * @brief Despliga un menu con las poeraciones basicas con listas
 *
 * @author Dave Gomez
 */
void despliegaMenuListas()
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

// Listas enlazadas de Enteros
/**
 * @brief Crea un nodo de una lista y devuelve su direccion en memoria
 *
 * @param dato Dato a ser insertado en el Nodo, en esta caso int
 * @return NodoInt*
 *
 * @author Dave Gomez
 */

NodoInt *creaNodoInt(int dato)
{
    NodoInt *nuevoNodo = malloc(sizeof(NodoInt)); // liberamos espacio en memoria del tamanio de un nodo int
    if (nuevoNodo != NULL)
    {
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

/**
 * @brief Retorna -1 si la lista esta vacia, 0 en caso contrario
 *
 * @param ListaVal Lista a ser Evaluada
 * @return bool
 *
 * @author Dave Gomez
 */
bool listaIntEstaVacia(ListaInt ListaVal)
{
    if (ListaVal.cabeza == NULL && ListaVal.cola == NULL)
    { // si la cabeza y la cola son iguales a NULL
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Crea un nodo y lo inserta en la cabeza de la lista (tambien valido para pila)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}.
 * Obs: para una pila, si inserto desde la cabeza tambien debo leer desde la cabeza.
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarIntEnCabeza(int dato, ListaInt *listaDestino)
{
    NodoInt *ptrNuevoNodo = creaNodoInt(dato); // crea el nodo con el dato

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaIntEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                              // si la lista no esta vacia
            ptrNuevoNodo->sig = listaDestino->cabeza;  // asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
            listaDestino->cabeza->ante = ptrNuevoNodo; // asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
            listaDestino->cabeza = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief Crea un nodo y lo inserta en cola de la lista (tabien valido para Colas)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarIntEnCola(int dato, ListaInt *listaDestino)
{
    /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
    NodoInt *ptrNuevoNodo = creaNodoInt(dato);

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaIntEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                            // si la lista no esta vacia
            ptrNuevoNodo->ante = listaDestino->cola; // asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
            listaDestino->cola->sig = ptrNuevoNodo;  // asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
            listaDestino->cola = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief crea un registro y lo inserta en la cabeza de la lista
 *
 * @param ACargar
 */
void insertarEnCabezaListaInt(ListaInt *ACargar)
{
    int valor;
    printf("Ingrese el Valor entero a ser agregado a la Lista: ");
    scanf("%d", &valor);
    insertarIntEnCabeza(valor, ACargar);
}

/**
 * @brief crea un registro y lo inserta en la cola de la lista
 *
 * @param ACargar
 */
void insertarEnColaListaInt(ListaInt *ACargar)
{
    int valor;
    printf("Ingrese el Valor entero a ser agregado a la Lista: ");
    scanf("%d", &valor);
    insertarIntEnCola(valor, ACargar);
}

/**
 * @brief Extrae un el dato de la cabeza de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return int
 *
 * @author Dave Gomez
 */
int extraerCabezaListaInt(ListaInt *listaObjetivo)
{

    int contenedor = 0; // contenedor Auxiliar
    if (!listaIntEstaVacia(*listaObjetivo))
    {

        NodoInt *ptrNodoObjetivo;

        ptrNodoObjetivo = listaObjetivo->cabeza;
        contenedor = ptrNodoObjetivo->dato;
        if (ptrNodoObjetivo->sig != NULL)
        {
            ptrNodoObjetivo->sig->ante = NULL; // asigna null al puntero anterior del nodo cabeza
        }

        listaObjetivo->cabeza = ptrNodoObjetivo->sig;
        listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
        if (listaObjetivo->cantidadElem == 0)
            listaObjetivo->cola = NULL;

        free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    }
    else
        printf("\nLa lista esta vacia\n");

    return contenedor; // retorna una copia del registro extraido
}

/**
 * @brief Extrae un el dato de la cola de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return int
 *
 * @author Dave Gomez
 */
int extraerColaListaInt(ListaInt *listaObjetivo)
{
    NodoInt *ptrNodoObjetivo;
    int Dato = 0;                          // contenedor Auxiliar
    ptrNodoObjetivo = listaObjetivo->cola; // direccion de memoria del nodo a extraer

    Dato = ptrNodoObjetivo->dato;                // asigna el dato de la cola al registro contenedor
    listaObjetivo->cola = ptrNodoObjetivo->ante; // asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida

    listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
    if (listaObjetivo->cantidadElem == 0)
        listaObjetivo->cabeza = NULL;
    else
        listaObjetivo->cola->sig = NULL; // elimina la direccion de memoria del apuntador siguiente de la cola actual

    free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    return Dato;
}

/**
 * @brief Imprime una lista desde la cabeza (tambien valido para una Cola)
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaCabezaListaInt(const ListaInt *listaObjetivo)
{
    if (listaObjetivo->cabeza != NULL)
    {
        printf("\nLa lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
        NodoInt *ptrNodoObjetivo = listaObjetivo->cabeza;
        while (ptrNodoObjetivo != NULL)
        {
            printf("(%d)", ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
            printf(" -> ");
            ptrNodoObjetivo = ptrNodoObjetivo->sig;
        }
        printf("NULL\n");
    }
    else
    {
        printf("La lista esta vacia");
    }
}

/**
 * @brief imprime una lista desde la Cola (tambien valido para una Pila)
 * Obs: para una pila, si leo desde la cola es porque cargue los datos desde la cola
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaColaListaInt(const ListaInt *listaObjetivo)
{

    printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    NodoInt *ptrNodoObjetivo = listaObjetivo->cola;
    while (ptrNodoObjetivo != NULL)
    {
        printf("(%d)", ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->ante;
    }
    printf("NULL\n");
}

/**
 * @brief Retorna la direccion del primer nodo que contenga un dato mayor al valor recibido como parametro
 *
 * @param Dato Entero que sera comparado
 * @param listaDestino Lista en la que se buscara
 * @return Nodo*
 *
 * @author Dave Gomez
 */
NodoInt *dirMayorEnListaInt(int Dato, ListaInt *listaDestino)
{
    NodoInt *ptrNodoEvaluado = listaDestino->cabeza;
    while (ptrNodoEvaluado != NULL)
    {
        if (ptrNodoEvaluado->dato >= Dato)
        { // compara el valor
            return ptrNodoEvaluado;
        }
        else
            ptrNodoEvaluado = ptrNodoEvaluado->sig;
    }
    return NULL;
}

/**
 * @brief Retorna la direccion del primer nodo que contenga un dato igual al valor recibido como parametro
 *
 * @param Dato Entero que sera comparado
 * @param listaDestino Lista en la que se buscara
 * @return Nodo*
 *
 * @author Dave Gomez
 */
NodoInt *dirEnListaInt(int Dato, ListaInt *listaDestino)
{
    NodoInt *ptrNodoEvaluado = listaDestino->cabeza;
    while (ptrNodoEvaluado != NULL)
    {
        if (ptrNodoEvaluado->dato == Dato)
        { // compara el valor
            return ptrNodoEvaluado;
        }
        else
            ptrNodoEvaluado = ptrNodoEvaluado->sig;
    }
    return NULL;
}

/**
 * @brief Inserta un dato recibido en la lista, detras del nodo especificado
 *
 * @param nodoMayor Direccion de memoria del Nodo del cual se insertara el dato Antes
 * @param dato Dato a ser insertado
 *
 * @author Dave Gomez
 */
void insertaDatoAntesDeEnListaInt(NodoInt *nodoMayor, int dato)
{

    NodoInt *ptrNuevoNodo = creaNodoInt(dato);

    ptrNuevoNodo->sig = nodoMayor;        // asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
    ptrNuevoNodo->ante = nodoMayor->ante; // asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
    nodoMayor->ante->sig = ptrNuevoNodo;
    nodoMayor->ante = ptrNuevoNodo;
}

/**
 * @brief Inserta un Nodo detras de otro especificado
 *
 * @param nodoMayor Direccion de memoria del Nodo del cual se insertara el dato Antes
 * @param dato Dato a ser insertado
 *
 * @author Dave Gomez
 */
void insertaNodoAntesDeEnListaInt(NodoInt *nodoMayor, NodoInt *ptrNuevoNodo)
{
    ptrNuevoNodo->sig = nodoMayor;        // asigna la direccion del nodo mayor al puntero siguiente del nuevo nodo
    ptrNuevoNodo->ante = nodoMayor->ante; // asigna la direccion del del puntero anterior del nodo mayor a puntero anterior del nuevo nodo
    nodoMayor->ante->sig = ptrNuevoNodo;
    nodoMayor->ante = ptrNuevoNodo;
}

/**
 * @brief Inserta un Dato en una Lista dependidendo de Su orden
 *
 * @param dato
 * @param listaDestino
 *
 * @author Dave Gomez
 */
void insertaEnOrdenEnListaInt(int dato, ListaInt *listaDestino)
{

    NodoInt *ptrNuevoNodo = creaNodoInt(dato); // crea un nuevo nodoInt
    if (ptrNuevoNodo != NULL)                  // se creo el nuevo nodo
    {
        listaDestino->cantidadElem++;         // aumenta la cantidad de elementos en la lista
        if (listaIntEstaVacia(*listaDestino)) // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
        {
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {
            NodoInt *ptrNodoMayor = dirMayorEnListaInt(dato, listaDestino); // Ubica el nodo con valor mayor al valor a ser insertado
            if (ptrNodoMayor == listaDestino->cabeza)
            {
                insertarIntEnCabeza(dato, listaDestino);
            }
            else
            {
                if (ptrNodoMayor != NULL)
                {
                    insertaNodoAntesDeEnListaInt(ptrNodoMayor, ptrNuevoNodo);
                }
                else
                {
                    insertarIntEnCola(dato, listaDestino);
                }
            }
        }
    }
}

/**
 * @brief Despliga un menu con las poeraciones basicas con listas
 *
 * @author Dave Gomez
 */
void despliegaMenuListasInt()
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

/**
 * @brief Elimina el nodo del argumento nodo de la Lista int
 * Obs: Se debe asegurar que el nodo exista en la Lista
 * @param Nodo
 * @param Lista
 */
void eliminaNodoDeListaInt(NodoInt *Nodo, ListaInt *Lista)
{
    NodoInt *NodoAnter = INICIALIZAPUNTEROLISTAINT;
    NodoInt *NodoSiguiente = INICIALIZAPUNTEROLISTAINT;

    if (Lista->cabeza == Nodo)
    {
        extraerCabezaListaInt(Lista);
    }
    else
    {
        if (Lista->cola == Nodo)
        {
            extraerColaListaInt(Lista);
        }
        else
        {
            NodoAnter = Nodo->ante;
            NodoSiguiente = Nodo->sig;
            NodoAnter->sig = NodoSiguiente;
            NodoSiguiente->ante = NodoAnter;
            free(Nodo);
        }
    }
};

// Listas enlazadas de Caracteres
/**
 * @brief Crea un nodo de una lista y devuelve su direccion en memoria
 *
 * @param dato Dato a ser insertado en el Nodo, en esta caso int
 * @return NodoInt*
 *
 * @author Dave Gomez
 */

NodoChar *creaNodoChar(char dato)
{
    NodoChar *nuevoNodo = malloc(sizeof(NodoChar)); // liberamos espacio en memoria del espacio de un nodo de char
    if (nuevoNodo != NULL)
    {
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

/**
 * @brief Retorna true si la lista esta vacia, false en caso contrario
 *
 * @param ListaVal Lista a ser Evaluada
 * @return bool
 *
 * @author Dave Gomez
 */
bool listaCharEstaVacia(ListaChar ListaVal)
{
    if (ListaVal.cabeza == NULL && ListaVal.cola == NULL)
    { // si la cabeza y la cola son iguales a NULL
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Crea un nodo y lo inserta en la cabeza de la lista (tambien valido para pila)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}.
 * Obs: para una pila, si inserto desde la cabeza tambien debo leer desde la cabeza.
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarCharEnCabeza(char dato, ListaChar *listaDestino)
{
    NodoChar *ptrNuevoNodo = creaNodoChar(dato); // crea el nodo con el dato

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;
        if (listaCharEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                              // si la lista no esta vacia
            ptrNuevoNodo->sig = listaDestino->cabeza;  // asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
            listaDestino->cabeza->ante = ptrNuevoNodo; // asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
            listaDestino->cabeza = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief Crea un nodo y lo inserta en cola de la lista (tabien valido para Colas)
 * Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0}
 *
 * @param dato Dato a ser ingresado en la Cabeza de la Lista
 * @param listaDestino Lista en la que se insertara el nuevo nodo
 *
 * @author Dave Gomez
 */
void insertarCharEnCola(char dato, ListaChar *listaDestino)
{
    /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
    NodoChar *ptrNuevoNodo = creaNodoChar(dato);

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaCharEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                            // si la lista no esta vacia
            ptrNuevoNodo->ante = listaDestino->cola; // asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
            listaDestino->cola->sig = ptrNuevoNodo;  // asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
            listaDestino->cola = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief crea un registro y lo inserta en la cabeza de la lista
 *
 * @param ACargar
 */
void insertarEnCabezaListaChar(ListaChar *ACargar)
{
    char valor = ' ';
    printf("\nIngrese un caracter: ");
    fflush(stdin);
    valor = getchar();
    insertarCharEnCabeza(valor, ACargar);
}

/**
 * @brief crea un registro y lo inserta en la cola de la lista
 *
 * @param ACargar
 */
void insertarEnColaListaChar(ListaChar *ACargar)
{
    char valor = ' ';
    printf("\nIngrese un caracter: ");
    fflush(stdin);
    valor = getchar();
    insertarCharEnCola(valor, ACargar);
}

/**
 * @brief Extrae un el dato de la cabeza de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return char
 *
 * @author Dave Gomez
 */
int extraerCabezaListaChar(ListaChar *listaObjetivo)
{

    char contenedor = '\0'; // contenedor Auxiliar
    if (listaCharEstaVacia(*listaObjetivo))
    {

        NodoChar *ptrNodoObjetivo;

        ptrNodoObjetivo = listaObjetivo->cabeza;

        contenedor = ptrNodoObjetivo->dato; // guarda el dato de la cabeza
        listaObjetivo->cabeza = ptrNodoObjetivo->sig;
        listaObjetivo->cabeza->ante = NULL; // asigna null al puntero anterior del nodo cabeza
        listaObjetivo->cantidadElem--;      // resta uno a la cantidad de elementos de la lista
        if (listaObjetivo->cantidadElem == 0)
            listaObjetivo->cola = NULL;

        free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    }
    else
        printf("\nLa lista esta vacia\n");

    return contenedor; // retorna una copia del registro extraido
}

/**
 * @brief Extrae un el dato de la cola de la lista y lo retorna
 *
 * @param listaObjetivo Lista objetivo
 * @return char
 *
 * @author Dave Gomez
 */
int extraerColaListaChar(ListaChar *listaObjetivo)
{
    NodoChar *ptrNodoObjetivo;
    char Dato = '\0';                      // contenedor Auxiliar
    ptrNodoObjetivo = listaObjetivo->cola; // direccion de memoria del nodo a extraer

    Dato = ptrNodoObjetivo->dato;                // asigna el dato de la cola al registro contenedor
    listaObjetivo->cola = ptrNodoObjetivo->ante; // asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida

    listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
    if (listaObjetivo->cantidadElem == 0)
        listaObjetivo->cabeza = NULL;
    else
        listaObjetivo->cola->sig = NULL; // elimina la direccion de memoria del apuntador siguiente de la cola actual

    free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    return Dato;
}

/**
 * @brief Imprime una lista desde la cabeza (tambien valido para una Cola)
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaCabezaListaChar(const ListaChar *listaObjetivo)
{
    printf("\nLa lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    NodoChar *ptrNodoObjetivo = listaObjetivo->cabeza;
    while (ptrNodoObjetivo != NULL)
    {
        printf("(%c)", ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->sig;
    }
    printf("NULL\n");
}

/**
 * @brief imprime una lista desde la Cola (tambien valido para una Pila)
 * Obs: para una pila, si leo desde la cola es porque cargue los datos desde la cola
 *
 * @param listaObjetivo Lista a ser impresa
 *
 * @author Dave Gomez
 */
void imprimeDesdeLaColaListaChar(const ListaChar *listaObjetivo)
{

    printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    NodoChar *ptrNodoObjetivo = listaObjetivo->cola;
    while (ptrNodoObjetivo != NULL)
    {
        printf("(%c)", ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->ante;
    }
    printf("NULL\n");
}

// listas de string
/**
 * @brief Crea un nodo a cadena en base a la cadena suministrada
 * @param string
 * @return *NodoString
 *
 * @author David Gomez
 */

NodoString *creaNodoString(char *string)
{
    NodoString *nuevoNodo = malloc(sizeof(NodoString)); // liberamos espacio en memoria del tamanio de un nodo int
    if (nuevoNodo != NULL)
    {
        nuevoNodo->dato = malloc(sizeof(string));
        strcpy(nuevoNodo->dato, string);
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

/**
 * @brief verifica si una lista de string esta vacia
 * @param ListaVal
 * @return boolean
 *
 * @author David Gomez
 *
 */
bool listaStringEstaVacia(ListaString ListaVal)
{
    if (ListaVal.cabeza == NULL && ListaVal.cola == NULL)
    { // si la cabeza y la cola son iguales a NULL
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Inserta una cadena en la lista desde la cabeza
 * @param dato
 * @param listaDestino
 *
 * @author David Gomez
 *
 */
void insertarStringEnCabeza(char dato[], ListaString *listaDestino)
{
    NodoString *ptrNuevoNodo = creaNodoString(dato); // crea el nodo con el dato

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;
        if (listaStringEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                              // si la lista no esta vacia
            ptrNuevoNodo->sig = listaDestino->cabeza;  // asigna a al puntero siguiente del nuevo nodo la direccion de la cabeza de la lista
            listaDestino->cabeza->ante = ptrNuevoNodo; // asigna al puntero anterior de la cabeza de la lista la direccion del nuevo nodo
            listaDestino->cabeza = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief Inserta una cadena en la lista desde la cola
 * @param dato
 * @param listaDestino
 *
 * @author David Gomez
 */
void insertarStringEnCola(char dato[], ListaString *listaDestino)
{
    /* Obs: la lista ya debe esta inicializada Lista = {NULL, NULL, 0} */
    NodoString *ptrNuevoNodo = creaNodoString(dato);

    if (ptrNuevoNodo != NULL)
    {
        listaDestino->cantidadElem++;

        if (listaStringEstaVacia(*listaDestino))
        { // si la lista esta vacia asigna la direccion del nuevo nodo a la cabeza y la cola
            listaDestino->cabeza = listaDestino->cola = ptrNuevoNodo;
        }
        else
        {                                            // si la lista no esta vacia
            ptrNuevoNodo->ante = listaDestino->cola; // asigna a al puntero anterior del nuevo nodo la direccion de la cola de la lista
            listaDestino->cola->sig = ptrNuevoNodo;  // asigna al puntero siguiente de la cola de la lista la direccion del nuevo nodo
            listaDestino->cola = ptrNuevoNodo;       // asigna al almacenador de la direccion de la cola de la lista la direccion del nuevo nodo
        }
    }
}

/**
 * @brief inserta un nuevo string en la caabeza de la lista
 * @param ACargar
 * @author David Gomez
 */
void insertarEnCabezaListaString(ListaString *ACargar)
{
    char valor[100];
    printf("Ingrese un texto de entre 0 y 100 caracteres: ");
    leeConEspacios(valor);
    insertarStringEnCabeza(valor, ACargar);
}
/**
 * @brief inserta un nuevo string en la cola de la lista
 * @param ACargar
 * @author David Gomez
 */
void insertarEnColaListaString(ListaString *ACargar)
{
    char valor[100];
    printf("Ingrese un texto de entre 0 y 100 caracteres: ");
    leeConEspacios(valor);
    insertarStringEnCola(valor, ACargar);
}
/**
 * @brief Imprime una lista de Strings desde la cabeza
 * @param listaObjetivo
 */
void imprimeDesdeLaCabezaListaString(const ListaString *listaObjetivo)
{
    if (listaObjetivo->cabeza != NULL)
    {
        printf("\nLa lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
        NodoString *ptrNodoObjetivo = listaObjetivo->cabeza;
        while (ptrNodoObjetivo != NULL)
        {
            printf("(%s)", ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
            printf(" -> ");
            ptrNodoObjetivo = ptrNodoObjetivo->sig;
        }
        printf("NULL\n");
    }
    else
    {
        printf("La lista esta vacia");
    }
}

/**
 * @brief Imprime una lista de Strings desde la cola
 * @param listaObjetivo
 */
void imprimeDesdeLaColaListaString(const ListaString *listaObjetivo)
{
    printf("La lista cuenta con %d Elementos.\n", listaObjetivo->cantidadElem);
    NodoString *ptrNodoObjetivo = listaObjetivo->cola;
    while (ptrNodoObjetivo != NULL)
    {
        printf("(%s)", ptrNodoObjetivo->dato); // imprimie el registro asociado al nodo
        printf(" -> ");
        ptrNodoObjetivo = ptrNodoObjetivo->ante;
    }
    printf("NULL\n");
}

/**
 * @brief Extrea el dato de la cabeza de la lista string
 * @param listaObjetivo
 * @return
 */
char *extraerCabezaListaString(ListaString *listaObjetivo)
{

    char *contenedor = malloc(sizeof(char *)); // contenedor Auxiliar
    if (!listaStringEstaVacia(*listaObjetivo))
    {
        NodoString *ptrNodoObjetivo;

        ptrNodoObjetivo = listaObjetivo->cabeza;
        contenedor = ptrNodoObjetivo->dato;
        if (ptrNodoObjetivo->sig != NULL)
        {
            ptrNodoObjetivo->sig->ante = NULL; // asigna null al puntero anterior del nodo cabeza
        }

        listaObjetivo->cabeza = ptrNodoObjetivo->sig;
        listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
        if (listaObjetivo->cantidadElem == 0)
            listaObjetivo->cola = NULL;

        free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    }
    else
        printf("\nLa lista esta vacia\n");

    return contenedor; // retorna una copia del registro extraido
}

/**
 * @brief Extrae el ultimo elemento de la cola de la lista String
 * @param listaObjetivo
 * @return char*
 */
char *extraerColaListaString(ListaString *listaObjetivo)
{
    NodoString *ptrNodoObjetivo;
    char *contenedor = malloc(sizeof(char *)); // contenedor Auxiliar
    if (!listaStringEstaVacia(*listaObjetivo))
    {
        ptrNodoObjetivo = listaObjetivo->cola; // direccion de memoria del nodo a extraer

        contenedor = ptrNodoObjetivo->dato;          // asigna el dato de la cola al registro contenedor
        listaObjetivo->cola = ptrNodoObjetivo->ante; // asigna a la cola de la lista la direccion de memoria del nodo anterior a la cola extraida

        listaObjetivo->cantidadElem--; // resta uno a la cantidad de elementos de la lista
        if (listaObjetivo->cantidadElem == 0)
            listaObjetivo->cabeza = NULL;
        else
            listaObjetivo->cola->sig = NULL; // elimina la direccion de memoria del apuntador siguiente de la cola actual

        free(ptrNodoObjetivo); // libera el espacio en memoria ocupado por el nodo extraido
    }
    else
        printf("\nLa lista esta vacia\n");

    return contenedor;
}
/* Funciones de colas de prioridad */

/**
 * @brief Crea una cola de prioridad
 *
 * @param cantidadDePrioridades
 * @return ColaDePrioridad
 */
ColaDePrioridad CreaColaPrioridad(int cantidadDePrioridades)
{
    ColaDePrioridad NuevaCola; // Cola A ser retornada

    int i;                                      // iterador
    for (i = 0; i < cantidadDePrioridades; i++) // Inicializa las colas del Array Prioridades a colas Vacias
    {
        NuevaCola.Prioridades[i].cabeza = NULL;
        NuevaCola.Prioridades[i].cola = NULL;
        NuevaCola.Prioridades[i].cantidadElem = 0;
    }

    NuevaCola.CantPrioridades = cantidadDePrioridades; // Indica cuantas prioridades hay en la Cola
    return NuevaCola;
}

/**
 * @brief Inserta un registro en una cola de prioridad
 *
 * @param ColaPrioridad
 * @param AInsertar
 */
void insertarEnPrioridad(ColaDePrioridad *ColaPrioridad, RegistroDePrioridad *AInsertar)
{
    if (AInsertar->prioridad < ColaPrioridad->CantPrioridades && AInsertar->prioridad >= 0)
    {
        insertarDatoEnCola(AInsertar->nodo->dato, &ColaPrioridad->Prioridades[AInsertar->prioridad]);
    }
    else
    {
        printf("Error! Prioridad fuera de Rango");
    }
}

/**
 * @brief  inserta en una una cola de prioridad
 *
 * @param colaDePrioridad
 */
void insertarDatosEnColaDePriridad(ColaDePrioridad *colaDePrioridad)
{

    int P;

    RegistroDePrioridad *DatosDePrioridad = malloc(sizeof(RegistroDePrioridad));
    DatosDePrioridad->nodo = creaNodo(creaRegistro());
    printf("Prioridad:");
    scanf("%d", &P);
    DatosDePrioridad->prioridad = P - 1;

    insertarEnPrioridad(colaDePrioridad, DatosDePrioridad);
}

/**
 * @brief Lee un dato de la cola de prioridad
 *
 * @param colaDePrioridad
 */
void leerColaDePrioridades(ColaDePrioridad *colaDePrioridad)
{
    if (ColaPrioridadVacia(*colaDePrioridad) != -1)
    {
        Registro aux = DesencolaPrioridad(colaDePrioridad);
        printf("El Prime Dato era: %d", aux.valor); // aqui deban inr las operaciones requeridas para hacer con el dato de la cola de prioridad
    }
    else
    {
        printf("Error: La cola de priridad Esta Vacia\n");
    }
}

/**
 * @brief Imprime el estado actual de la cola de prioridad
 *
 * @param colaDePrioridad
 */
void imprimirColaDePrioridad(ColaDePrioridad colaDePrioridad)
{
    int i; // iterador
    printf("\nCola De prioridad de %d Prioridades\n", colaDePrioridad.CantPrioridades);
    for (i = 0; i < colaDePrioridad.CantPrioridades; i++)
    {
        printf("\nPrioridad %d\n", i + 1);
        imprimeDesdeLaCabeza(&colaDePrioridad.Prioridades[i]);
    }
}
/**
 * @brief Retorna -1 si la lista esta vacia, 0 en caso contrario
 *
 * @param ListaVal
 * @return int
 */
int ColaPrioridadVacia(ColaDePrioridad ListaVal)
{                     // retorna -1 si la lista esta vacia, 0 en caso contrario
    int i;            // iterador
    int bandera = -1; // su valor determina si esta o no vacia: -1 para vacia, 0 para no vacia
    for (i = 0; i < ListaVal.CantPrioridades; i++)
    {
        if (ListaVal.Prioridades[i].cabeza != NULL)
        {
            bandera = 0;
            break; // basta con que una de las colas no este vacia para que la cola de prioridades no este vacia
        }
    }

    return bandera;
}

/**
 * @brief Saca un dato de la cola de prioridad
 *
 * @param ColaDePrio
 * @return Registro
 */
Registro DesencolaPrioridad(ColaDePrioridad *ColaDePrio)
{
    // esta funcion no es aplicable a colas de prioridades vacias

    int i = 0;
    Registro dato; // contenedor auxiliar a ser retornado
    for (i = 0; i < ColaDePrio->CantPrioridades; i++)
    {
        if (listaEstaVacia(ColaDePrio->Prioridades[i]))
            continue;

        dato = extraerCabeza(&ColaDePrio->Prioridades[i]);
        break; // extrae solamente el primer elemento de la primera cola no vacia que encuentra
    }

    return dato;
}

/**
 * @brief Despliega un menu de operaciones de la cola de prioridad
 *
 */
void despliegaMenuColasDePrioridad()
{
    printf("\n");
    printf("Que desea Hacer?\n");
    printf("Opciones:\n");
    printf("1 - Insertar en la Cola de prioridades\n");
    printf("2 - Leer Dato desde la Cola de prioridades\n");
    printf("3 - Imprimir la Cola de prioridades\n");
    printf("4 - Salir\n");
    printf("Su Opcion = ");
}

/**
 * @brief Funciones de archivos
 *
 */

/**
 * @brief crea un arichivo y devuelve su apuntador
 *
 * @return *Archivo
 */
Archivo *creaArchivo()
{

    char nombreArchivo[150] = "";
    char modo[5] = "";
    Archivo *ptrNuevoArchivo = malloc(sizeof(Archivo)); // inicializa el puntero al archivo en null
    ptrNuevoArchivo->punteroArchivo = NULL;

    printf("\nIngrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
    scanf("%s", nombreArchivo); // ingresa el nombre y formato del archivo
    printf("\nIngrese el codigo del Modo de apertura del archivo: ");
    scanf("%s", modo); // ingresa el formato de apertura del archivo
    if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, modo)) == NULL)
    {
        printf("No se pudo crear el archivo.\nERROR\n"); // retorna null si no se pudo abrir el archivo
    }
    else
    {
        ptrNuevoArchivo->cantidadElementos = 0; // establece en cero la cantidad de elementos
        ptrNuevoArchivo->registros = 0;         // establece la cantidad de registtros hab en cero
        // optenerCantidadElementos(ptrNuevoArchivo);
    }
    return ptrNuevoArchivo; // retorna el puntero al archivo si hubo exito
}

/**
 * @brief cierra el archivo que recibe y elimina
 *
 */
void cierraArchivo(Archivo *ArchivoObjetivo)
{
    fclose(ArchivoObjetivo->punteroArchivo);
    free(ArchivoObjetivo);
}

/**
 * @brief //crea un arichivo binario y devuelce su apuntador
 *
 * @return FILE*
 */
Archivo *creaArchivoBin()
{

    char nombreArchivo[150] = "";
    char modo[5] = "";
    Archivo *ptrNuevoArchivo = malloc(sizeof(Archivo)); // inicializa el puntero al archivo en null

    printf("Ingrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
    scanf("%s", nombreArchivo); // ingresa el nombre y formato del archivo
    printf("\nIngrese el codigo del Modo de apertura del archivo: ");
    scanf("%s", modo); // ingresa el formato de apertura del archivo
    if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, modo)) == NULL)
    {
        if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, "wb+")) != NULL)
        {
            ptrNuevoArchivo->cantidadElementos = 0;
            return ptrNuevoArchivo; // retorna el puntero al archivo si hubo exito
        }
        else
        {
            printf("No se pudo Abir Ni crear el archivo");
            return NULL;
        }
    }
    else
    {
        if (strcmp("w", modo) == 0)
        {
            fclose(ptrNuevoArchivo->punteroArchivo);
            ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, "rb+");
            ptrNuevoArchivo->cantidadElementos = 0;
            return ptrNuevoArchivo;
        }
        else
            ptrNuevoArchivo->cantidadElementos = 0;
        return ptrNuevoArchivo; // retorna el puntero al archivo si hubo exito
    }
}

/**
 * @brief Recibe el apuntador a un registro y lo guarda en el archivo
 *
 * @param ptrArchivo Puntero a estructura de Tipo Archivo
 * @param aGuardar Registro a ser guardado en el archivo
 */
void guardaRegistroEnArchivo(Archivo *ptrArchivo, RegistroArchivo *aGuardar)
{

    fseek(ptrArchivo->punteroArchivo, (aGuardar->id - 1) * sizeof(RegistroArchivo), SEEK_SET); // establece el apuntador a la posicion del numero de cuenta del nuevo Registro
    fwrite(aGuardar, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);                  // escribe el contenido del registro nuevo en la direccion especificada
    rewind(ptrArchivo->punteroArchivo);
}

/**
 * @brief Crea un nuevo registro y lo inserta en el archivo
 *
 * @param ptrArchivo Puntero al archivo destino
 */
void nuevoRegistro(Archivo *ptrArchivo)
{

    RegistroArchivo nuevoRegistro = {ptrArchivo->cantidadElementos + 1, 1, {0}}, auxRegistro = {0, 0, {0}};

    nuevoRegistro.Dato = creaRegistro(); // crea un nuevo registro
    nuevoRegistro.estaEliminado = 1;
    printf("id Asignado: %d\n", ptrArchivo->cantidadElementos + 1);
    fseek(ptrArchivo->punteroArchivo, (ptrArchivo->cantidadElementos) * sizeof(RegistroArchivo), SEEK_SET); // establece el apuntador a la posicion del numero de cuenta del nuevo Registro
    fread(&auxRegistro, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);                            // almacena la lectura del puntero del archivo al registro auxiliar

    if (auxRegistro.id != 0)
    { // si la cuenta del reigistro ya existe, o si existe y no esta esliminado
        printf("\nERROR: La cuenta %d Ya existe\n", auxRegistro.id);
    }
    else
    { // sino, guarda el nuevo registro en esa direccion
        printf("Estatus registo: %s \n",
               (nuevoRegistro.estaEliminado == 0 || nuevoRegistro.estaEliminado == -1) ? "Vacio\n" : "Contiene Datos\n");
        imprimeRegistro(&nuevoRegistro.Dato);
        guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistro);
        ptrArchivo->cantidadElementos++;
        printf("\nRegistro Agregado Exitosamente!\n\n");
    }
}

/**
 * @brief Establece en blanco un registro en el archivo (Eliminacion Fisica)
 *
 * @param ptrArchivo Puntero a Estructura de Tipo archivo de la cual se eliminara un
 */
void eliminaRegistro(Archivo *ptrArchivo)
{

    RegistroArchivo registroAux = {0, 0, {0}};

    int id;
    printf("Introduzca el id a Eliminar: ");
    scanf("%d", &id);

    fseek(ptrArchivo->punteroArchivo, (id - 1) * sizeof(RegistroArchivo), SEEK_SET); // situa el apuntador a la direccion del registro a eliminar
    fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);     // lee el registro
    printf("Registro: {id: %d, estuatus: %s, valor: %d, dirMem: %p }\n", registroAux.id, registroAux.estaEliminado == 1 ? "Contiene Datos" : "Esta Vacio", registroAux.Dato.valor, ptrArchivo->punteroArchivo);

    if (registroAux.estaEliminado == -1 || registroAux.id == 0 || registroAux.estaEliminado == 0) // verifica si el archivo ya esta vacio de antemano
    {
        printf("El registro %d no existe", id);
    }
    else // edita el archivo
    {
        registroAux.estaEliminado = -1;
        guardaRegistroEnArchivo(ptrArchivo, &registroAux); // guarda un registro en blanco en la id especificada
        // ptrArchivo->cantidadElementos--;

        ptrArchivo->registros--;
        printf("\n\tRegistro Eliminado Exitosamente\n"); // mensaje de exito
    }
}

/**
 * @brief Inicializar los valores a editar del
 *
 * @param ptrArchivo
 */
void actualizaRegistro(Archivo *ptrArchivo)
{

    RegistroArchivo registroAux = {0, 0, {0}};
    int id;
    Registro NuevosDatos;

    printf("\nIntroduzca id del registro a actualizar: "); // este debe ser un identificador para el registro del archivo.
    scanf("%d", &id);                                      // solicita el numero de cuenta a editar

    fseek(ptrArchivo->punteroArchivo, (id - 1) * sizeof(RegistroArchivo), SEEK_SET); // establece el apuntado al registro a editar
    fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);     // lee el registro a editar en el registro auxiliar

    if (registroAux.estaEliminado == 0)
    {
        printf("\nLa cuenta #%d no tiene informacion\n", registroAux.id);
    }
    else
    {
        printf("\nIntroduzaca los nuevos Valores para el registro de ID Nro %d \n", registroAux.id);
        NuevosDatos = creaRegistro();
        registroAux.Dato = NuevosDatos;
        guardaRegistroEnArchivo(ptrArchivo, &registroAux);
        printf("\nRegistro #%d actualizado Correctamente", registroAux.id);
    }
}

/**
 * @param ptrf*
 *
 */
Archivo *abreArchivoParaLectura()
{
    char nombreArchivo[150] = "";
    Archivo *ptrNuevoArchivo = malloc(sizeof(Archivo)); // inicializa el puntero al archivo en null
    ptrNuevoArchivo->punteroArchivo = NULL;

    printf("\nIngrese el Nombre Del Archivo SIN ESPACIOS y Su extension: ");
    scanf("%s", nombreArchivo); // ingresa el nombre y formato del archivo
    if ((ptrNuevoArchivo->punteroArchivo = fopen(nombreArchivo, "r")) == NULL)
    {
        printf("No se pudo abir el archivo\n"); // retorna null si no se pudo abrir el archivo
    }
    else
    {
        ptrNuevoArchivo->cantidadElementos = 0; // establece en cero la cantidad de elementos
        ptrNuevoArchivo->registros = 0;         // establece la cantidad de registtros hab en cero
    }
    return ptrNuevoArchivo;
}

/**
 * @brief Crea un archivo de texto con formato para impresión
 * Obs: la definicion del archivo depende de los requerimientos del programa.
 *
 *
 * @param ptrArchivo
 */
void informeTxt(Archivo *ptrArchivo)
{
    FILE *ptrInforme = malloc(sizeof(FILE *)); // apuntador al archivo Resultado
    RegistroArchivo datos = {0, 1, {0}};       // inicializar aqui el registro,
    if ((ptrInforme = fopen("Informe.txt", "w")) == NULL)
        printf("\n\tERROR: No se pudo crear el Archivo\n\n");
    else
    {
        rewind(ptrArchivo->punteroArchivo);                                                             // establece el puntero al principio del archivo
        fprintf(ptrInforme, "%s\t%s\t%s\t%s\t%s\n", "id.", "entero", "nombre", "flotante", "caracter"); // imprime la cabecera. Esto depende de los campos a imprimir del registro
        while (!feof(ptrArchivo->punteroArchivo))
        {
            datos.estaEliminado = 0;
            fread(&datos, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo); // lee los datos en el Registro datos
            if (datos.estaEliminado == 1)
            {

                fprintf(ptrInforme, "%d\n", datos.Dato.valor);
                // imprimir aqui en el formato que pida el ejercicio
            }
            else
            {
                printf("Registro Vacio\n"); // informa que no se pudo leer nada desde el archivo origen
            }
        }
        fclose(ptrInforme); // cierra el archivo de informe
        printf("\n\tInforme Generado exitosamente!\n\n");
    }
};

/**
 * @brief recibe un archivo
 *
 * @param *ListaInt
 * @param *Archivo
 */
void guardaListaIntEnArchivoNuevo(ListaInt *ListaOrigen, Archivo *ArchivoDestino)
{
    int iteraciones = ListaOrigen->cantidadElem;
    int i, valor;
    rewind(ArchivoDestino->punteroArchivo);
    for (i = 0; i < iteraciones; i++)
    {
        valor = extraerCabezaListaInt(ListaOrigen);
        fprintf(ArchivoDestino->punteroArchivo, "%d\n", valor);
        ArchivoDestino->cantidadElementos++;
    }
    rewind(ArchivoDestino->punteroArchivo);
}

/**
 * @brief crea un archivo llamado informe.txt y en el almacena todos los elementos de de la lista int
 *
 * @param ListaInt*
 */
void guardaListaIntEnArchivoInforme(ListaInt *ListaOrigen)
{
    FILE *ptrInforme = malloc(sizeof(FILE *)); // apuntador al archivo Resultadox

    int valor = 0, i, iteraciones = ListaOrigen->cantidadElem;
    printf("\nLa lista tiene %d elementos.", ListaOrigen->cantidadElem);
    if ((ptrInforme = fopen("Informe.txt", "w")) == NULL)
        printf("\n\tERROR: No se pudo crear el Archivo\n\n");
    else
    {
        for (i = 0; i < iteraciones; i++)
        {
            valor = extraerCabezaListaInt(ListaOrigen);
            fprintf(ptrInforme, "%d\n", valor);
        }
        // fprintf(ptrInforme, "%d\n", EOF);
        fclose(ptrInforme); // cierra el archivo de informe
        printf("\n\tInforme Generado exitosamente!\n\n");
    }
}

/**
 * @brief guarda el contenido de una lista en un archivo recibido
 *
 * @param ListaInt*
 * @param Archivo*
 */
void leeListaIntDeArchivoInforme(ListaInt *ListaDestino, Archivo *Archivo)
{
    int dato;
    if (Archivo->punteroArchivo != NULL)
    {
        while (!feof(Archivo->punteroArchivo))
        {
            fscanf(Archivo->punteroArchivo, "%d", &dato);
            insertarIntEnCola(dato, ListaDestino);
        }
    }
    cierraArchivo(Archivo);
}

/**
 * @brief recibe una Lista y guarda los registros en un archivo desde la cabeza de la lista
 *
 * @param ptrArchivo Puntero a estructura de archivo de destino
 * @param ListaDatos Lista a ser almacenada en el archivo
 */
void guardaDesdeCabezaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos)
{

    Nodo *ptrNodoObjetivo = ListaDatos.cabeza;
    RegistroArchivo nuevoRegistroArc = {0, 0, ptrNodoObjetivo->dato};
    while (ptrNodoObjetivo != NULL)
    {
        guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistroArc);
        ptrNodoObjetivo = ptrNodoObjetivo->sig;
    }
}

/**
 * @brief recibe una Lista y guarda los registros en un archivo desde la cola de la lista
 *
 * @param ptrArchivo Puntero a estructura de archivo de destino
 * @param ListaDatos Lista a ser almacenada en el archivo
 */
void guardaDesdeColaEnArchivo(Archivo *ptrArchivo, Lista ListaDatos)
{
    Nodo *ptrNodoObjetivo = ListaDatos.cola;
    RegistroArchivo nuevoRegistroArc = {0, 0, ptrNodoObjetivo->dato};
    while (ptrNodoObjetivo != NULL)
    {
        guardaRegistroEnArchivo(ptrArchivo, &nuevoRegistroArc);
        ptrNodoObjetivo = ptrNodoObjetivo->ante;
    }
}

/**
 * @brief Despliega un menu para operaciones con archivos
 *
 */
void menuArchivos()
{ // despliega el menu
    printf("Selecciones su opcion\n1- Informe EN archivo txt.\n2-AcualizarUnRegistro\n3-Agregar Un Registro.\n4- Eliminar un registro \n5-Salir Del Programa.\nOpcion=");
}

void optenerCantidadElementos(Archivo *ptrArchivo)
{
    RegistroArchivo registroAux = {0, 0, {0}};

    printf("Cantidad de registros hab: %d\n", ptrArchivo->registros);

    do
    {
        registroAux.estaEliminado = 0;
        fseek(ptrArchivo->punteroArchivo, (ptrArchivo->cantidadElementos) * sizeof(RegistroArchivo), SEEK_SET); //
        fread(&registroAux, sizeof(RegistroArchivo), 1, ptrArchivo->punteroArchivo);                            // almacena la lectura del puntero del archivo al registro auxiliar
        // printf("Registro id: %d\n Registro estatus %s\n", registroAux.id, registroAux.estaEliminado == 0 ? "Nunca escrito" : "Con datos");

        ptrArchivo->cantidadElementos++;

        if (registroAux.estaEliminado == 1)
            ptrArchivo->registros++; // cuenta la cantidad de registro no eliminados

    } while (registroAux.estaEliminado != 0);

    if (ptrArchivo->cantidadElementos != 0)
        ptrArchivo->cantidadElementos--;

    rewind(ptrArchivo->punteroArchivo);

    if (ptrArchivo->registros != 0 && ptrArchivo->cantidadElementos != 0)
        printf("\nEl archivo ya contiene Datos!\n");
    else
        printf("\nArchivo en blanco\n");

    printf("Cantidad de registros hab: %d\n", ptrArchivo->registros);
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

/**
 * @brief Funciones de Arboles Binarios y monticulos
 *
 */

/**
 * @brief Despliega el menu de operaciones basicas con arboles binarios
 *
 */
void despliegaMenuArboles()
{
    printf("Que desea Hacer?\n");
    printf("Opciones:\n");
    printf("1 - Insertar Nodo En arbol\n");
    printf("2 - Imprimir Arbol\n");
    printf("3 - Salir\n");
    printf("Su Opcion = ");
}

/**
 * @brief Carga un valor entero en un arbol
 *
 * @param ArbolObjetivo
 * @param valor
 */
void cargaArbol(Arbol *ArbolObjetivo, int valor)
{
    NodoArbol *ptrNuevoNodo = creaNodoArbol(valor);
    insertaNodoEnArbol(&ArbolObjetivo->Raiz, ptrNuevoNodo);
}

/**
 * @brief Crea un nuevo nodo de arbol y retorna su direccion de memoria
 *
 * @param dato
 * @return NodoArbol*
 */
NodoArbol *creaNodoArbol(int dato)
{
    NodoArbol *nuevoNodo = malloc(sizeof(NodoArbol)); // libera espacio en memora para el nuevo nodo
    if (nuevoNodo != NULL)
    {
        nuevoNodo->dato = dato;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        return nuevoNodo;
    }
    else
    {
        printf("No de pudo crear el Nuevo Nodo, Memoria insuficiente");
        return NULL;
    }
}

/**
 * @brief Inserta un Nodo nuevo en un Arbol
 *
 * @param SubArbol
 * @param ptrNuvoNodo
 */
void insertaNodoEnArbol(NodoArbol **SubArbol, NodoArbol *ptrNuvoNodo)
{
    if (*SubArbol == NULL) // si el arbol esta vacio
    {
        *SubArbol = ptrNuvoNodo;
    }
    else // si no esta vacio
    {
        if ((*SubArbol)->dato > ptrNuvoNodo->dato)
            insertaNodoEnArbol(&(*SubArbol)->izq, ptrNuvoNodo);

        if ((*SubArbol)->dato < ptrNuvoNodo->dato)
            insertaNodoEnArbol(&(*SubArbol)->der, ptrNuvoNodo);
    }
}

/**
 * @brief Imprime un Arbol binario en orden
 *
 * @param ptrNodoArbol
 */
void inOrden(NodoArbol *ptrNodoArbol)
{
    if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
    {
        inOrden(ptrNodoArbol->izq);
        printf(" %d -", ptrNodoArbol->dato);
        inOrden(ptrNodoArbol->der);
    }
}

/**
 * @brief Imprime un arbol binario en preOrden
 *
 * @param ptrNodoArbol
 */
void preOrden(NodoArbol *ptrNodoArbol)
{
    if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
    {
        printf(" %d -", ptrNodoArbol->dato);
        preOrden(ptrNodoArbol->izq);
        preOrden(ptrNodoArbol->der);
    }
}

/**
 * @brief imprime un arbol en PostOrden
 *
 * @param ptrNodoArbol
 */
void postOrden(NodoArbol *ptrNodoArbol)
{
    if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
    {
        postOrden(ptrNodoArbol->der);
        printf(" %d -", ptrNodoArbol->dato);
        postOrden(ptrNodoArbol->izq);
    }
}

/**
 * @brief Funcion Imprimir arbol, desplega las opciones posibles para imprimmir el arbol
 *
 * @param aImprimir
 */
void imprimirArbol(Arbol *aImprimir)
{
    int opcion;
    if (aImprimir->Raiz == NULL)
    {
        printf("Arbol Vacio!\n");
    }
    else
    {
        printf("Como desea Visualizar el Arbol\n");
        printf("Ingrese su Opcion\n");
        printf("1- InOrden\n");
        printf("2- preOrden\n");
        printf("3- posOrden\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            inOrden(aImprimir->Raiz);
            break;
        case 2:
            preOrden(aImprimir->Raiz);
            break;
        case 3:
            postOrden(aImprimir->Raiz);
            break;
        default:
            printf("Opcion Invalida");
            break;
        }
    }
}

/**
 * @brief Inserta un Nodo en el arbol (acepta datos duplicado)
 *
 * @param SubArbol
 * @param ptrNuvoNodo
 */
void insertaNodoEnArbolConRep(NodoArbol **SubArbol, NodoArbol *ptrNuvoNodo)
{
    if (*SubArbol == NULL) // si el arbol esta vacio
    {
        *SubArbol = ptrNuvoNodo;
    }
    else // si no esta vacio
    {
        if ((*SubArbol)->dato > ptrNuvoNodo->dato)
            insertaNodoEnArbolConRep(&(*SubArbol)->izq, ptrNuvoNodo);

        if ((*SubArbol)->dato <= ptrNuvoNodo->dato)
            insertaNodoEnArbolConRep(&(*SubArbol)->der, ptrNuvoNodo);
    }
}

/**
 * @brief Carga un array en un arbol binario
 *
 * @param ArbolObjetivo
 * @param array
 * @param longitud
 */
void cargaArregloEnArbol(Arbol *ArbolObjetivo, int array[], int longitud)
{
    int i;
    for (i = 0; i < longitud; i++)
    {
        insertaNodoEnArbolConRep(&ArbolObjetivo->Raiz, creaNodoArbol(array[i]));
    }
}

/**
 * @brief Carga los datos del arbol en orden en un arreglo
 *
 * @param ptrNodoArbol
 * @param arreglo
 * @param dirIteradorDelArray direccin de memoria del iterador
 */
void inOrdenArray(NodoArbol *ptrNodoArbol, int arreglo[], int dimension)
{
    int bandera = 0;
    static int iterador = 0;
    if (ptrNodoArbol != NULL) // Si el NodoArbol (que es un subarbol) No esta vacio
    {
        inOrdenArray(ptrNodoArbol->izq, arreglo, dimension);
        arreglo[iterador] = ptrNodoArbol->dato;
        iterador = iterador + 1;
        inOrdenArray(ptrNodoArbol->der, arreglo, dimension);
    }
    if (iterador == dimension)
    {
        iterador = 0;
    }
}

// pruebas con listas
/**
 * @brief Crea una lista de longitud aleatoria y con valores aleatorios en los registros
 *
 * @return *ListaInt
 */
ListaInt *creaListaIntAleatoria()
{
    int i;
    ListaInt *Lista = malloc(sizeof(ListaInt));
    int cantidadElementos = enteroAleatorioEntre(1, 2000); // por ahora dejo asi, en el momento de guardar cosas en archivos usare el que puede generar miles de numeros

    NodoInt *nodoAux;
    printf("Cantidad de elementos: %d", cantidadElementos);
    for (i = 0; i < cantidadElementos; i++)
    {
        insertarIntEnCola(enteroAleatorio(100), Lista);
    }
    return (Lista);
}

// pruebas con listas
/**
 * @brief Crea una lista de longitud aleatoria y con valores aleatorios en los registros
 *
 * @param int cantElem cantidad de elementos de la lista
 * @return *ListaInt
 */
ListaInt *creaListaInt(int cantElem)
{
    int i;
    ListaInt *Lista = malloc(sizeof(ListaInt));
    for (i = 0; i < cantElem; i++)
    {
        insertarIntEnCola(enteroAleatorio(100), Lista);
    }
    return (Lista);
}

/**
 * funciones de lab
 *

 */

/**
 * @brief Resta errada
 *
 * @param n
 * @return int
 */
int resta_errad(int n)
{
    int res;
    int ult = n % 10;
    if (ult == 0)
    {
        res = n / 10;
    }
    else
    {
        res = n - 1;
    }

    return res;
}

/* devuelve uno cero si todos los digitos del anio son diferentes
caso contrario devuelce -1*/
/* funciona para anios de 4 dijitos pero se puede mejorar */
bool isBeautifullYear(int anio)
{
    int unid, dec, cent, uni_mil;
    bool ret = true;

    unid = anio % 10;
    dec = ((anio % 100) - unid) / 10;
    cent = ((anio % 1000) - dec * 10 - unid) / 100;
    uni_mil = ((anio % 10000) - cent * 100 - dec * 10 - unid) / 1000;

    if (unid == dec)
        ret = false;

    if (unid == cent)
        ret = false;

    if (unid == uni_mil)
        ret = false;

    if (cent == dec)
        ret = false;

    if (uni_mil == dec)
        ret = false;

    if (uni_mil == cent)
        ret = false;

    return ret;
}

/**
 * @brief calcula pasos
 *
 * @param dist
 * @return int
 */
int calc_pasos(int dist)
{
    int pos = 0, pasos = 0, x = dist;
    while (pos != x)
    {
        if (pos + 5 <= x)
        {
            pasos++;
            pos += 5;
            break;
        }
        if (pos + 4 <= x)
        {
            pasos++;
            pos += 4;
            break;
        }
        if (pos + 3 <= x)
        {
            pasos++;
            pos += 3;
            break;
        }
        if (pos + 2 <= x)
        {
            pasos++;
            pos += 2;
            break;
        }
        if (pos + 1 <= x)
        {
            pasos++;
            pos += 1;
            break;
        }
    }

    return pasos;
}

/**
 * @brief devuelve la minnima cantidad de pasos necesarios para subir la cima de una escalera teniendo en cuenta que se pueden tomar pasos de 1 o 2 escalonnes a la vez
 *
 * @param n
 * @return int
 */
int sube_escalera(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return sube_escalera(n - 1) + sube_escalera(n - 2);
}

/**
 * @brief imprime el camino que recorrio una en una matriz
 *
 * @param fila
 * @param col
 * @param a
 */
void imprimeCamino(int fila, int col, int a[][col])
{
    int i, j, elem;
    for (elem = 1; elem <= fila * col + 1; elem++)
    {
        for (i = 0; i < fila; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (a[i][j] == elem)
                {
                    printf("%c%d ", getLetra(i + 1), j);
                }
            }
        }
    }
}

/**
 * @brief verifica si el valor actual y el pasado suman una cantidad dada
 *
 * @param arreglo1
 * @param dim
 * @param dias
 * @return int
 */
int agendador(int arreglo1[], int dim, int dias)
{

    int persecutor = 0, adelantado, contador = 0;
    for (adelantado = 1; adelantado < dim; adelantado++)
    {
        while (arreglo1[adelantado] + arreglo1[persecutor] < dias)
        {
            arreglo1[adelantado]++;
            contador++;
        }
        persecutor++;
    }

    return contador;
}

void aniadeUno()
{
    int pruebas, i, j, s, cont;
    char nuemero[6];
    char acum[15] = "";
    char aux[15] = "";
    int nuevos[6] = {0};
    scanf("%d", &pruebas);
    int result[pruebas];
    char auxcad[2] = "";

    for (i = 0; i < pruebas; i++)
    {
        scanf("%s", nuemero);

        for (j = 0; j < strlen(nuemero); j++)
        {
            strcat(auxcad, &nuemero[j]);
            cont = atoi(auxcad);
            // itoa(aux, cont + 1, 10);
            strcat(acum, aux);
            // auxcad[0] = '';
        }
        result[i] = atoi(acum);

        for (s = 0; s < 15; s++)
        {
            // acum[s] = '';
        }
    }

    for (i = 0; i < pruebas; i++)
    {
        printf("%d", result[i]);
    }
}

// lab 5
/**
 * @brief Recibe un arreglo, un string y su dimension y copia los valores del arrego en el string
 *
 * @param origen
 * @param destino
 * @param dim
 */
void copiaArregloDeEnterosAString(int origen[], char destino[], const int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        char *digit = malloc(sizeof(int));
        enteroAString(origen[i], digit);
        strcat(destino, digit);
        free(digit);
    }
}

/**
 * @brief Se ingresan casos de prueba y para cada caso imprime si los datos ingrasdos corresponden o no a un Cuadrado
 *
 */
void esCuadrado()
{
    int casosPrueba, i, aux;
    scanf("%d", &casosPrueba);
    char *respuestas[casosPrueba];
    Rectangulo RecUno;
    Rectangulo RecDos;
    for (i = 0; i < casosPrueba; i++)
    {
        scanf("%d", &aux);
        RecUno.lado1 = aux;
        scanf("%d", &aux);
        RecUno.lado2 = aux;
        scanf("%d", &aux);
        RecDos.lado1 = aux;
        scanf("%d", &aux);
        RecDos.lado2 = aux;
        respuestas[i] = "NO";

        if (RecUno.lado1 == RecDos.lado1 && RecUno.lado1 == RecUno.lado2 + RecDos.lado2)
        {
            respuestas[i] = "SI";
        }
        if (RecUno.lado1 == RecDos.lado2 && RecDos.lado2 == RecUno.lado2 + RecDos.lado1)
        {
            respuestas[i] = "SI";
        }
        if (RecUno.lado2 == RecDos.lado2 && RecDos.lado2 == RecUno.lado1 + RecDos.lado1)
        {
            respuestas[i] = "SI";
        }
        if (RecUno.lado2 == RecDos.lado1 && RecDos.lado1 == RecUno.lado1 + RecDos.lado2)
        {
            respuestas[i] = "SI";
        }
    }

    for (i = 0; i < casosPrueba; i++)
    {
        printf("%s", respuestas[i]);
    }
}

/**
 * @brief Inicializa un vector
 *
 * @param V
 * @param valorInicial
 */
void inicializaVector(Vector *V, int valorInicial)
{
    V->x = valorInicial;
    V->y = valorInicial;
    V->z = valorInicial;
}

/**
 * @brief Carga datos en el vector
 *
 * @param V
 */
void cargarVector(Vector *V)
{
    int aux;
    printf("Ingrese la componente de la fuerza en x: ");
    scanf("%d", &aux);
    V->x = aux;
    printf("Ingrese la componente de la fuerza en Y: ");
    scanf("%d", &aux);
    V->y = aux;
    printf("Ingrese la componente de la fuerza en z: ");
    scanf("%d", &aux);
    V->x = aux;
}

/**
 * @brief Retorna cero si la sumatoria de fuerzas es cero
 *
 * @param Fuerzas
 * @param cantidad
 * @return int
 */
int FuerzasEnEquilibrio(Vector Fuerzas[], int cantidad)
{
    int i = 0, x = 0, y = 0, z = 0, bandera = 0;
    for (i = 0; i < cantidad; i++)
    {
        x += Fuerzas[i].x;
        y += Fuerzas[i].y;
        z += Fuerzas[i].z;
    }

    return x + y + z;
}

// lab 8
/**
 * @brief
 *
 * @param numero
 * @return int
 */
int esPrimo(long numero)
{ // retorna cero si el numero es primo
    int contadorDivisores = 0, i;
    int bandera = 0;
    for (i = 1; i <= (numero / 2); i++)
    { // un numero mayor a la mitad del numero recibido jamas sera divisor exacto

        if (contadorDivisores > 1)
        { // el iterador empieza en uno, y el contador de divisore aumenta, si encuentra otro divisor exacto no es primo

            bandera = 1;
            break;
        }
        else
        {
            if (numero % i == 0)
            {
                contadorDivisores++;
            }
        }
    }

    printf("bander = %d\t", bandera);
    switch (bandera)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
    default:
        return 1;
        break;
    }
}

/**
 * @brief  retorna -1 si es impar 0 si es par y 1 si es primo
 *
 * @param numero
 * @return int
 */
int tipoNumero(long numero)
{
    if (numero < 0)
        numero = numero * -1;

    if (esPrimo(numero) != 1)
    {
        return 1;
    }
    else
    {
        if (numero % 2 == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

// lab 10
/**
 * @brief retorna 0 si los simbolos estan valanveados
 *
 * @param cadena
 * @param pilaContenedora
 * @param simboloApertura
 * @param simboloCierre
 * @return int
 */
int simbolosValanceados(char cadena[], ListaChar pilaContenedora, char simboloApertura, char simboloCierre)
{
    int bandera = 0, i = 0;
    char aux;
    while (cadena[i] != '\0' && cadena[i] != '\n')
    {
        printf("\n%c", cadena[i]);
        if (cadena[i] == simboloApertura)
        {
            insertarCharEnCabeza(cadena[i], &pilaContenedora); // si encuentra apertura de parentesis agrega a la pila
        }
        if (cadena[i] == simboloCierre)
        {
            if (pilaContenedora.cantidadElem == 0)
            { // si encuentra una cierre de parentesis y la pila esta vacia retorna bandera 1
                bandera = 1;
                break;
            }
            else
            {
                aux = extraerCabezaListaChar(&pilaContenedora);
                printf("El valor extraido fue: %c", aux);
            }
        }
        i++;
    }

    // imprimeDesdeLaCabezaListaChar(&pilaContenedora);
    if (pilaContenedora.cantidadElem != 0)
    {
        bandera = 1;
    }

    return bandera;
}

// funciones extra

/**
 * @brief determina si una palabra es un palindromo o no
 *
 * @param cadena
 * @return int ( 1 si es palindromo 0 en caso contrario)
 */
int esPalidromo(char cadena[])
{
    int longitud = strlen(cadena);
    if (longitud <= 1)
        return 1; // las palabras de una sola letra son siempre palindromos
    int inicio = 0, fin = longitud - 1;
    while (cadena[inicio] == cadena[fin])
    {
        if (inicio >= fin)
            return 1; // si sigue en el bucle e inicio y fin ya son iguales retorna 1(es palindromo)
        inicio++;
        fin--;
    }
    return 0; // si sale del bucle entonces no es palindromo
}

/**
 * @brief calcula recursivamente la cantidad de digitos de un entero
 * @param valor
 * @return int
 */
int cantidadDigitosInt(int valor)
{
    int contenedor = 1;
    if (valor > 10)
    {
        contenedor += cantidadDigitosInt(valor / 10);
    }

    return contenedor;
};