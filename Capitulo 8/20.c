/*20. Desarrollar una aplicación que abra el archivo de registros con las películas de un negocio de DVD. Realizar búsquedas por título y listar en pantalla el stock disponible de ese título.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITULO 100

typedef struct {
    char titulo[MAX_TITULO];  
    int stock;               
} Pelicula;

void convertirAMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void crearArchivoBinario(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb"); 

    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return;
    }

    Pelicula peliculas[] = {
        {"El Padrino", 10},
        {"Titanic", 5},
        {"Avatar", 8},
        {"Inception", 7},
        {"The Dark Knight", 6}
    };

    int cantidadPeliculas = sizeof(peliculas) / sizeof(Pelicula);

    fwrite(&cantidadPeliculas, sizeof(int), 1, archivo);

    for (int i = 0; i < cantidadPeliculas; i++) {
        fwrite(&peliculas[i], sizeof(Pelicula), 1, archivo);
    }

    fclose(archivo); 
    printf("Archivo binario creado exitosamente.\n");
}

void mostrarStock(const char *nombreArchivo, const char *tituloBuscado) {
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    int cantidadPeliculas;
    
    fread(&cantidadPeliculas, sizeof(int), 1, archivo);

    Pelicula pelicula;
    
    int encontrado = 0;
    char tituloBuscadoMinusculas[MAX_TITULO];
    
    strcpy(tituloBuscadoMinusculas, tituloBuscado);
    convertirAMinusculas(tituloBuscadoMinusculas);

    for (int i = 0; i < cantidadPeliculas; i++) {
        fread(&pelicula, sizeof(Pelicula), 1, archivo);


        char tituloArchivoMinusculas[MAX_TITULO];
        strcpy(tituloArchivoMinusculas, pelicula.titulo);
        convertirAMinusculas(tituloArchivoMinusculas);

        if (strcmp(tituloArchivoMinusculas, tituloBuscadoMinusculas) == 0) {
            printf("Título: %s\n", pelicula.titulo);
            printf("Stock disponible: %d\n", pelicula.stock);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Película '%s' no encontrada en el archivo.\n", tituloBuscado);
    }

    fclose(archivo); 
}

void listarPeliculas(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return;
    }

    int cantidadPeliculas;
    fread(&cantidadPeliculas, sizeof(int), 1, archivo);

    Pelicula pelicula;

    printf("\nListado de películas disponibles:\n");
    for (int i = 0; i < cantidadPeliculas; i++) {
        fread(&pelicula, sizeof(Pelicula), 1, archivo); 
        printf("Título: %s, Stock: %d\n", pelicula.titulo, pelicula.stock);
    }

    fclose(archivo); 
}

int main() {
    const char *nombreArchivo = "peliculas.dat";

    crearArchivoBinario(nombreArchivo);

    int opcion;
    char tituloBuscado[MAX_TITULO];

    do {
        printf("\nMenú de opciones:\n");
        printf("1. Listar todas las películas\n");
        printf("2. Buscar película por título\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                listarPeliculas(nombreArchivo); 
                break;

            case 2:
                printf("Ingrese el título de la película para verificar el stock: ");
                fgets(tituloBuscado, sizeof(tituloBuscado), stdin);
                tituloBuscado[strcspn(tituloBuscado, "\n")] = '\0';
                mostrarStock(nombreArchivo, tituloBuscado); 
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }

    } while (opcion != 3);

    return 0;
}


