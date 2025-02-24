/*40. Implementar una función que imprima los elementos distintos de dos arreglos dinámicos ordenados de enteros recibidos como argumento.*/

#include <stdio.h>
#include <stdlib.h>

void imprimirElementosDistintos(int* A, int n, int* B, int m) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            printf("%d ", A[i]);
            i++;
        } else if (A[i] > B[j]) {
            printf("%d ", B[j]);
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < n) {
        printf("%d ", A[i]);
        i++;
    }

    while (j < m) {
        printf("%d ", B[j]);
        j++;
    }
}

int main() {
    int n, m;

    printf("Ingrese el tamaño del arreglo A: ");
    scanf("%d", &n);
    int* A = (int*)malloc(n * sizeof(int));

    printf("Ingrese el tamaño del arreglo B: ");
    scanf("%d", &m);
    int* B = (int*)malloc(m * sizeof(int));

    printf("Ingrese los elementos del arreglo A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Ingrese los elementos del arreglo B: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    printf("Arreglo A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\nArreglo B: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", B[i]);
    }

    printf("\nElementos distintos: ");
    imprimirElementosDistintos(A, n, B, m);
 
    free(A);
    free(B);
 
    printf("\n");

    return 0;
}