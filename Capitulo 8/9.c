/*9.Desarrollar un programa que lea información de N estudiantes desde un archivo de registros con
nombre, nota1, nota2, y guarde en otro archivo solo aprobados.*/


#include <stdio.h>

typedef struct{

    char nombre[50];
    float nota1, nota2;

} Estudiante;

void aprobados(){

    FILE *entrada = fopen("estudiantes.txt", "r");
    FILE *salida = fopen("aprobados.txt", "w");

    if(entrada == NULL){

        printf("ERROR: No se pudo abrir el archivo estudiantes.");
        return;
    }

    if(salida == NULL){

        printf("ERROR: No se pudo abrir el archivo aprobados.");
        return;
    }

    Estudiante estudiante;

    while(fscanf(entrada, "%s %f %f", estudiante.nombre, &estudiante.nota1, &estudiante.nota2) == 3){

        float promedio = (estudiante.nota1 + estudiante.nota2) / 2.0;

        if(promedio >= 3.0){

            fprintf(salida, "%s %.2f\n", estudiante.nombre, promedio);
        }
    }

    fclose(entrada);
    fclose(salida);

    printf("Los estudiantes aprobados se guardaron en el archivo aprobados");

}

int main(){

    aprobados();

    return 0;

}
