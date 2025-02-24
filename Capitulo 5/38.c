/*38. Desarrollar una función que retorne una cadena truncada a una longitud máxima, agregando puntos suspensivos al final.  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* truncar(char* cadena, int longitud){
    char* nuevaCadena = (char*)malloc(longitud+4);
    int i;
    
    for(i=0; i<longitud; i++){
        nuevaCadena[i] = cadena[i];
    }
    
    nuevaCadena[i] = '.';
    nuevaCadena[i+1] = '.';
    nuevaCadena[i+2] = '.';
    nuevaCadena[i+3] = '\0';
    
    return nuevaCadena;
}

int main(){
    char palabra[100];
    int longitud;
    
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    
    printf("Ingrese la longitud maxima: ");
    scanf("%d", &longitud);
    
    printf("%s\n", truncar(palabra, longitud));
    
    return 0;
}