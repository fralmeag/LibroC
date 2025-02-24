/*12. Crear un programa que determine si un triángulo es isósceles, equilátero o escaleno con base en la longitud de sus lados.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lado1, lado2, lado3;

    printf("Ingrese el primer lado del triangulo: ");
    scanf("%f", &lado1);
    printf("Ingrese el segundo lado del triangulo: ");
    scanf("%f", &lado2);
    printf("Ingrese el tercer lado del triangulo: ");
    scanf("%f", &lado3);

    if (lado1 == lado2 && lado2 == lado3)
    {
        printf("El triangulo es equilatero\n");
    }
    else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
    {
        printf("El triangulo es isosceles\n");
    }
    else
    {
        printf("El triangulo es escaleno\n");
    }

    return 0;
}