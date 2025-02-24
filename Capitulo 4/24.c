/*24. Calcular x^n mediante una función recursiva sin utilizar ciclos.
*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int n){
    if(n==0){
        return 1;
    }else{
        return x*potencia(x,n-1);
    }
}

int main(){
    int x,n;
    
    printf("Ingrese el valor de x: ");
    scanf("%d",&x);
    printf("Ingrese el valor de n: ");
    scanf("%d",&n);
    printf("El resultado de %d^%d es: %d\n",x,n,potencia(x,n));
    
    return 0;
}