/*10. Crear una función que retorne el factorial de un número pasado como parámetro.*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    int i, fact = 1;
 
    for(i = 1; i <= n; i++){
        fact *= i;
    }
 
    return fact;
}

int main(){
    int n;
    
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("El factorial de %d es: %d\n", n, factorial(n));
    
    return 0;
}