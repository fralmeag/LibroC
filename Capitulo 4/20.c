/*20. Generar los números triangulares del 1 al 100 mediante ciclos.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, suma = 0;
    
    for(i = 1; i <= 100; i++){
        suma = 0;
    
        for(j = 1; j <= i; j++){
            suma += j;
        }
    
        printf("%d\n", suma);
    }
    
    return 0;
}