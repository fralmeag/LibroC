/*14. Realizar una función que retorne una cadena de texto rotada N posiciones. Por ejemplo "Hola" rotada 3 queda “laHo”.*/

#include <stdio.h>
#include <string.h>

void rotar(char cadena[], int n){
    int i, j;
    char aux;

    for(i = 0; i < n-1; i++){
        aux = cadena[0];
        
        for(j = 0; j < strlen(cadena) - 1; j++){
            cadena[j] = cadena[j+1];
        }
        
        cadena[j] = aux;
    }
}

int main(){

    char cadena[100];
    int n;

    printf("Ingrese una cadena de texto: ");
    scanf("%s", cadena);

    printf("Ingrese la cantidad de posiciones a rotar: ");
    scanf("%d", &n);

    rotar(cadena, n);

    printf("La cadena rotada es: %s\n", cadena);

    return 0;
}