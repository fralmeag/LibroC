/*26. Escribir una función que llene dinámicamente un arreglo bidimensional con números primos utilizando calloc.*/

#include <stdio.h>
#include <stdlib.h>

int esPrimo(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}   

void llenarPrimos(int** arr, int filas, int columnas) {
    int num = 2;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            while (!esPrimo(num)) {
                num++;
            }

            arr[i][j] = num;
            num++;
        }
    }
}

int main() {
    int filas, columnas;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);

    int** arr = (int**)calloc(filas, sizeof(int*));
    for (int i = 0; i < filas; i++) {
        arr[i] = (int*)calloc(columnas, sizeof(int));
    }

    llenarPrimos(arr, filas, columnas);

    printf("Arreglo bidimensional de primos:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < filas; i++) {
        free(arr[i]);
    }
    
    free(arr);

    return 0;
}