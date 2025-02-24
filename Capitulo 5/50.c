/*50. Realizar una función que retorne una cadena cotizada con comillas dobles al inicio y final.*/

#include <stdio.h>
#include <stdlib.h>

void cotizarCadena(char cadena[], char cadenaCotizada[]) {
    cadenaCotizada[0] = '"';
    int i;
    
    for (i = 0; cadena[i] != '\0'; i++) {
        cadenaCotizada[i + 1] = cadena[i];
    }
    
    cadenaCotizada[i + 1] = '"';
    cadenaCotizada[i + 2] = '\0';
}

int main() {
    char cadena[] = "Hola, mundo";
    char cadenaCotizada[100];
    
    cotizarCadena(cadena, cadenaCotizada);
    
    printf("Cadena original: %s\n", cadena);
    printf("Cadena cotizada: %s\n", cadenaCotizada);
    
    return 0;
}