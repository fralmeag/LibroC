/*6. Escribir un programa que lea las horas y minutos de una hora del día e indique si es AM o PM.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int horas, minutos;

    printf("Ingrese la hora: ");
    scanf("%d", &horas);
    printf("Ingrese los minutos: ");
    scanf("%d", &minutos);

    if(horas >= 0 && horas < 12 && minutos >= 0 && minutos <= 59){
        printf("La hora ingresada es AM \n");
    }else if(horas >= 12 && horas <= 24 && minutos >= 0 && minutos <= 59){
        printf("La hora ingresada es PM \n");
    }else{
        printf("La hora ingresada no es valida \n");
    }

    return 0;
}