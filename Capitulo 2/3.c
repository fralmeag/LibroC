/* 3. Desarrollar un programa que compruebe si un a�o ingresado por el usuario es bisiesto. */

#include <stdio.h>

int main() {

    int anio;

    printf("Ingrese un a�o: ");
    scanf("%d", &anio);

    if(anio % 4 == 0){
        if(anio % 100 != 0){
            printf("El a�o %d es bisiesto", anio);
        }
        else{
            if(anio % 400 == 0){
               printf("El a�o %d es bisiesto", anio);
            }
            else{
                printf("El a�o %d NO es bisiesto", anio);
            }
        }
    }
    else {
        printf("El a�o %d NO es bisiesto", anio);
    }



    return 0;
}
