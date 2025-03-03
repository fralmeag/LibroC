/*1.Crear un archivo de registros de empleados con informaci�n como c�digo, nombre, salario y edad, utilizando un struct Empleado.*/

#include <stdio.h>

typedef struct{

    int codigo;
    char nombre[50];
    float salario;
    int edad;

} Empleado;

void agregar(){

    FILE *archivo = fopen("empleados_registro.txt", "ab");

    if(archivo == NULL){
        printf("ERROR: No se pudo abrir el archivo.");
    }

    Empleado empleado;

    printf("Ingrese el codigo: ");
    scanf("%d", &empleado.codigo);

    printf("Ingrese el nombre: ");
    scanf("%s", empleado.nombre);

    printf("Ingrese el salario: ");
    scanf("%f", &empleado.salario);

    printf("Ingrese la edad: ");
    scanf("%d", &empleado.edad);

    fwrite(&empleado, sizeof(Empleado),1,archivo);

    fclose(archivo);

    printf("\nSe agrego el empleado al archivo.");
}

void mostrar(){

    FILE *archivo = fopen("empleados_registro.txt", "rb");

    if(archivo == NULL){
        printf("Aun no hay empleados registrados en el archivo.");
    }

    Empleado empleado;

    while(fread(&empleado, sizeof(Empleado),1,archivo)){
        printf("Codigo: %d, Nombre: %s, Salario: %.2f, Edad: %d\n", empleado.codigo, empleado.nombre, empleado.salario, empleado.edad);
    }

    fclose(archivo);

}

int main(){

    int opcion;

    do{
        printf("\nMenu:\n");
        printf("1. Agregar Empleado\n");
        printf("2. Mostrar Empleados\n");
        printf("3.Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

        case 1:
            agregar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            printf("Saliendo...");
            break;
        default:
            printf("Opcion no valida\n");

        }
    } while(opcion != 3);

    return 0;

}
