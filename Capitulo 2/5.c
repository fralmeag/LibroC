/*5. Implementar un algoritmo que lea tres números distintos y determine cuál de ellos es el mayor.*/

#include <stdio.h>

int main(){

    int num1, num2, num3, mayor;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if(num1 > num2){
        mayor = num1;
    }
    else{
        mayor = num2;
    }

    if(mayor > num3){
        printf("El numero mayor es: %d", mayor);
    }
    else{
        printf("El numero mayor es: %d", num3);
    }

    return 0;

}
