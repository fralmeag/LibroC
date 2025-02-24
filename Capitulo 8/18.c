/*18. Desarrollar un sistema de reserva de pasajes aéreos leyendo las reservas disponibles desde un archivo. El programa debe permitir hacer reservas y actualizar disponibilidad en el archivo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VUELOS 5

typedef struct {
    int codigoVuelo;        
    int asientosDisponibles; 
    int asientosReservados; 
} Reserva;

void mostrarVuelos(Reserva *reservas, int cantidad) {
    printf("Vuelos disponibles:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("Vuelo %d: %d asientos disponibles, %d asientos reservados\n", 
            reservas[i].codigoVuelo, reservas[i].asientosDisponibles, reservas[i].asientosReservados);
    }
}

void hacerReserva(Reserva *reservas, int cantidad, int codigoVuelo, int asientos) {
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i].codigoVuelo == codigoVuelo) {
            if (reservas[i].asientosDisponibles >= asientos) {
                reservas[i].asientosReservados += asientos;
                reservas[i].asientosDisponibles -= asientos;
                printf("Reserva realizada: %d asientos para el vuelo %d\n", asientos, codigoVuelo);
            } else {
                printf("No hay suficientes asientos disponibles para el vuelo %d.\n", codigoVuelo);
            }
            return;
        }
    }
    printf("Vuelo con código %d no encontrado.\n", codigoVuelo);
}

void guardarReservas(Reserva *reservas, int cantidad, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo) {
        fwrite(reservas, sizeof(Reserva), cantidad, archivo);
        fclose(archivo);
        printf("Cambios guardados en el archivo.\n");
    } else {
        printf("Error al guardar el archivo.\n");
    }
}

void cargarReservas(Reserva *reservas, int cantidad, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");

    if (archivo) {
        fread(reservas, sizeof(Reserva), cantidad, archivo);
        fclose(archivo);
    } else {
        for (int i = 0; i < cantidad; i++) {
            reservas[i].codigoVuelo = 101 + i;
            reservas[i].asientosDisponibles = 100 + (i * 50); 
            reservas[i].asientosReservados = 0;
        }
        
        printf("Archivo no encontrado, inicializando con valores predeterminados.\n");
    }
}

int main() {
    const char *nombreArchivo = "reservas.dat";
    Reserva reservas[MAX_VUELOS];

    cargarReservas(reservas, MAX_VUELOS, nombreArchivo);

    int opcion, codigoVuelo, asientos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Mostrar vuelos disponibles\n");
        printf("2. Realizar una reserva\n");
        printf("3. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarVuelos(reservas, MAX_VUELOS);
                break;
            case 2:
                printf("Ingrese el codigo del vuelo: ");
                scanf("%d", &codigoVuelo);
                printf("Ingrese el numero de asientos a reservar: ");
                scanf("%d", &asientos);
                hacerReserva(reservas, MAX_VUELOS, codigoVuelo, asientos);
                guardarReservas(reservas, MAX_VUELOS, nombreArchivo);
                break;
            case 3:
                guardarReservas(reservas, MAX_VUELOS, nombreArchivo);
                printf("Saliendo del programa.\n");
                return 0;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
                break;
        }
    }

    return 0;
}
