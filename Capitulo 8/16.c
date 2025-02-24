/*16. Crear un archivo binario con registros de artículos con código y ubicación. Escribir un programa para generar reportes de distribución por almacén y artículos por ubicación.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTICULOS 100

typedef struct {
    int codigo;
    char ubicacion[50];
} Articulo;

void crearArchivoBinario(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");

    if (!archivo) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    Articulo articulos[MAX_ARTICULOS] = {
        {101, "Almacen A - Estante 1"},
        {102, "Almacen B - Estante 2"},
        {103, "Almacen A - Estante 3"},
        {104, "Almacen C - Estante 1"},
        {105, "Almacen B - Estante 4"}
    };

    fwrite(articulos, sizeof(Articulo), 5, archivo);

    fclose(archivo);
    printf("Archivo binario '%s' creado exitosamente.\n", nombreArchivo);
}

void generarReporte(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (!archivo) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    Articulo articulo;
    printf("Reporte de distribución por almacén:\n");
    printf("==============================\n");

    while (fread(&articulo, sizeof(Articulo), 1, archivo)) {
        printf("Código: %d, Ubicación: %s\n", articulo.codigo, articulo.ubicacion);
    }

    fclose(archivo);
}

int main() {
    const char *nombreArchivo = "articulos.dat";
    crearArchivoBinario(nombreArchivo);

    generarReporte(nombreArchivo);

    return 0;
}
