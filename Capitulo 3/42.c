/*42. Escribir una función recursiva que calcule la serie 1 + 2 + 3 + ... + N siendo N un número entero positivo.*/

#include <stdio.h>
#include <stdlib.h>

int serie(int n){
    if(n == 1){
        return 1;
    }

    return n + serie(n - 1);
}

int main(){
    int n;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    if(n < 1){
        printf("El numero ingresado no es positivo.\n");
        return 1;
    }

    printf("La suma de los primeros %d numeros enteros positivos es: %d\n", n, serie(n));

    return 0;
}