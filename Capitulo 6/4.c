/*4. USANDO PUNTEROS Realizar una función que retorne si una matriz es simétrica o no usando solo punteros para iterar sobre sus elementos. */

#include <stdio.h>
#include <stdlib.h>

int esSimetrica(int **matriz, int filas, int columnas){
    int i, j;
    for(i = 0; i < filas; i++){
        for(j = 0; j < columnas; j++){
            if(*(*(matriz + i) + j) != *(*(matriz + j) + i)){
                return 0;
            }
        }
    }
 
    return 1;
}

int main(){
    int filas, columnas, i, j;
    int matriz[3][3] = {{-8, 1, 3}, {1, 7, 4}, {3, 4, 9}};
    int **matrizPunteros = (int **)malloc(3 * sizeof(int *));

    for(i = 0; i < 3; i++){
        matrizPunteros[i] = (int *)malloc(3 * sizeof(int));
        for(j = 0; j < 3; j++){
            *(*(matrizPunteros + i) + j) = matriz[i][j];
        }
    }

    if(esSimetrica(matrizPunteros, 3, 3)){
        printf("La matriz es simetrica\n");
    }else{
        printf("La matriz no es simetrica\n");
    }

    for(i = 0; i < 3; i++){
        free(matrizPunteros[i]);
    }

    free(matrizPunteros);

    return 0;
}

