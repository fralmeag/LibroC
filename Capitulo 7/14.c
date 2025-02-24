/*14. Declarar struct Rectángulo y calcular el área según base y altura. Usar typedef para declarar varios rectángulos.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float base;
    float altura;
} Rectangulo;

int main(){
    Rectangulo r1, r2, r3;
    
    r1.base = 5;
    r1.altura = 10;
    r2.base = 3;
    r2.altura = 7;
    r3.base = 8;
    r3.altura = 12;

    printf("El área del rectángulo 1 es: %.2f\n", r1.base * r1.altura);
    printf("El área del rectángulo 2 es: %.2f\n", r2.base * r2.altura);
    printf("El área del rectángulo 3 es: %.2f\n", r3.base * r3.altura);

    return 0;
}