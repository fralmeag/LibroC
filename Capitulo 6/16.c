/*16. Escribir una función recursiva que calcule la potencia utilizando punteros para pasar los parámetros por referencia.*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int *base, int *exp){
    if(*exp == 0){
        return 1;
    }else{
        int new_exp = *exp - 1;
        
        return *base * potencia(base, &new_exp);
    }
}

int main(){
    int base, exp;
    printf("Ingrese la base: ");
    scanf("%d", &base);

    printf("Ingrese el exponente: ");
    scanf("%d", &exp);
 
    printf("El resultado es: %d\n", potencia(&base, &exp));
 
    return 0;
}


