/*34. Desarrollar una lista doblemente enlazada para representar eventos en un calendario mediante un struct Evento con fecha, descripción y hora.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Evento{
    int fecha;
    char descripcion[100];
    int hora;
    struct Evento *siguiente;
    struct Evento *anterior;
}Evento;

Evento *crearEvento(int fecha, char descripcion[100], int hora){
    Evento *nuevoEvento = (Evento*)malloc(sizeof(Evento));
    nuevoEvento->fecha = fecha;
    strcpy(nuevoEvento->descripcion, descripcion);
    nuevoEvento->hora = hora;
    nuevoEvento->siguiente = NULL;
    nuevoEvento->anterior = NULL;
    
    return nuevoEvento;
}

void insertarEvento(Evento **lista, Evento *nuevoEvento){
    if(*lista == NULL){
        *lista = nuevoEvento;
    }else{
        Evento *aux = *lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
 
        aux->siguiente = nuevoEvento;
        nuevoEvento->anterior = aux;
    }
}

void mostrarEventos(Evento *lista){
    Evento *aux = lista;
 
    while(aux != NULL){
        printf("Fecha: %d\n", aux->fecha);
        printf("Descripcion: %s\n", aux->descripcion);
        printf("Hora: %d\n", aux->hora);
        printf("\n");
        aux = aux->siguiente;
    }
}

int main(){
    Evento *lista = NULL;
    Evento *evento1 = crearEvento(20210101, "Evento 1", 1000);
    Evento *evento2 = crearEvento(20210102, "Evento 2", 1100);
    Evento *evento3 = crearEvento(20210103, "Evento 3", 1200);
 
    insertarEvento(&lista, evento1);
    insertarEvento(&lista, evento2);
    insertarEvento(&lista, evento3);
 
    mostrarEventos(lista);
 
    return 0;
}               