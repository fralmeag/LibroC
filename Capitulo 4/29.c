/*29.Implementar una funci�n recursiva para obtener el m�ximo com�n divisor de dos n�meros.*/

#include <stdio.h>

int mcd(int num1, int num2){

    if(num2 == 0){
        return num1;
    }
    else{
        return mcd(num2, num1 % num2);
    }

}

int main(){

    int num1, num2;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("El MCD es %d", mcd(num1,num2));

    return 0;

}
