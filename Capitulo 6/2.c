/*2. Crear una función que sume dos matrices de enteros utilizando aritmética de punteros para iterar.*/

#include <stdio.h>
#include <stdlib.h>

void sumarMatrices(int *matriz1, int *matriz2, int *matrizResultado, int filas, int columnas){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            *(matrizResultado + i*columnas + j) = *(matriz1 + i*columnas + j) + *(matriz2 + i*columnas + j);
        }
    }
}

void imprimirMatriz(int *matriz, int filas, int columnas){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            printf("%d ", *(matriz + i*columnas + j));
        }
        printf("\n");
    }
}

int main(){
    int filas = 3;
    int columnas = 3;
    int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrizResultado[3][3];

    sumarMatrices(&matriz1[0][0], &matriz2[0][0], &matrizResultado[0][0], filas, columnas);
    imprimirMatriz(&matrizResultado[0][0], filas, columnas);

    return 0;
}