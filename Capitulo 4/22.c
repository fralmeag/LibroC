/*22. Obtener la serie fibonacci de los primeros 10 números usando recursión.*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main(){
    int i;

    for(i=0;i<10;i++){
        printf("%d ",fibonacci(i));
    }
    
    printf("\n");

    return 0;
}