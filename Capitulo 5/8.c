/*8. Crear una función que reciba un arreglo de enteros y retorne el valor máximo.*/

#include <stdio.h>
#include <stdlib.h>

int maximo(int *arreglo, int tamano){
    int max = arreglo[0];
    
    for(int i = 1; i < tamano; i++){
        if(arreglo[i] > max){
            max = arreglo[i];
        }
    }
    
    return max;
}

int main(){
    int arreglo[] = {1, 2, 3, 4, 5, 10, 7, 8, 9, 6};
    
    printf("El valor maximo del arreglo es: %d\n", maximo(arreglo, 10));
    
    return 0;
}