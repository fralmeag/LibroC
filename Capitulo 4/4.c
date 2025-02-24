/*4.Imprimir los primeros 50 números pares utilizando ciclo for.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    
    for(i=1; i<=50; i++){
        printf("%d\n", i*2);
    }
    
    return 0;
}