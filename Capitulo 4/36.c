/*36. Crear una función recursiva que calcule Ackermann(m,n) sin utilizar ciclos.
*/

#include <stdio.h>
#include <stdlib.h>

int Ackermann(int m, int n){
    if(m == 0){
        return n + 1;
    }else if(n == 0){
        return Ackermann(m - 1, 1);
    }else{
        return Ackermann(m - 1, Ackermann(m, n - 1));
    }
}

int main(){
    int m, n;
    
    printf("Ingrese m: ");
    scanf("%d", &m);
    printf("Ingrese n: ");
    scanf("%d", &n);
    printf("Ackermann(%d, %d) = %d\n", m, n, Ackermann(m, n));
    
    return 0;
}