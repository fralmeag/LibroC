/*20. Implementar una función para multiplicar dos matrices cuadradas utilizando solo aritmética de punteros para iterar.*/

#include <stdio.h>
#include <stdlib.h>

void multiplicarMatrices(int **matriz1, int **matriz2, int **resultado, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            resultado[i][j] = 0;
 
            for(int k = 0; k < n; k++){
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void imprimirMatriz(int **matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
}

int main(){
    int n = 3;
    int **matriz1 = (int **)malloc(n * sizeof(int *));
    int **matriz2 = (int **)malloc(n * sizeof(int *));
    int **resultado = (int **)malloc(n * sizeof(int *));

    for(int i = 0; i < n; i++){
        matriz1[i] = (int *)malloc(n * sizeof(int));
        matriz2[i] = (int *)malloc(n * sizeof(int));
        resultado[i] = (int *)malloc(n * sizeof(int));
    }

    matriz1[0][0] = 1;
    matriz1[0][1] = 2;
    matriz1[0][2] = 3;
    matriz1[1][0] = 4;
    matriz1[1][1] = 5;
    matriz1[1][2] = 6;
    matriz1[2][0] = 7;
    matriz1[2][1] = 8;
    matriz1[2][2] = 9;

    matriz2[0][0] = 9;
    matriz2[0][1] = 8;
    matriz2[0][2] = 7;
    matriz2[1][0] = 6;
    matriz2[1][1] = 5;
    matriz2[1][2] = 4;
    matriz2[2][0] = 3;
    matriz2[2][1] = 2;
    matriz2[2][2] = 1;

    printf("Matriz 1:\n");
    imprimirMatriz(matriz1, n);

    printf("Matriz 2:\n");
    imprimirMatriz(matriz2, n);
    
    printf("Resultado:\n");
    multiplicarMatrices(matriz1, matriz2, resultado, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++){
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }

    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}