/*36. Declarar un array para almacenar puntajes de jugadores de un equipo mediante un typedef Puntos. Ordenar puntajes de mayor a menor.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Puntos{
    int puntaje;
    struct Puntos *siguiente;
    struct Puntos *anterior;
}Puntos;

Puntos *crearPuntos(int puntaje){
    Puntos *nuevoPuntaje = (Puntos*)malloc(sizeof(Puntos));
    nuevoPuntaje->puntaje = puntaje;
    nuevoPuntaje->siguiente = NULL;
    nuevoPuntaje->anterior = NULL;
    
    return nuevoPuntaje;
}

void insertarPuntaje(Puntos **lista, Puntos *nuevoPuntaje){
    if(*lista == NULL){
        *lista = nuevoPuntaje;
    }else{
        Puntos *aux = *lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
 
        aux->siguiente = nuevoPuntaje;
        nuevoPuntaje->anterior = aux;
    }
}

void mostrarPuntajes(Puntos *lista){
    Puntos *aux = lista;
 
    while(aux != NULL){
        printf("Puntaje: %d\n", aux->puntaje);
        aux = aux->siguiente;
    }
}

void ordenarPuntajes(Puntos **lista){
    Puntos *aux = *lista;
    Puntos *aux2 = *lista;
    int temp;
    
    while(aux != NULL){
        while(aux2 != NULL){
            if(aux->puntaje > aux2->puntaje){
                temp = aux->puntaje;
                aux->puntaje = aux2->puntaje;
                aux2->puntaje = temp;
            }
            aux2 = aux2->siguiente;
        }
        aux = aux->siguiente;
        aux2 = *lista;
    }
}

int main(){
    Puntos *lista = NULL;
    Puntos *puntaje1 = crearPuntos(100);
    Puntos *puntaje2 = crearPuntos(200);
    Puntos *puntaje3 = crearPuntos(300);
 
    insertarPuntaje(&lista, puntaje1);
    insertarPuntaje(&lista, puntaje2);
    insertarPuntaje(&lista, puntaje3);
 
    printf("Puntajes sin ordenar:\n");
    mostrarPuntajes(lista);
    
    ordenarPuntajes(&lista);
    
    printf("\n");
    
    printf("Puntajes ordenados:\n");
    mostrarPuntajes(lista);
 
    return 0;
}