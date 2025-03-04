/*3. Escribir un programa que aumente en 10% el salario de los empleados mayores de 45 años. Guardar en otro archivo resultado.*/


#include <stdio.h>

typedef struct{

    int codigo;
    char nombre[50];
    float salario;
    int edad;

} Empleado;

void agregar(){

    FILE *archivo = fopen("Empleados1.txt", "a");

    if(archivo == NULL){
        printf("ERROR: No se pudo abrir el archivo.");
        return;
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

    fprintf(archivo, "%d %s %f %d\n", empleado.codigo, empleado.nombre, empleado.salario, empleado.edad);

    fclose(archivo);

    printf("\nSe agrego el empleado al archivo.");
}

void mostrar(){

    FILE *archivo = fopen("Empleados1.txt", "r");

    if(archivo == NULL){
        printf("Aun no hay empleados registrados en el archivo.");
        return;
    }

    Empleado empleado;

    while(fscanf(archivo, "%d %s %f %d", &empleado.codigo, empleado.nombre, &empleado.salario, &empleado.edad)== 4){
        printf("Codigo: %d, Nombre: %s, Salario: %.2f, Edad: %d\n", empleado.codigo, empleado.nombre, empleado.salario, empleado.edad);
    }

    fclose(archivo);

}

void aumento(){

    FILE *archivo = fopen("Empleados1.txt", "r");
    FILE *nuevo = fopen("aumentos.txt", "w");

    if(archivo == NULL || nuevo == NULL){
        printf("ERROR: No se pudieron abrir los archivos.");
        return;
    }

    Empleado empleado;

    while(fscanf(archivo, "%d %s %f %d", &empleado.codigo, empleado.nombre, &empleado.salario, &empleado.edad)== 4){
        if(empleado.edad > 45){
            empleado.salario = empleado.salario + (0.1 * empleado.salario);
        }
        fprintf(nuevo, "%d %s %f %d\n", empleado.codigo, empleado.nombre, empleado.salario, empleado.edad);
    }

    fclose(archivo);
    fclose(nuevo);
    printf("Aumentos de salario completos.");

}

int main(){

    int opcion;

    do{
        printf("\nMenu:\n");
        printf("1. Agregar Empleado\n");
        printf("2. Mostrar Empleados\n");
        printf("3.Aumento de salario a mayores de 45 años\n");
        printf("4.Salir\n");
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
            aumento();
            break;
        case 4:
            printf("Saliendo...");
            break;
        default:
            printf("Opcion no valida\n");

        }
    } while(opcion != 4);

    return 0;

}
