/*14. Escribir un programa que abra un archivo de registros con calificaciones de alumnos, calcule el promedio, cuente las notas deficientes y guardar resultado en otro archivo.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUMNOS 100 

typedef struct {
    char nombre[50];
    float calificacion;
} Alumno;

void procesarCalificaciones(const char *archivoEntrada, const char *archivoSalida) {
    FILE *archivo = fopen(archivoEntrada, "r");
    FILE *informe = fopen(archivoSalida, "w");

    if (!archivo) {
        printf("Error al abrir el archivo de calificaciones.\n");
        if (informe) fclose(informe);
        return;
    }

    if (!informe) {
        printf("Error al abrir el archivo de informe.\n");
        fclose(archivo);
        return;
    }

    Alumno alumnos[MAX_ALUMNOS];
    int totalAlumnos = 0;
    float sumaCalificaciones = 0;
    int deficientes = 0;

    while (fscanf(archivo, "%49[^,],%f\n", alumnos[totalAlumnos].nombre, &alumnos[totalAlumnos].calificacion) != EOF) {
        sumaCalificaciones += alumnos[totalAlumnos].calificacion;
        
        if (alumnos[totalAlumnos].calificacion < 6) {
            deficientes++;
        }
        
        totalAlumnos++;
    }

    float promedio = (totalAlumnos > 0) ? sumaCalificaciones / totalAlumnos : 0;
    
    fprintf(informe, "Informe de calificaciones:\n");
    fprintf(informe, "=========================\n");
    fprintf(informe, "Total de alumnos: %d\n", totalAlumnos);
    fprintf(informe, "Promedio de calificaciones: %.2f\n", promedio);
    fprintf(informe, "Número de calificaciones deficientes (menor a 6): %d\n", deficientes);

    fclose(archivo);
    fclose(informe);

    printf("Validación completada. Informe guardado en '%s'.\n", archivoSalida);
}

int main() {
    const char *archivoEntrada = "calificaciones.txt";  
    const char *archivoSalida = "informe_calificaciones.txt";  

    procesarCalificaciones(archivoEntrada, archivoSalida);

    return 0;
}
