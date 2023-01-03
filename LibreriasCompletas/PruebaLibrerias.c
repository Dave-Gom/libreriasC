#include "headerDocumentado.h"

int main()
{
    Archivo *ArchivoInforme = malloc(sizeof(Archivo));
    ListaInt *Lista = malloc(sizeof(ListaInt));
    ListaInt *nuevaLista = creaListaIntAleatoria();
    imprimeDesdeLaCabezaListaInt(nuevaLista);
    guardaListaIntEnArchivoInforme(nuevaLista);
    ArchivoInforme = abreArchivoParaLectura();
    leeListaIntDeArchivoInforme(Lista, ArchivoInforme);
    imprimeDesdeLaCabezaListaInt(Lista);
    return 0;
}
