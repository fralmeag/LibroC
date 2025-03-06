/*11.Implementar una función que reciba una cadena de texto y retorne TRUE si es un palíndromo,
FALSE en caso contrario*/

#include <stdio.h>
#include <string.h>

int palindromo(char palabra[]){

    int f = strlen(palabra) - 1;
    int i = 0;
    int respuesta = 0;

    while((palabra[i] != '\0')){

        if(palabra[i] == palabra[f]){

           respuesta++;
        }

        i++;
        f--;

    }

    if(respuesta == strlen(palabra)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char palabra[50];

    printf("Escriba una palabra: ");
    scanf("%s", palabra);

    if(palindromo(palabra) == 1){
        printf("\nTRUE");
    }
    else{
        printf("\nFALSE");
    }

    return 0;

}
