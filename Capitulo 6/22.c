/*22. Desarrollar un programa que codifique una palabra en código Morse utilizando arreglos de punteros.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char* morse[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   // A-I
    ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",  // J-R
    "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--..",         // S-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", // 0-7
    "---..", "----."                                                     // 8-9
};

const char* charToMorse(char c) {
    if (isalpha(c)) { 
        return morse[toupper(c) - 'A'];
    } else if (isdigit(c)) { 
        return morse[c - '0' + 26];
    } else {
        return NULL; 
    }
}

int main() {
    char palabra[100];

    printf("Ingrese una palabra para convertirla a código Morse: ");
    fgets(palabra, 100, stdin);

    printf("Código Morse: ");

    for (int i = 0; i < strlen(palabra); i++) {
        const char* codigo = charToMorse(palabra[i]);
        if (codigo != NULL) {
            printf("%s ", codigo);
        }
    }

    printf("\n");

    return 0;
}
