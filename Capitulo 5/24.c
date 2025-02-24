/*24. Crear una función que reciba una matriz Cuadrada y retorne si es diagonal o no.  
*/

#include <stdio.h>
#include <stdlib.h>

#define N 3

int esDiagonal(int matriz[N][N]){
    int i, j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){

            if(i != j && matriz[i][j] != 0){
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    int matriz[N][N] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};

    if(esDiagonal(matriz)){
        printf("La matriz es diagonal\n");
    }else{
        printf("La matriz no es diagonal\n");
    }

    return 0;
}
