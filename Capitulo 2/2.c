/*2. Crear una aplicación que valide si un número ingresado es par o impar.*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    
    if(num % 2 == 0){
        printf("El numero %d es par \n", num);
    }else{
        printf("El numero %d es impar \n", num);
    }

    return 0;
}
