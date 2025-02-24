/*28. Desarrollar una lista enlazada de structs Alumno ordenados por promedio. Añadir y eliminar alumnos manteniendo orden.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno{
    char nombre[50];
    float promedio;
    struct Alumno *siguiente;
};

struct Alumno *crearAlumno(char nombre[], float promedio){
    struct Alumno *nuevoAlumno = (struct Alumno*)malloc(sizeof(struct Alumno));
    
    if(nuevoAlumno == NULL){
        printf("Error al reservar memoria para el alumno\n");
        exit(1);
    }
    
    nuevoAlumno->promedio = promedio;
    nuevoAlumno->siguiente = NULL;
    
    for(int i = 0; nombre[i] != '\0'; i++){
        nuevoAlumno->nombre[i] = nombre[i];
    }
    
    return nuevoAlumno;
}

void insertarAlumno(struct Alumno **lista, struct Alumno *nuevoAlumno){
    struct Alumno *actual = *lista;
    struct Alumno *anterior = NULL;
    
    while(actual != NULL && actual->promedio < nuevoAlumno->promedio){
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if(anterior == NULL){
        nuevoAlumno->siguiente = *lista;
        *lista = nuevoAlumno;
    }else{
        anterior->siguiente = nuevoAlumno;
        nuevoAlumno->siguiente = actual;
    }
}

void eliminarAlumno(struct Alumno **lista, char nombre[]){
    struct Alumno *actual = *lista;
    struct Alumno *anterior = NULL;
    
    while(actual != NULL && strcmp(actual->nombre, nombre) != 0){
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if(actual == NULL){
        printf("No se encontró el alumno\n");
        return;
    }
    
    if(anterior == NULL){
        *lista = actual->siguiente;
    }else{
        anterior->siguiente = actual->siguiente;
    }
    
    free(actual);
}

void imprimirLista(struct Alumno *lista){
    struct Alumno *actual = lista;
    
    while(actual != NULL){
        printf("Nombre: %s, Promedio: %.2f\n", actual->nombre, actual->promedio);
        actual = actual->siguiente;
    }
}

int main(){
    struct Alumno *lista = NULL;
    
    struct Alumno *alumno1 = crearAlumno("Juan", 8.5);
    struct Alumno *alumno2 = crearAlumno("Maria", 9.0);
    struct Alumno *alumno3 = crearAlumno("Pedro", 7.0);
    
    insertarAlumno(&lista, alumno1);
    insertarAlumno(&lista, alumno2);
    insertarAlumno(&lista, alumno3);
    
    printf("Lista de alumnos ordenados por promedio:\n");
    imprimirLista(lista);
    
    printf("\nEliminando a Maria\n");
    eliminarAlumno(&lista, "Maria");
    
    printf("\nNueva lista de alumnos ordenados por promedio:\n");
    imprimirLista(lista);
    
    return 0;
}