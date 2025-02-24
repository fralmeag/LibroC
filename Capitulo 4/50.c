/*50. Realizar una función recursiva que retorne la suma de todos los dígitos pares de un número entero.*/

#include <stdio.h>
#include <stdlib.h>

int sumaDigitosPares(int n){
    if(n==0){
        return 0;
    }else if((n%10)%2==0){
        return (n%10) + sumaDigitosPares(n/10);
    }else{
        return sumaDigitosPares(n/10);
    }
}

int main(){
    int n;
    
    printf("Ingrese un número entero: ");
    scanf("%d",&n);
    
    printf("La suma de los dígitos pares de %d es: %d\n",n,sumaDigitosPares(n));
    
    return 0;
}