/*9.Invertir un número leído por teclado utilizando ciclo while.*/

#include <stdio.h>

int main(){

    int numero, digito, invertido = 0;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    while(numero != 0){

        digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero = numero / 10;
    }

    printf("Numero invertido: %d", invertido);

    return 0;

}
