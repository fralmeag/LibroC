/*5. Implementar una función que reciba 3 números y retorne el promedio.*/

#include <stdio.h>

float promedio(float num1, float num2, float num3){

    return (num1 + num2 + num3) / 3;

}

int main(){

    float num1, num2, num3;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);

    printf("\nIngrese el segundo numero: ");
    scanf("%f", &num2);

    printf("\nIngrese el tercer numero: ");
    scanf("%f", &num3);

    printf("\nEl promedio de los tres numeros es = %f", promedio(num1, num2, num3));

    return 0;
}
