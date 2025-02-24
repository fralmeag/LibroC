/*36. Escribir una función recursiva para multiplicar dos matrices utilizando memoria dinámica.*/

#include <stdio.h>
#include <stdlib.h>

int** crearMatriz(int filas, int columnas) {
    int** matriz = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*)malloc(columnas * sizeof(int));
    }
    
    return matriz;
}

void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    
    free(matriz);
}

void imprimirMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        
        printf("\n");
    }
}

int calcularElemento(int** A, int** B, int fila, int columna, int n, int k) {
    if (k == n)
        return 0;
    
    return A[fila][k] * B[k][columna] + calcularElemento(A, B, fila, columna, n, k + 1);
}

void multiplicarMatricesRecursivo(int** A, int** B, int** C, int filasA, int columnasB, int n, int fila, int columna) {
    if (fila == filasA)
        return;

    if (columna == columnasB) {
        multiplicarMatricesRecursivo(A, B, C, filasA, columnasB, n, fila + 1, 0);
        return;
    }

    C[fila][columna] = calcularElemento(A, B, fila, columna, n, 0);

    multiplicarMatricesRecursivo(A, B, C, filasA, columnasB, n, fila, columna + 1);
}

int main() {
    int filasA, columnasA, filasB, columnasB;

    printf("Ingrese las dimensiones de la matriz A (filas columnas): ");
    scanf("%d %d", &filasA, &columnasA);
    printf("Ingrese las dimensiones de la matriz B (filas columnas): ");
    scanf("%d %d", &filasB, &columnasB);

    if (columnasA != filasB) {
        printf("Error: las matrices no se pueden multiplicar.\n");
        return 1;
    }

    int** A = crearMatriz(filasA, columnasA);
    int** B = crearMatriz(filasB, columnasB);

    printf("Ingrese los elementos de la matriz A:\n");
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Ingrese los elementos de la matriz B:\n");
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int** C = crearMatriz(filasA, columnasB);

    multiplicarMatricesRecursivo(A, B, C, filasA, columnasB, columnasA, 0, 0);

    printf("El resultado de la multiplicación es:\n");
    imprimirMatriz(C, filasA, columnasB);

    liberarMatriz(A, filasA);
    liberarMatriz(B, filasB);
    liberarMatriz(C, filasA);

    return 0;
}

