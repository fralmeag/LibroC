/*50. Implementar una función que retorne una matriz aleatoria invertible generada dinámicamente utilizando calloc, free y srand.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int determinante(int** matriz, int n) {
    if (n == 1) {
        return matriz[0][0];
    }

    if (n == 2) {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    int det = 0;

    for (int p = 0; p < n; p++) {
        int** submatriz = (int**)calloc(n - 1, sizeof(int*));

        for (int i = 0; i < n - 1; i++) {
            submatriz[i] = (int*)calloc(n - 1, sizeof(int));
        }

        for (int i = 1; i < n; i++) {
            int colIndex = 0;

            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                submatriz[i - 1][colIndex] = matriz[i][j];

                colIndex++;
            }
        }

        int subDet = determinante(submatriz, n - 1);
        det += (p % 2 == 0 ? 1 : -1) * matriz[0][p] * subDet;

        for (int i = 0; i < n - 1; i++) {
            free(submatriz[i]);
        }

        free(submatriz);
    }

    return det;
}

void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

int** generarMatrizInvertible(int n) {
    int** matriz = NULL;

    while (1) {
        matriz = (int**)calloc(n, sizeof(int*));
        
        for (int i = 0; i < n; i++) {
            matriz[i] = (int*)calloc(n, sizeof(int));
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = rand() % 10 + 1;
            }
        }

        if (determinante(matriz, n) != 0) {
            break;
        }

        liberarMatriz(matriz, n);
    }

    return matriz;
}

void imprimirMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
     
        printf("\n");
    }
}

int main() {
    int n;
    srand(time(NULL));

    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    int** matriz = generarMatrizInvertible(n);

    printf("Matriz invertible generada aleatoriamente:\n");
    imprimirMatriz(matriz, n);
    liberarMatriz(matriz, n);

    return 0;
}
