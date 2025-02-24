/*22. sin usar punteros Implementar una función que retorne el promedio de las notas contenidas en un arreglo ingresado por teclado.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float promedio(float notas[], int n){
    int i;
    float suma = 0.0;
    
    for(i = 0; i < n; i++){
        suma += notas[i];
    }
    
    return suma/n;
}

int main(){
    int n, i;
    float notas[MAX];
    
    printf("Ingrese la cantidad de notas: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        printf("Ingrese la nota %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    
    printf("El promedio de las notas es: %.2f\n", promedio(notas, n));
    
    return 0;
}
