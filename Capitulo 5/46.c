/*46. Implementar el algoritmo de mergesort (mezcla y ordena) para ordenar un arreglo de números.*/

#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = l;
    
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int *arr, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

void imprimirArreglo(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 6;
    int *arr = (int *)malloc(n * sizeof(int));
    
    arr[0] = 38;
    arr[1] = 27;
    arr[2] = 43;
    arr[3] = 3;
    arr[4] = 9;
    arr[5] = 82;
    
    printf("Arreglo original:\n");
    imprimirArreglo(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("\nArreglo ordenado:\n");
    imprimirArreglo(arr, n);
    
    free(arr);
    
    return 0;
}