/*14. Desarrollar una función que reciba las horas trabajadas de un empleado y devuelva su salario, considerando que hasta 40 horas se paga $20 por hora, luego $25.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int horas;
    float salario;
    
    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &horas);
    
    if(horas <= 40){
        salario = horas * 20;
    }else{
        salario = 40 * 20 + (horas - 40) * 25;
    }
    
    printf("El salario es: %.2f\n", salario);
    
    return 0;
}