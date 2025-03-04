/*5.Crear un archivo con datos de películas como título, duración, género.
Escribir los datos de todas las películas de acción al archivo resultado.txt*/

#include <stdio.h>
#include <string.h>

typedef struct{

    char titulo[50];
    int duracion;
    char genero[50];

} Pelicula;

void agregar(){

    FILE *archivo = fopen("resultado.txt", "a");

    if(archivo == NULL){
        printf("ERROR: No se pudo abrir el archivo.");
        return;
    }

    Pelicula pelis;

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    fgets(pelis.titulo,sizeof(pelis.titulo),stdin);
    pelis.titulo[strcspn(pelis.titulo, "\n")] = 0;


    printf("Ingrese la duracion en minutos: ");
    scanf("%d", &pelis.duracion);

    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    fgets(pelis.genero,sizeof(pelis.genero),stdin);
    pelis.genero[strcspn(pelis.genero, "\n")] = 0;

    if(strcmp(pelis.genero,"accion") == 0){

        fprintf(archivo, "%s %d %s\n", pelis.titulo, pelis.duracion, pelis.genero);
        printf("\nSe agrego la pelicula de accion al archivo resultado.txt\n");

    }
    else{
        printf("\nLa pelicula no es de accion, por ende ,no se guardara en el archivo resultado.txt\n");
    }


    fclose(archivo);


}

void mostrar(){

    FILE *archivo = fopen("resultado.txt", "r");

    if(archivo == NULL){
        printf("Aun no hay peliculas de accion registradas en el archivo.");
        return;
    }

    Pelicula pelis;
    char linea[150];

    while(fgets(linea,sizeof(linea),archivo)){
        sscanf(linea, "%49[^0-9] %d %49s", pelis.titulo, &pelis.duracion, pelis.genero);
        pelis.titulo[strcspn(pelis.titulo,"0123456789")] = 0;
        printf("Titulo: %s, Duracion: %d, Genero: %s\n", pelis.titulo, pelis.duracion, pelis.genero);
    }

    fclose(archivo);

}

int main(){

    int opcion;

    do{
        printf("\nMenu:\n");
        printf("1. Agregar Pelicula\n");
        printf("2. Mostrar Peliculas\n");
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

