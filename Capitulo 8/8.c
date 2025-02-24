/*8. Abrir un archivo de registro del inventario de productos de una tienda. Calcular y mostrar el stock total estimado en dinero de cada rubro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RUBROS 50
#define MAX_NOMBRE 50

typedef struct {
    char rubro[MAX_NOMBRE];
    float stockTotal;
} Rubro;

void calcularStockPorRubro(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return;
    }

    Rubro rubros[MAX_RUBROS];
    int numRubros = 0;

    char rubro[MAX_NOMBRE];
    char nombreProducto[MAX_NOMBRE];
    int cantidad;
    float precio;

    while (fscanf(archivo, "%s %s %d %f", rubro, nombreProducto, &cantidad, &precio) == 4) {
        float valorStock = cantidad * precio;
        int encontrado = 0;

        for (int i = 0; i < numRubros; i++) {
            if (strcmp(rubros[i].rubro, rubro) == 0) {
                rubros[i].stockTotal += valorStock;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado && numRubros < MAX_RUBROS) {
            strcpy(rubros[numRubros].rubro, rubro);
            rubros[numRubros].stockTotal = valorStock;
            numRubros++;
        }
    }

    fclose(archivo);

    printf("Stock total estimado por rubro:\n");
    printf("================================\n");
    for (int i = 0; i < numRubros; i++) {
        printf("Rubro: %s, Stock total: $%.2f\n", rubros[i].rubro, rubros[i].stockTotal);
    }
}

int main() {
    const char* nombreArchivo = "inventario2.txt";
    calcularStockPorRubro(nombreArchivo);

    return 0;
}
