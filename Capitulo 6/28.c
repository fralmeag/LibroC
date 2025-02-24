/*28. Crear una función que retorne un puntero a una copia invertida de una cadena recibida como parámetro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *invertirCadena(char *cadena){
    int i, j;
    
    char *cadenaInvertida = (char *)malloc(strlen(cadena) * sizeof(char));
    
    for(i = strlen(cadena) - 1, j = 0; i >= 0; i--, j++){
        cadenaInvertida[j] = cadena[i];
    }
    
    cadenaInvertida[j] = '\0';
    
    return cadenaInvertida;
}

int main(){
    char cadena[100];

    printf("Introduce una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    printf("Cadena invertida: %s\n", invertirCadena(cadena));

    return 0;
}