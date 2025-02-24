/*26. Implementar una función que retorne un arreglo con la secuencia de Fibonacci hasta el índice N. */

#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n, int arr[]){
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i < n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
}

int main(){
    int n;
    printf("Ingrese el indice N: ");
    scanf("%d", &n);
    
    int arr[n];
    fibonacci(n, arr);
    
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    return 0;
}