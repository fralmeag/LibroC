/*21.Implementar una funci�n que retorne el n�mero de d�gitos de un n�mero entero recibido como argumento.*/

#include <stdio.h>

int digitos(char numero[100]){

    int i = 0;
    int digitos = 0;

    while(numero[i] != '\0'){

        digitos++;
        i++;
    }

    return digitos;

}

int main(){

    char numero[100];

    printf("Ingrese un numero: ");
    scanf("%s", numero);

    printf("\nEl numero tiene %d digitos", digitos(numero));

    return 0;

}
