/*19. Crear una función que retorne TRUE/FALSE dependiendo si un número pasado como parámetro es primo o no.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool primo(int num){

    if(num <= 1){
        return false;
    }

    if(num == 2 || num == 3){
        return true;
    }

    if(num % 2 == 0 && num > 2){
        return false;
    }

    for(int i = 2; i <= sqrt(num); i++){

            if(num % i == 0){
                return false;
            }
    }

    return true;
}


int main(){

    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if(primo(numero)){
        printf("TRUE");
    }
    else{
        printf("FALSE");
    }
}
