/*22. Desarrollar agenda telefónica ordenando por nombre structs de Contacto con información personal de propietario.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[50];
    char apellido[50];
    char telefono[50];
    char direccion[50];
}Contacto;

void ordenar(Contacto *agenda, int n){
    Contacto aux;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(strcmp(agenda[j].nombre, agenda[j+1].nombre)>0){
                aux = agenda[j];
                agenda[j] = agenda[j+1];
                agenda[j+1] = aux;
            }
        }
    }
}

int main(){
    int n;
    
    printf("Ingrese la cantidad de contactos: ");
    scanf("%d", &n);
    getchar();
    
    Contacto *agenda = (Contacto*)malloc(n*sizeof(Contacto));
    
    for(int i=0; i<n; i++){
        printf("Ingrese el nombre del contacto %d: ", i+1);
        fgets(agenda[i].nombre, 50, stdin);
        agenda[i].nombre[strcspn(agenda[i].nombre, "\n")] = 0; 
        printf("Ingrese el apellido del contacto %d: ", i+1);
        fgets(agenda[i].apellido, 50, stdin);
        agenda[i].apellido[strcspn(agenda[i].apellido, "\n")] = 0; 
        printf("Ingrese el telefono del contacto %d: ", i+1);
        fgets(agenda[i].telefono, 50, stdin);
        agenda[i].telefono[strcspn(agenda[i].telefono, "\n")] = 0; 
        printf("Ingrese la direccion del contacto %d: ", i+1);
        fgets(agenda[i].direccion, 50, stdin);
        agenda[i].direccion[strcspn(agenda[i].direccion, "\n")] = 0; 
    }
    
    ordenar(agenda, n);
    
    for(int i=0; i<n; i++){
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Apellido: %s\n", agenda[i].apellido);
        printf("Telefono: %s\n", agenda[i].telefono);
        printf("Direccion: %s\n", agenda[i].direccion);
    }
    
    free(agenda);
    
    return 0;
}