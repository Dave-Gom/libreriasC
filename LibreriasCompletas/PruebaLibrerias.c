#include "headerDocumentado.h"

int main()
{
    ListaString ListaP = INICIALIZALISTA;
    char exem[15];
    cadenaAleatoria(exem, 15);
    insertarEnColaListaString(&ListaP);
    insertarEnColaListaString(&ListaP);
    insertarEnColaListaString(&ListaP);
    insertarEnColaListaString(&ListaP);
    imprimeDesdeLaCabezaListaString(&ListaP);
    char *aux = extraerCabezaListaString(&ListaP);
    printf("%s\n", aux);
    imprimeDesdeLaCabezaListaString(&ListaP);
    imprimeDesdeLaColaListaString(&ListaP);

    return 0;
}
