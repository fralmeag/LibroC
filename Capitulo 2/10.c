/*10. Implementar un algoritmo que lea las 3 notas parciales de un estudiante y calcule si el alumno gana o pierde la materia.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float nota1, nota2, nota3, promedio;

    printf("Ingrese la primera nota: ");
    scanf("%f", &nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%f", &nota2);
    printf("Ingrese la tercera nota: ");
    scanf("%f", &nota3);

    promedio = (nota1 + nota2 + nota3) / 3;

    if(promedio >= 3){
        printf("El estudiante ha ganado la materia con un promedio de %.2f\n", promedio);
    }else{
        printf("El estudiante ha perdido la materia con un promedio de %.2f\n", promedio);
    }

    return 0;
}