/*47. Desarrollar un algoritmo que lea el sueldo bruto de un trabajador e implemente un aumento
del 15% si gana menos de $1000; 12% si está entre $1000 y $3500; 10% en otro caso.
Imprimir el sueldo bruto y neto luego del aumento.*/

#include <stdio.h>

int main(){

    int sueldo;

    printf("Ingrese el sueldo del trabajador: ");
    scanf("%d", &sueldo);

    if(sueldo < 1000){

        printf("El sueldo bruto es = %d", sueldo);

        sueldo = sueldo + (sueldo * 0.15);

        printf("\nEl sueldo con aumento del 15 porciento es = %d", sueldo);
    }
    else{
        if(sueldo >= 1000 && sueldo <= 3500){

            printf("El sueldo bruto es = %d", sueldo);

            sueldo = sueldo + (sueldo * 0.12);

            printf("\nEl sueldo con aumento del 12 porciento es = %d", sueldo);
        }
        else{
            printf("El sueldo bruto es = %d", sueldo);

            sueldo = sueldo + (sueldo * 0.10);

            printf("\nEl sueldo con aumento del 10 porciento es = %d", sueldo);
        }
    }

    return 0;
}
