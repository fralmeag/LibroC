/*37.Implementar un algoritmo que analice un número e indique si tiene 1, 2, 3 o más de 3 dígitos.*/

#include <stdio.h>

int main(){

    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if(num < 0){
        num = num * (-1);
    }

    if((num >= 0) && (num <= 9)){
        printf("El numero tiene 1 digito");
    }

    if((num >= 10) && (num <= 99)){
        printf("El numero tiene 2 digitos");
    }

    if((num >= 100) && (num <= 999)){
        printf("El numero tiene 3 digitos");
    }

    if(num >= 1000){
        printf("El numero tiene mas de 3 digitos");
    }

    return 0;

}
