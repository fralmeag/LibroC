/*42. Realizar una función recursiva que calcule la serie armónica H(n) = 1 + (1/2) + (1/3) + ... + (1/n)*/

#include <stdio.h>
#include <stdlib.h>

int serieArmonica(int n){
    if(n == 1){
        return 1;
    }else{
        return 1.0/n + serieArmonica(n-1);
    }
}

int main(){
    int n;
    
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("La serie armonica de %d es: %f\n", n, serieArmonica(n));
    
    return 0;
}