/*15.Calcular el máximo común divisor (MCD) de dos números con algoritmo de Euclides.*/

#include <stdio.h>

int main(){

    int numero1, numero2;
    int auxiliar;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);

    while(numero2 != 0){

        auxiliar = numero2;
        numero2 = numero1 % numero2;
        numero1 = auxiliar;

    }

    printf("El MCD es %d", numero1);

    return 0;


}
