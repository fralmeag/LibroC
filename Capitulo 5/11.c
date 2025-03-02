/*11. Desarrollar una función que decodifique una palabra en código Morse*/

#include <stdio.h>
#include <string.h>

int buscarIndice(char abc[], char letra){

    int i = 0;

    while(abc[i] != '\0'){

        if(abc[i] == letra){
            return i;
        }

        i++;
    }

    return -1;

}

int main(){

    char morse[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.",
    "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
    ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----"
    };

    char abc[36] = {'a','b','c','d','e','f','g','h','i','j',
    'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    '1','2','3','4','5','6','7','8','9','0'
    };

    char palabra[200];
    char decodificada[200] = "";

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    int i = 0;
    int indice;

    while(palabra[i] != '\0'){

        indice = buscarIndice(abc,palabra[i]);


        if(indice != -1){
            strcat(decodificada, morse[indice]);
            strcat(decodificada, " ");
        }

        i++;
    }

    printf("\nDecodificacion %s", decodificada);

    return 0;
}
