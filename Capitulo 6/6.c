/*6. Escribir un programa que ordena un array utilizando el algoritmo de la burbuja y punteros para iterar sobre los elementos.*/

#include <stdio.h>
#include <stdlib.h>

void burbuja(int *array, int n){
    int i, j, aux;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(*(array+j)>*(array+j+1)){
                aux = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = aux;
            }
        }
    }
}

int main(){
    int n, i;
    int array[] = {5, 3, 2, 1, 4};

    n = sizeof(array)/sizeof(array[0]);

    burbuja(array, n);

    for(i=0; i<n; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    
    return 0;
}