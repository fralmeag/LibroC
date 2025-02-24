/*14. Crear una función que reciba N notas de alumnos y retorne la nota promedio.*/

#include <stdio.h>
#include <stdlib.h>

float promedio(int n, float notas[]){
    float promedio = 0;
    
    for(int i = 0; i < n; i++){
        promedio += notas[i];
    }
    
    return promedio/n;
}

int main(){
    int n;
    printf("Ingrese la cantidad de notas: ");
    scanf("%d", &n);
    
    float notas[n];
    
    for(int i = 0; i < n; i++){
        printf("Ingrese la nota %d: ", i+1);
        scanf("%f", &notas[i]);
    }
    
    printf("El promedio de las notas es: %.2f", promedio(n, notas));
    
    return 0;
}