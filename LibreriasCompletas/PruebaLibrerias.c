#include "headerDocumentado.h"

int main(void)
{
    int array[10];
    arrayAleatorio(array, 10, 50);
    imprimeArreglo(array, 10);
    ordenaArrayConArboles(array, 10);
    imprimeArreglo(array, 10);
    int otroArray[10];
    arrayAleatorio(otroArray, 10, 50);
    ordenaArrayConArboles(otroArray, 10);
    imprimeArreglo(otroArray, 10);
}
