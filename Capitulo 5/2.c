/*2. Inicializar un array con los números primos del 1 al 50 generados por una función y mostrarlos en pantalla.*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 50

bool isPrime(int n){
    if(n < 2) return false;
    
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    
    return true;
}

int main(){
    int primes[SIZE];
    int count = 0;
    
    for(int i = 1; i <= 50; i++){
        if(isPrime(i)){
            primes[count] = i;
            count++;
        }
    }
    
    for(int i = 0; i < count; i++){
        printf("%d ", primes[i]);
    }
    
    return 0;
}