/*15. Desarrollar una agenda telefónica que almacene los contactos en un archivo de registros ordenados
alfabéticamente para búsqueda eficiente.*/

#include <stdio.h>
#include <string.h>

typedef struct{
    char nombre[50];
    char telefono[15];
}Contacto;

void agregarContacto(){

    FILE *archivo = fopen("agenda.txt", "a+");

    if(archivo == NULL){

        printf("ERROR: No se pudo abrir el archivo.");
        return;
    }

    Contacto nuevo;

    printf("Ingrese el nombre: ");
    getchar();
    fgets(nuevo.nombre, 50, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = 0;

    printf("Ingrese el numero de telefono: ");
    fgets(nuevo.telefono, 15, stdin);
    nuevo.telefono[strcspn(nuevo.telefono, "\n")] = 0;

    fprintf(archivo, "%s,%s\n", nuevo.nombre, nuevo.telefono);
    fclose(archivo);

    ordenarContacto();
    printf("Contacto agregado.");
}

void mostrarContacto(){

    FILE *archivo = fopen("agenda.txt", "r");

    if(archivo == NULL){

        printf("No hay contactos registrados.");
        return;
    }

    Contacto contacto;

    while(fscanf(archivo, " %49[^,],%14[^\n]" , contacto.nombre, contacto.telefono) == 2){
        printf("Nombre: %s, Telefono: %s\n", contacto.nombre, contacto.telefono);
    }

    fclose(archivo);

}

void buscarContacto(){

    FILE *archivo = fopen("agenda.txt", "r");

    if(archivo == NULL){
        printf("No hay contactos registrados.");
        return;
    }

    char buscado[50];

    printf("Ingrese el nombre a buscar: ");
    getchar();
    fgets(buscado, 50, stdin);
    buscado[strcspn(buscado, "\n")] = 0;

    Contacto contacto;

    int encontrado = 0;

    while(fscanf(archivo, " %49[^,],%14[^\n]", contacto.nombre, contacto.telefono) == 2){

        if(strcmp(contacto.nombre, buscado) == 0){

            printf("Telefono de %s: %s\n", contacto.nombre, contacto.telefono);
            encontrado = 1;
            break;
        }
    }

    if(encontrado == 0){

        printf("Contacto no encontrado\n");
    }

    fclose(archivo);

}

void ordenarContacto(){

    FILE *archivo = fopen("agenda.txt", "r");

    if(archivo == NULL){

        return;
    }

    Contacto contactos[100];
    int contador = 0;

    while(fscanf(archivo, " %49[^,],%14[^\n]", contactos[contador].nombre, contactos[contador].telefono) == 2){
        contador++;
    }

    fclose(archivo);

    for(int i = 0; i < contador-1; i++){

        for(int j = i+1; j < contador; j++){

            if(strcmp(contactos[i].nombre, contactos[j].nombre) > 0){
                Contacto temp = contactos[i];
                contactos[i] = contactos[j];
                contactos[j] = temp;
            }
        }
    }

    archivo = fopen("agenda.txt", "w");

    for(int i = 0; i < contador; i++){

        fprintf(archivo, "%s,%s\n", contactos[i].nombre, contactos[i].telefono);

    }

    fclose(archivo);
}

int main(){

    int opcion;

    do{
        printf("\nMENU\n");
        printf("1. Agregar contacto\n");
        printf("2. Buscar contacto\n");
        printf("3. Mostrar contactos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

        case 1:
            agregarContacto();
            break;
        case 2:
            buscarContacto();
            break;
        case 3:
            mostrarContacto();
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
