/*8. Contar la cantidad de vocales que tiene un texto ingresado con ciclo do-while.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    char texto[100];
    int i = 0, contador = 0;

    printf("Ingrese un texto: ");
    scanf("%[^\n]", texto);
    
    do{
        if(tolower(texto[i]) == 'a' || tolower(texto[i]) == 'e' || tolower(texto[i]) == 'i' || tolower(texto[i]) == 'o' || tolower(texto[i]) == 'u'){
            contador++;
        }

        i++;
    }while(texto[i] != '\0');
    
    printf("La cantidad de vocales en el texto es: %d\n", contador);
    
    return 0;
}