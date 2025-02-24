/*27.Desarrollar un programa que determine si un estudiante aprueba
o reprueba un curso considerando que aprobarlo requiere mínimo nota de 61 y 75% de asistencia. */

#include <stdio.h>

int main(){

    int nota, asistencia;

    printf("Ingrese la nota del estudiante: ");
    scanf("%d", &nota);

    printf("Ingrese el porcentaje de asistencia del estudiante: ");
    scanf("%d", &asistencia);

    if((nota >= 61) && (asistencia >= 75)){
        printf("El estudiante aprueba el curso");
    }
    else{
        printf("El estudiante reprueba el curso");
    }

    return 0;
}
