/*9.Realizar una funci�n que retorne la suma de los N primeros n�meros naturales usando recursividad.*/

#include <stdio.h>

int suma(int n){

    if(n == 0){
        return 0;
    }
    else {
        return n + suma(n-1);
    }
}

int main(){

    int n;

    printf("Ingrese el valor de N: ");
    scanf("%d", &n);

    printf("\nLa suma de los %d primeros numeros naturales es = %d", n, suma(n));

    return 0;
}
