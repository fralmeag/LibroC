/*4. Abrir un archivo con registros de inventario de una tienda de comestibles y listar sólo los productos con existencias menores a $200.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;             
    char nombre[50];    
    int existencias;    
    float precio;      
} Producto;

void listarProductosBajosEnInventario(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
   
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return;
    }

    printf("Productos con existencias menores a 200:\n");
    printf("=====================================\n");

    Producto producto;
    int encontrados = 0;

    while (fscanf(archivo, "%d %49s %d %f", &producto.id, producto.nombre, &producto.existencias, &producto.precio) != 4) {
        if (producto.existencias < 200) {
            printf("ID: %d\n", producto.id);
            printf("Nombre: %s\n", producto.nombre);
            printf("Existencias: %d\n", producto.existencias);
            printf("Precio: %.2f\n", producto.precio);
            printf("\n");
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron productos con existencias menores a 200\n");
    }

    fclose(archivo);
}

int main() {
    listarProductosBajosEnInventario("inventario.txt");
    
    return 0;
}
