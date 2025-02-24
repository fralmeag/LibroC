/*12. Crear un menú que permita sumar o restar dos números según opción usando do-while.  
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcion;
    float num1, num2, resultado;
    
    do{
        printf("1. Sumar\n2. Restar\n3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        if(opcion == 1){
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
            resultado = num1 + num2;
            printf("El resultado de la suma es: %.2f\n", resultado);
        }else if(opcion == 2){
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);
            resultado = num1 - num2;
            printf("El resultado de la resta es: %.2f\n", resultado);
        }else if(opcion == 3){
            printf("Saliendo...\n");
        }else{
            printf("Opcion no valida\n");
        }
    }while(opcion != 3);
    
    return 0;
}