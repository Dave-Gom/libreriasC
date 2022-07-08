// David Emmanuel Gomez Arca
#include "headerDocumentado.h"

int main(int argc, char const *argv[])
{
    int i, j, bandera;
    char cadena[LONGITUDCADENA];
    char *palabras[CANTIDAD_MAXIMA_PALABRAS] = {NULL}; // inicializa el array de palabras
    printf("\nIngresa un texto con espacios: ");
    leeConEspacios(cadena);
    int cantidadPalabras = separaParabrasEnArray(palabras, cadena, " "); // el espacio es el separador de entre palabras
    // imprimeArrayPalabras(palabras);
    int ContadoPalabras[cantidadPalabras];
    incicializaContador(ContadoPalabras, cantidadPalabras);

    cuentaPalDelArreglo(ContadoPalabras, cantidadPalabras, palabras);

    FILE *ptrInforme;

    if ((ptrInforme = fopen("Informe.txt", "w")) == NULL)
    {
        printf("\nNo se pudo abrir el archivo");
    }
    else
    {

        fprintf(ptrInforme, "%s", "Palabras más repetidas:\n");
        for (i = 0; i < 3; i++)
        {
            j = posMayor(ContadoPalabras, cantidadPalabras); // almacena en j la posicion del elemewnto mayor del arreglo
            if (strlen(palabras[j]) > 1)
            {
                fprintf(ptrInforme, "%s(%d)", palabras[j], ContadoPalabras[j]); // imprime la
                ContadoPalabras[j] = 0;                                         // asigna cero a esa posicion, entonces en la siguient iteracion obtende el segundo mayor
            }
        }
        fprintf(ptrInforme, "%s", "\n");
    }

    return 0;
}
