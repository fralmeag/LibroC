/*10. Crear un archivo de registros médicos de pacientes (historia clínica). Escribir un programa para agregar nuevos registros de pacientes con sus datos personales y tipo de seguro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    char genero[20];
    char tipoSeguro[20];
} Paciente;

void agregarRegistro() {
    FILE *archivo = fopen("registros_medicos.txt", "a"); 
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Paciente paciente;

    printf("Ingrese el nombre del paciente: ");
    fgets(paciente.nombre, sizeof(paciente.nombre), stdin);
    paciente.nombre[strcspn(paciente.nombre, "\n")] = 0;

    printf("Ingrese la edad del paciente: ");
    scanf("%d", &paciente.edad);
    while (getchar() != '\n');

    printf("Ingrese el género del paciente (Masculino/Femenino): ");
    fgets(paciente.genero, sizeof(paciente.genero), stdin);
    paciente.genero[strcspn(paciente.genero, "\n")] = 0; 

    printf("Ingrese el tipo de seguro (Público/Privado/Ninguno): ");
    fgets(paciente.tipoSeguro, sizeof(paciente.tipoSeguro), stdin);
    paciente.tipoSeguro[strcspn(paciente.tipoSeguro, "\n")] = 0; 
    
    fprintf(archivo, "Nombre: %s\n", paciente.nombre);
    fprintf(archivo, "Edad: %d\n", paciente.edad);
    fprintf(archivo, "Género: %s\n", paciente.genero);
    fprintf(archivo, "Tipo de Seguro: %s\n", paciente.tipoSeguro);
    fprintf(archivo, "---------------------------------\n");

    fclose(archivo); 

    printf("Registro agregado con éxito.\n");
}

int main() {
    int opcion;

    printf("=== Sistema de Registros Médicos ===\n");

    do {
        printf("\n1. Agregar un nuevo registro\n");
        printf("2. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                agregarRegistro();
                break;
            case 2:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Inténtelo nuevamente.\n");
        }
    } while (opcion != 2);

    return 0;
}
