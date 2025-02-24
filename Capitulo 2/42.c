/*42. Desarrollar un algoritmo que lea tres números distintos y determine cuál de ellos es el mayor. Considerar el caso en que el mayor no es único.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1, num2, num3;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &num3);

    if(num1 > num2 && num1 > num3){
        printf("El numero mayor es: %d\n", num1);
    }else if(num2 > num1 && num2 > num3){
        printf("El numero mayor es: %d\n", num2);
    }else if(num3 > num1 && num3 > num2){
        printf("El numero mayor es: %d\n", num3);
    }else{
        printf("Los numeros son iguales\n");
    }
    
    return 0;
}
