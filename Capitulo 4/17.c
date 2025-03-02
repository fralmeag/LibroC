/*17.Convertir un número decimal a binario utilizando ciclo while.*/

#include <stdio.h>

int main(){

    int decimal, residuo, binario = 0, factor = 1;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &decimal);

    while(decimal > 0){

        residuo = decimal % 2;
        binario = binario + residuo * factor;
        factor = factor * 10;
        decimal = decimal / 2;
    }

    printf("El numero decimal en binario es: %d", binario);

    return 0;



}
