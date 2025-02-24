/*8. Realizar una calculadora que permita sumar, restar, multiplicar o dividir según la operación seleccionada por el usuario.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1, num2, resultado;
    char operacion;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);
    printf("Ingrese la operación a realizar (+, -, *, /): ");
    scanf(" %c", &operacion);

    switch(operacion){
        case '+':
            resultado = num1 + num2;
            printf("El resultado de la suma es: %d\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("El resultado de la resta es: %d\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("El resultado de la multiplicación es: %d\n", resultado);
            break;
        case '/':
            if(num2 == 0){
                printf("No se puede dividir por 0\n");
            }else{
                resultado = num1 / num2;
                printf("El resultado de la división es: %d\n", resultado);
            }
            break;
        default:
            printf("Operación no válida\n");
    }

    return 0;
}