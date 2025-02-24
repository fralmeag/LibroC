/*4. Realizar una función que retorne la tabla de multiplicar de un número entero entre 1 y 10 pasado como argumento.*/

#include <stdio.h>
#include <stdlib.h>

void tablaMultiplicar(int num){
    for(int i = 1; i <= 10; i++){
        printf("%d x %d = %d\n", num, i, num*i);
    }
}

int main(){
    int num;

    printf("Ingrese un numero entre 1 y 10: ");
    scanf("%d", &num);

    if(num >= 1 && num <= 10){
        tablaMultiplicar(num);
    }else{
        printf("El numero ingresado no esta en el rango de 1 a 10\n");
    }

    return 0;
}