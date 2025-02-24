/*6. Desarrollar un programa que lea desde un archivo los registros de temperaturas de diferentes ciudades durante una semana y muestre promedio semanal de cada ciudad. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_CIUDADES 100
#define MAX_NOMBRE 50
#define DIAS_SEMANA 7

typedef struct {
    char nombre[MAX_NOMBRE];
    float temperaturas[DIAS_SEMANA];
} Ciudad;

void calcularPromedios(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return;
    }

    Ciudad ciudades[MAX_CIUDADES];
    int numCiudades = 0;

    while (fscanf(archivo, "%s %f %f %f %f %f %f %f", 
                  ciudades[numCiudades].nombre,
                  &ciudades[numCiudades].temperaturas[0],
                  &ciudades[numCiudades].temperaturas[1],
                  &ciudades[numCiudades].temperaturas[2],
                  &ciudades[numCiudades].temperaturas[3],
                  &ciudades[numCiudades].temperaturas[4],
                  &ciudades[numCiudades].temperaturas[5],
                  &ciudades[numCiudades].temperaturas[6]) == 8) {
        numCiudades++;
        
        if (numCiudades >= MAX_CIUDADES) {
            printf("Se alcanzó el límite máximo de ciudades (%d).\n", MAX_CIUDADES);
            break;
        }
    }

    fclose(archivo);

    printf("Promedio semanal de temperaturas por ciudad:\n");
    printf("============================================\n");

    for (int i = 0; i < numCiudades; i++) {
        float suma = 0.0;
        
        for (int j = 0; j < DIAS_SEMANA; j++) {
            suma += ciudades[i].temperaturas[j];
        }
        
        float promedio = suma / DIAS_SEMANA;
        printf("Ciudad: %s, Promedio: %.2f°C\n", ciudades[i].nombre, promedio);
    }
}

int main() {
    const char* nombreArchivo = "temperaturas.txt";
    calcularPromedios(nombreArchivo);

    return 0;
}
