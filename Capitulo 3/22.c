/*22. Escribir una función que busque si un caracter se encuentra dentro de una frase pasada como parámetro.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int buscarCaracter(char frase[], char caracter){
    int i;
    
    for(i=0; i<strlen(frase); i++){
        if(frase[i] == caracter){
            return 1;
        }
    }

    return 0;
}

int main(){
    char frase[100], caracter;
    int resultado;

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    printf("Ingrese un caracter: ");
    caracter = getchar();

    resultado = buscarCaracter(frase, caracter);

    if(resultado == 1){
        printf("El caracter %c se encuentra en la frase.\n", caracter);
    }else{
        printf("El caracter %c no se encuentra en la frase.\n", caracter);
    }

    return 0;
}
