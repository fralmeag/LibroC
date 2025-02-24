/*50. Realizar un algoritmo que dado el sueldo de un trabajador calcule su categoría impositiva y descuente el porcentaje de impuestos correspondiente.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float sueldo;
    
    printf("Ingrese el sueldo del trabajador: ");
    scanf("%f", &sueldo);
    
    if(sueldo <= 10000){
        printf("Categoria impositiva: 1\n");
        printf("Impuesto a descontar: %.2f\n", sueldo * 0.05);
    }else if(sueldo > 10000 && sueldo <= 15000){
        printf("Categoria impositiva: 2\n");
        printf("Impuesto a descontar: %.2f\n", sueldo * 0.10);
    }else if(sueldo > 15000 && sueldo <= 20000){
        printf("Categoria impositiva: 3\n");
        printf("Impuesto a descontar: %.2f\n", sueldo * 0.15);
    }else if(sueldo > 20000){
        printf("Categoria impositiva: 4\n");
        printf("Impuesto a descontar: %.2f\n", sueldo * 0.20);
    }
    
    return 0;
}