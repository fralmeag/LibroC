/*32. Escribir una función que dado un número, retorne la suma de todos sus divisores positivos, sin incluirlo.*/

#include <stdio.h>
#include <stdlib.h>

int sumaDivisores(int numero){
    int suma = 0;
    
    for(int i = 1; i < numero; i++){
        if(numero % i == 0){
            suma += i;
        }
    }
    
    return suma;
}

int main(){
    int numero;
    
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    
    printf("La suma de los divisores de %d es: %d \n", numero, sumaDivisores(numero));
    
    return 0;
}