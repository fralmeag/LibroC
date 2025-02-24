/*12. Desarrollar un programa para validar información de una agenda de contactos guardada en archivo de registros y generar informe de datos faltantes.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nombre[50];
    char telefono[20];
    char direccion[100];
} Contacto;

int estaVacio(const char *campo) {
    if (campo == NULL || strlen(campo) == 0) {
        return 1;
    }

    for (int i = 0; i < strlen(campo); i++) {
        if (!isspace(campo[i])) {
            return 0; 
        }
    }

    return 1;
}

void validarContactos(const char *nombreArchivo, const char *nombreInforme) {
    FILE *archivo = fopen(nombreArchivo, "r");
    FILE *informe = fopen(nombreInforme, "w");

    if (!archivo) {
        printf("Error al abrir el archivo de contactos.\n");
        if (informe) fclose(informe);
        return;
    }

    if (!informe) {
        printf("Error al abrir el archivo de informe.\n");
        fclose(archivo);
        return;
    }

    char linea[200];
    int lineaNum = 1;

    fprintf(informe, "Informe de contactos con datos faltantes:\n");
    fprintf(informe, "=========================================\n");

    while (fgets(linea, sizeof(linea), archivo)) {
        Contacto contacto = {"", "", ""}; 
        char *token;
        int contador = 0;
        linea[strcspn(linea, "\n")] = 0;
        token = strtok(linea, ",");
        
        while (token != NULL) {
            while (*token == ' ') token++;
            token[strcspn(token, "\n")] = 0; 

            if (contador == 0) {
                if (strlen(token) > 0) strcpy(contacto.nombre, token);
            } else if (contador == 1) {
                if (strlen(token) > 0) strcpy(contacto.telefono, token);
            } else if (contador == 2) {
                if (strlen(token) > 0) strcpy(contacto.direccion, token);
            }

            token = strtok(NULL, ",");
            contador++;
        }

        fprintf(informe, "Contacto %d:\n", lineaNum);
        
        if (estaVacio(contacto.nombre)) {
            fprintf(informe, "  Nombre: No especificado\n");
        } else {
            fprintf(informe, "  Nombre: %s\n", contacto.nombre);
        }

        if (estaVacio(contacto.telefono)) {
            fprintf(informe, "  Teléfono: No especificado\n");
        } else {
            fprintf(informe, "  Teléfono: %s\n", contacto.telefono);
        }

        if (estaVacio(contacto.direccion)) {
            fprintf(informe, "  Dirección: No especificado\n");
        } else {
            fprintf(informe, "  Dirección: %s\n", contacto.direccion);
        }

        fprintf(informe, "\n");

        lineaNum++;
    }

    fclose(archivo);
    fclose(informe);

    printf("Validación completada. Informe guardado en '%s'.\n", nombreInforme);
}

int main() {
    const char *nombreArchivo = "agenda_contactos.txt";
    const char *nombreInforme = "informe_contactos.txt";

    validarContactos(nombreArchivo, nombreInforme);

    return 0;
}











