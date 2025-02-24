/*2. Leer el archivo de empleados, imprimir los datos del empleado con mayor salario y mostrar el promedio de edad.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;         
    char nombre[50];
    int edad;       
    float salario;  
} Empleado;

int leerEmpleados(const char* nombreArchivo, Empleado** empleados) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return 0;
    }

    int count = 0;
    Empleado temp;
    while (fscanf(archivo, "%d %49s %d %f", &temp.id, temp.nombre, &temp.edad, &temp.salario) == 4) {
        count++;
    }

    rewind(archivo);

    *empleados = (Empleado*)malloc(count * sizeof(Empleado));
    for (int i = 0; i < count; i++) {
        fscanf(archivo, "%d %49s %d %f", &(*empleados)[i].id, (*empleados)[i].nombre, &(*empleados)[i].edad, &(*empleados)[i].salario);
    }

    fclose(archivo);
    return count;
}

Empleado empleadoMayorSalario(Empleado* empleados, int n) {
    Empleado mayor = empleados[0];
    for (int i = 1; i < n; i++) {
        if (empleados[i].salario > mayor.salario) {
            mayor = empleados[i];
        }
    }

    return mayor;
}

float promedioEdad(Empleado* empleados, int n) {
    int sumaEdades = 0;
    for (int i = 0; i < n; i++) {
        sumaEdades += empleados[i].edad;
    }
    
    return (float)sumaEdades / n;
}

int main() {
    const char* nombreArchivo = "empleados.txt";
    Empleado* empleados = NULL;
    int numEmpleados = leerEmpleados(nombreArchivo, &empleados);

    if (numEmpleados == 0) {
        printf("No se encontraron empleados en el archivo.\n");
        return 1;
    }

    Empleado mayorSalario = empleadoMayorSalario(empleados, numEmpleados);
    float promedio = promedioEdad(empleados, numEmpleados);

    printf("Empleado con mayor salario:\n");
    printf("ID: %d\n", mayorSalario.id);
    printf("Nombre: %s\n", mayorSalario.nombre);
    printf("Edad: %d\n", mayorSalario.edad);
    printf("Salario: %.2f\n", mayorSalario.salario);

    printf("\nPromedio de edad: %.2f\n", promedio);

    free(empleados);

    return 0;
}
