/*34. Crear una función que recibe una cadena en minúsculas, la convierta a mayúsculas y retorne la nueva cadena. No debe usar funciones de conversión de librerías.*/

#include <stdio.h>
#include <string.h>

void convertirMayusculas(char cadena[]){
    for(int i = 0; i < strlen(cadena); i++){
        if(cadena[i] >= 'a' && cadena[i] <= 'z'){
            cadena[i] = cadena[i] - 32;
        }
    }
}

int main(){
    char cadena[100];
    
    printf("Ingrese una cadena en minusculas: ");
    scanf("%[^\n]", cadena);

    convertirMayusculas(cadena);
    
    printf("La cadena en mayusculas es: %s\n", cadena);
    
    return 0;
}