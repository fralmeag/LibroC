/*2. Crear una función que reciba una cadena de texto y retorne su longitud.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int longitud(char cadena[]){
    int i = 0;
    
    while(cadena[i] != '\0'){
        i++;
    }
    
    return i;
}

int main(){
    char cadena[100];
    
    printf("Ingrese una cadena de texto: ");
    scanf("%s", cadena);
    
    printf("La longitud de la cadena es: %d \n", longitud(cadena));
    
    return 0;
}
