/*48. Desarrollar una función que retorne el enésimo número de Fibonacci usando memoization.*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int memo[n]){
    if(n==0 || n==1){
        return n;
    }else if(memo[n]!=0){
        return memo[n];
    }else{
        memo[n] = fibonacci(n-1,memo) + fibonacci(n-2,memo);
        return memo[n];
    }
}

int main(){
    int n;
    
    printf("Ingrese el valor de n: ");
    scanf("%d",&n);
    
    int memo[n+1];
    
    for(int i=0;i<=n;i++){
        memo[i] = 0;
    }
    
    printf("Fibonacci(%d) = %d\n",n,fibonacci(n,memo));
    
    return 0;
}