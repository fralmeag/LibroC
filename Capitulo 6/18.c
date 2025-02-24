/*18. Crear una función que reciba una matriz como parámetro e invierta sus columnas usando aritmética de punteros.*/

#include <stdio.h>
#include <stdlib.h>

void invertirColumnas(int **matriz, int filas, int columnas){
    int i, j;
    int *aux;
    
    for(i = 0; i < columnas; i++){
        for(j = 0; j < filas; j++){
            aux = *(matriz + j) + i;
            printf("%d ", *aux);
        }
        printf("\n");
    }
}

void asignarMatriz(int **matriz, int filas, int columnas){
    int i, j;
    
    for(i = 0; i < filas; i++){
        *(matriz + i) = (int *)malloc(columnas * sizeof(int));
        
        for(j = 0; j < columnas; j++){
            *(*(matriz + i) + j) = i + j;
        }
    }
}

void llenarMatriz(int **matriz, int filas, int columnas){
    int i, j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            printf("Ingrese el valor de la matriz[%d][%d]: ", i, j);
            scanf("%d", *(matriz + i) + j);
        }
    }
}

void liberarMatriz(int **matriz, int filas){
    int i;

    for(i = 0; i < filas; i++){
        free(*(matriz + i));
    }

    free(matriz);
}

int main(){
    int filas, columnas;
    int **matriz;
    int i, j;

    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);

    matriz = (int **)malloc(filas * sizeof(int *));
    
    asignarMatriz(matriz, filas, columnas);
    llenarMatriz(matriz, filas, columnas);
    invertirColumnas(matriz, filas, columnas);
    liberarMatriz(matriz, filas);
    
    return 0;
}