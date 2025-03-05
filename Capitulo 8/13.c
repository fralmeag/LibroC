/*13. Crear un sistema bibliotecario que utilice un archivo para registrar libros y préstamos.
Permitir registrar y consultar préstamos vigentes por ISBN de libro o usuario.*/

#include <stdio.h>
#include <string.h>

typedef struct {

    char isbn[20];
    char usuario[50];
    char fecha[11];
} Prestamo;

void registrarPrestamo(){

    FILE *archivo = fopen("prestamos.txt", "a");

    if(archivo == NULL){

        printf("ERROR: No se pudo abrir el archivo");
        return;
    }

    Prestamo prestamo;

    printf("Ingrese el ISBN del libro: ");
    scanf("%s", prestamo.isbn);

    printf("Ingrese el nombre del usuario: ");
    scanf("%s", prestamo.usuario);

    printf("Ingrese la fecha (DD/MM/YYYY): ");
    scanf("%s", prestamo.fecha);

    fprintf(archivo, "%s %s %s\n", prestamo.isbn, prestamo.usuario, prestamo.fecha);
    fclose(archivo);
    printf("\nPrestamo registrado\n");
}

void consultarPorISBN(){

    FILE *archivo = fopen("prestamos.txt", "r");

    if(archivo == NULL){
        printf("No hay registros de prestamos.");
        return;
    }

    char isbnBuscado[20];

    printf("Ingrese el ISBN a consultar: ");
    scanf("%s", isbnBuscado);

    Prestamo prestamo;

    int encontrado = 0;

    while(fscanf(archivo, "%s %s %s", prestamo.isbn, prestamo.usuario, prestamo.fecha) == 3){

        if(strcmp(prestamo.isbn, isbnBuscado) == 0){
            printf("Usuario: %s, Fecha: %s\n", prestamo.usuario, prestamo.fecha);
            encontrado = 1;
        }
    }
    fclose(archivo);

    if(encontrado == 0){

        printf("No se encontraron prestamos con ese ISBN\n");
    }

}

void consultarPorUsuario(){

    FILE *archivo = fopen("prestamos.txt", "r");

    if(archivo == NULL){

        printf("No hay registros de prestamos.");
        return;
    }

    char usuarioBuscado[50];

    printf("Ingrese el nombre del usuario a consultar: ");
    scanf("%s", usuarioBuscado);

    Prestamo prestamo;

    int encontrado = 0;

    while(fscanf(archivo, "%s %s %s", prestamo.isbn, prestamo.usuario, prestamo.fecha) == 3){

        if(strcmp(prestamo.usuario, usuarioBuscado) == 0){

            printf("ISBN %s, Fecha: %s\n", prestamo.isbn, prestamo.fecha);
            encontrado = 1;
        }
    }
    fclose(archivo);

    if(encontrado == 0){
        printf("No se encontraron prestamos para ese usuario.\n");
    }

}

int main(){

    int opcion;

    do{
        printf("\nMENU\n");
        printf("1. Registrar prestamo.\n");
        printf("2. Consultar prestamos por ISBN.\n");
        printf("3. Consultar prestamos por usuario.\n");
        printf("4. Salir.\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

        case 1:
            registrarPrestamo();
            break;
        case 2:
            consultarPorISBN();
            break;
        case 3:
            consultarPorUsuario();
            break;
        case 4:
            printf("Saliendo...");
            break;
        default:
            printf("Opcion no valida.");
        }
    }while(opcion != 4);

    return 0;

}
