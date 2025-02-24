/*14. Realizar una función que reciba dos arreglos de enteros como parámetros y calcule su producto escalar solo a través de punteros.*/

#include <stdio.h>
#include <stdlib.h>

void productoEscalar(int *a, int *b, int n){
    int producto = 0;
    
    for(int i = 0; i < n; i++){
        producto += a[i] * b[i];
    }
    
    printf("El producto escalar es: %d\n", producto);
}

void imprimirArreglo(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    
    printf("\n");
}

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    
    printf("Arreglo a: ");
    imprimirArreglo(a, 5);

    printf("Arreglo b: ");
    imprimirArreglo(b, 5);
    
    productoEscalar(a, b, 5);
    
    return 0;
}