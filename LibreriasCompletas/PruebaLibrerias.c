#include "headerDocumentado.h"

int main()
{
    int dato;
    ListaInt *NuevaLista = creaListaIntAleatoria();
    // imprimeDesdeLaCabezaListaInt(NuevaLista);
    // extraerCabezaListaInt(NuevaLista);/
    guardaListaIntEnArchivoInforme(NuevaLista);
    // printf("EL valor es %d", valor);
    return 0;
}
