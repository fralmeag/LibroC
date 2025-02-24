/*4. Escribir un programa que defina un vector de números y calcule la suma de sus elementos.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(){
    int numbers[SIZE] = {1, 2, 3, 4, 5};
    int sum = 0;
    
    for(int i = 0; i < SIZE; i++){
        sum += numbers[i];
    }
    
    printf("Sum: %d\n", sum);
    
    return 0;
}