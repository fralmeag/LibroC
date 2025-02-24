/*48. Desarrollar una función que retorne una matriz con borde de 1 pixel de grosor igual al valor máximo contenido.*/

#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int encontrarMaximo(int matriz[FILAS][COLUMNAS]) {
    int max = matriz[0][0];
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
    }
    return max;
}

void matrizConBorde(int matriz[FILAS][COLUMNAS], int nuevaMatriz[FILAS + 2][COLUMNAS + 2]) {
    int maximo = encontrarMaximo(matriz);

    for (int i = 0; i < FILAS + 2; i++) {
        for (int j = 0; j < COLUMNAS + 2; j++) {
            nuevaMatriz[i][j] = maximo;
        }
    }

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            nuevaMatriz[i + 1][j + 1] = matriz[i][j];
        }
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {3, 5, 1},
        {2, 8, 4},
        {6, 7, 9}
    };

    int nuevaMatriz[FILAS + 2][COLUMNAS + 2];

    matrizConBorde(matriz, nuevaMatriz);

    printf("Matriz original:\n");
    imprimirMatriz(FILAS, COLUMNAS, matriz);

    printf("\nMatriz con borde:\n");
    imprimirMatriz(FILAS + 2, COLUMNAS + 2, nuevaMatriz);

    return 0;
}
