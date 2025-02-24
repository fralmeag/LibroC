/*12. Implementar el algoritmo de ordenamiento quicksort para ordenar un arreglo de enteros.*/

#include <stdio.h>
#include <stdlib.h>

void quicksort(int n, int arr[n], int izq, int der){
    int i, j, pivote, aux;
    i = izq;
    j = der;
    pivote = arr[(izq + der) / 2];
    do{
        while(arr[i] < pivote && i < der) i++;
        while(arr[j] > pivote && j > izq) j--;
        if(i <= j){
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);
    if(izq < j) quicksort(n, arr, izq, j);
    if(i < der) quicksort(n, arr, i, der);
}

int main(){
    int n;
    
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);
    int arr[n];
    
    for(int i = 0; i < n; i++){
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    quicksort(n, arr, 0, n - 1);
    
    printf("Arreglo ordenado: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}
