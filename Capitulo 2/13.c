/*13. Realizar un algoritmo que analice 3 valores ingresados y los ordene de forma descendente.*/

#include <stdio.h>

int main(){

    int valor1, valor2, valor3;

    printf("Ingrese el primer valor: ");
    scanf("%d", &valor1);

    printf("Ingrese el segundo valor: ");
    scanf("%d", &valor2);

    printf("Ingrese el tercer valor: ");
    scanf("%d", &valor3);

    if(valor1 > valor2){
        if(valor1 > valor3){
            printf(" %d ", valor1);
            if(valor2 > valor3){
                printf(" %d %d ", valor2, valor3);
            }
            else{
                printf(" %d %d ", valor3, valor2);
            }
        }
        else{
            printf(" %d %d %d ", valor3, valor1, valor2);
        }
    }
    else{
        if(valor2 > valor3){
            printf(" %d ", valor2);
            if(valor1 > valor3){
                printf(" %d %d ", valor1, valor3);
            }
            else{
                printf(" %d %d ", valor3, valor1);
            }

        }
        else{
            printf(" %d %d %d ", valor3, valor2, valor1);
        }
    }

    return 0;
}
