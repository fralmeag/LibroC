/*40. Realizar una función que retorne una cadena con las primeras letras de cada palabra de un string. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* primerasLetras(char* cadena){
    char* nuevaCadena = (char*)malloc((strlen(cadena) / 2 + 1) * sizeof(char));
    int i, j = 0;
    
    for(i = 0; i < strlen(cadena); i++){
        if(i == 0 || cadena[i-1] == ' '){
            nuevaCadena[j] = cadena[i];
            j++;
        }
    }
    
    nuevaCadena[j] = '\0';
    
    return nuevaCadena;
}

int main(){
    char palabra[100];
    
    printf("Ingrese una palabra: ");
    scanf("%[^\n]", palabra);
    
    printf("%s\n", primerasLetras(palabra));
    
    return 0;
}
