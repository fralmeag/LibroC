/*1. Escribir una función que reciba dos enteros y retorne el mayor.*/

#include <stdio.h>

int mayor(int num1, int num2){

    if(num1 > num2){
        return num1;
    }
    else{
        return num2;
    }
}


int main(){

    int numero1, numero2, num_mayor;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);

    num_mayor = mayor(numero1, numero2);

    printf("El numero mayor es: %d", num_mayor);

    return 0;

}
