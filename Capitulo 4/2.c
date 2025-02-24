/*2. Leer números hasta que se ingrese uno negativo usando ciclo while.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    while(num >= 0){
        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }

    return 0;
}
