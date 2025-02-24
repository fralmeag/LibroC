/*48. Crear una función que imprima los elementos de un arreglo en espiral utilizando aritmética de punteros anidada.
*/

#include <stdio.h>
#include <stdlib.h>

void imprimirEspiral(int* matriz, int filas, int columnas) {
    int filaInicio = 0, filaFin = filas - 1;
    int columnaInicio = 0, columnaFin = columnas - 1;

    printf("Elementos en espiral: ");

    while (filaInicio <= filaFin && columnaInicio <= columnaFin) {
        for (int i = columnaInicio; i <= columnaFin; i++) {
            printf("%d ", *(matriz + filaInicio * columnas + i));
        }
       
        filaInicio++;

        for (int i = filaInicio; i <= filaFin; i++) {
            printf("%d ", *(matriz + i * columnas + columnaFin));
        }
       
        columnaFin--;

        if (filaInicio <= filaFin) {
            for (int i = columnaFin; i >= columnaInicio; i--) {
                printf("%d ", *(matriz + filaFin * columnas + i));
            }
            
            filaFin--;
        }

        if (columnaInicio <= columnaFin) {
            for (int i = filaFin; i >= filaInicio; i--) {
                printf("%d ", *(matriz + i * columnas + columnaInicio));
            }
            
            columnaInicio++;
        }
    }
    
    printf("\n");
}

int main() {
    int filas, columnas;

    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int* matriz = (int*)malloc(filas * columnas * sizeof(int));

    if (matriz == NULL) {
        printf("Error al asignar memoria.\n");
        
        return 1;
    }

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            
            if (scanf("%d", matriz + (i * columnas + j)) != 1) {
                printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                free(matriz);
            
                return 1;
            }
        }
    }

    imprimirEspiral(matriz, filas, columnas);
    
    free(matriz);

    return 0;
}

