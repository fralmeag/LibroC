/*18. Desarrollar una función que reciba la cantidad de horas trabajadas en una semana y devuelva el salario semanal, considerando que hasta 40 horas se paga $20 por hora y luego $25 la hora extra. */

#include <stdio.h>
#include <stdlib.h>

int salario(int horas){
    int salario = 0;
    
    if(horas <= 40){
        salario = horas * 20;
    }else{
        salario = 40 * 20 + (horas - 40) * 25;
    }
    
    return salario;
}

int main(){
    int horas;
    printf("Ingrese la cantidad de horas trabajadas en la semana: ");
    scanf("%d", &horas);
    
    printf("El salario semanal es: $%d \n", salario(horas));
    
    return 0;
}