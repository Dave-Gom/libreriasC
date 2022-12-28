#include "headerDocumentado.h"

int main()
{
    int dato;
    ListaInt *NuevaLista = creaListaIntAleatoria();
    Archivo *NuevoArchivo = creaArchivo();
    guardaListaIntEnArchivoNuevo(NuevaLista, NuevoArchivo);
    cierraArchivo(NuevoArchivo);
    return 0;
}
