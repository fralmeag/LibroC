/*1.Escribir una función que intercambie el valor de dos variables utilizando punteros.*/

#include <stdio.h>

void intercambio(int *a, int *b){

    int temporal = *a;
    *a = *b;
    *b = temporal;

}

int main(){

    int x = 15, y = 50;

    printf("Antes de intercambiar valores--> x = %d, y = %d", x,y);

    intercambio(&x,&y);

    printf("\nDespues de intercambiar valores--> x = %d, y = %d", x,y);

    return 0;
}
