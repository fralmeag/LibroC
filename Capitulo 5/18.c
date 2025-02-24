/*18. Implementar el algoritmo de selección para ordenar un arreglo con las edades de 10 personas.*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    
    for (i = 0; i < n - 1; i++) {
        min = i;
        
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {
    int n;

    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &n);

    int edades[n];
    
    for (int i = 0; i < n; i++) {
        printf("Ingrese la edad de la persona %d: ", i + 1);
        scanf("%d", &edades[i]);
    }

    selectionSort(edades, n);
    
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%d ", edades[i]);
    
    printf("\n");

    return 0;
}