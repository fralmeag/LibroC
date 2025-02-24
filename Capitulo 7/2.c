/*2. Definir un struct Alumno y un array con 3 alumnos. Inicializar y mostrar los datos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Alumno;

int main() {
    Alumno alumnos[3] = {
        {"Juan", 20, 8.5},
        {"Maria", 21, 9.0},
        {"Pedro", 22, 7.0}
    };

    for (int i = 0; i < 3; i++) {
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
        printf("\n");
    }

    return 0;
}