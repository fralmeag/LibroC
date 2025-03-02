/*3. Calcular el factorial de un número usando ciclo for.*/

#include <stdio.h>

int main(){

    int numero, resultado = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);


    for(int i = 1; i<=numero; i++){

        resultado = resultado * i;

    }

    printf("\nEl factorial de %d es %d", numero, resultado);

    return 0;

}
