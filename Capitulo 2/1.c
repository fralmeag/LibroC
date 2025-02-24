/* 1. Escribir un programa que lea un número y determine si es positivo o negativo. */


#include <stdio.h>

int main() {

    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(numero >= 0)
    {
        printf("El numero %d es positivo", numero);
    }
    else
    {
        printf("El numero %d es negativo", numero);
    }

    return 0;

}
