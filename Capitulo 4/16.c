/*16. Contar la cantidad de dígitos de un número ingresado usando ciclo do-while*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, cont = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    
    do{
        num /= 10;
        cont++;
    }while(num != 0);
    
    printf("El numero tiene %d digitos\n", cont);
    
    return 0;
}