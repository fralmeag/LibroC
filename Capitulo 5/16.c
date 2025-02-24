/*16. Crear un programa que llene una matriz con números primos y muestre los números por pantalla.*/

#include <stdio.h>
#include <stdbool.h>

bool es_primo(int n){
    int i;
    
    for(i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    int matriz[3][3];
    int i, j, n = 2;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            while(!es_primo(n)){
                n++;
            }
            matriz[i][j] = n;
            n++;
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}