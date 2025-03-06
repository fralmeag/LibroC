/*17.Escribir una función que reciba una frase y retorne la misma frase invertida.*/

#include <stdio.h>
#include <string.h>

char* invertida(char frase[], char frase_invertida[]){

    int i = 0;
    int j = strlen(frase) - 1;



    while(j >= 0){

        frase_invertida[i] = frase[j];

        i++;
        j--;
    }

    frase_invertida[strlen(frase)] = '\0';

    return frase_invertida;

}

int main(){

    char frase[100];
    char frase_invertida[100];

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("%s", invertida(frase,frase_invertida));

    return 0;
}
