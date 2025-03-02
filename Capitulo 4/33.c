/*33. Calcular el producto de dos enteros mediante sumas sucesivas invocando una función recursiva.*/

#include <stdio.h>

int producto(int num1, int num2){

    if(num2 == 0){
        return 0;
    }
    else{
          if(num2 > 0){
            return num1 + producto(num1, num2-1);
          }
          else{
            if(num2 < 0){
                return -producto(num1, -num2);
            }
          }
    }

}


int main(){

    int num1, num2;

    printf("Ingrese el multiplicando: ");
    scanf("%d", &num1);

    printf("Ingrese el multiplicador: ");
    scanf("%d", &num2);

    printf("\nEl resultado es: %d", producto(num1,num2));

    return 0;
}
