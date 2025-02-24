/*42. Desarrollar un programa que codifique una cadena de texto a código Gray utilizando arreglos dinámicos de punteros y bitwise operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcularGray(int n) {
    return n ^ (n >> 1); 
}

void aBinario(int num, char* binario, int tam) {
    for (int i = tam - 1; i >= 0; i--) {
        binario[i] = (num & 1) ? '1' : '0'; 
        num >>= 1;
    }

    binario[tam] = '\0'; 
}

char** codificarCadenaGray(const char* cadena, int longitud) {
    char** resultado = (char**)malloc(longitud * sizeof(char*));

    for (int i = 0; i < longitud; i++) {
        int valorASCII = (int)cadena[i]; 
        int gray = calcularGray(valorASCII);

        resultado[i] = (char*)malloc(9 * sizeof(char)); 
        aBinario(gray, resultado[i], 8); 
    }

    return resultado;
}

void liberarMatriz(char** matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

int main() {
    char cadena[100];

    printf("Ingrese una cadena de texto: ");
    fgets(cadena, 100, stdin);

    size_t longitud = strlen(cadena);

    if (longitud > 0 && cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
        longitud--;
    }

    char** resultado = codificarCadenaGray(cadena, longitud);

    printf("Cadena codificada en código Gray:\n");
    for (int i = 0; i < longitud; i++) {
        printf("Carácter '%c': %s\n", cadena[i], resultado[i]);
    }

    liberarMatriz(resultado, longitud);

    return 0;
}
