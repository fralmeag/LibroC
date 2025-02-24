/*20. Crear una aplicación que lea tres números que representan los lados de un triángulo e indique si los valores corresponden a un triángulo o no.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int lado1, lado2, lado3;
    
    printf("Ingrese el primer lado del triangulo: ");
    scanf("%d", &lado1);
    printf("Ingrese el segundo lado del triangulo: ");
    scanf("%d", &lado2);
    printf("Ingrese el tercer lado del triangulo: ");
    scanf("%d", &lado3);
    
    if(lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1){
        printf("Los valores ingresados corresponden a un triangulo\n");
    }else{
        printf("Los valores ingresados no corresponden a un triangulo\n");
    }
    
    return 0;
}