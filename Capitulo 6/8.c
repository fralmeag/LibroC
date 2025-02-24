/*8. Crear una función para determinar si un arreglo contiene un valor específico utilizando únicamente punteros.
*/

#include <stdio.h>
#include <stdlib.h>

int contiene(int *arr, int n, int val){
    for(int i = 0; i < n; i++){
        if(*(arr + i) == val){
            return 1;
        }
    }
    return 0;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val;

    printf("El arreglo es: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }

    printf("\n");

    printf("Ingrese el valor a buscar: ");
    scanf("%d", &val);
    
    if(contiene(arr, n, val)){
        printf("El arreglo contiene el valor %d\n", val);
    }else{
        printf("El arreglo no contiene el valor %d\n", val);
    }
    
    return 0;
}