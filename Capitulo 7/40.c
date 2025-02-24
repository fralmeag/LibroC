/*40. Desarrollar estructura CircularList basada en struct Nodo para representar una lista circular. Incluir funciones para insertar y eliminar nodos.*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

struct CircularList {
    struct Nodo *inicio;
    struct Nodo *fin;
};

struct CircularList *crearLista() {
    struct CircularList *lista = (struct CircularList *)malloc(sizeof(struct CircularList));
    lista->inicio = NULL;
    lista->fin = NULL;
 
    return lista;
}

void insertar(struct CircularList *lista, int dato) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
 
    if (lista->inicio == NULL) {
        lista->inicio = nuevoNodo;
        lista->fin = nuevoNodo;
        nuevoNodo->siguiente = lista->inicio;
    } else {
        lista->fin->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista->inicio;
        lista->fin = nuevoNodo;
    }
}

void eliminar(struct CircularList *lista, int dato) {
    struct Nodo *actual = lista->inicio;
    struct Nodo *anterior = lista->fin;
 
    do {
        if (actual->dato == dato) {
            if (actual == lista->inicio) {
                lista->inicio = lista->inicio->siguiente;
                lista->fin->siguiente = lista->inicio;
            } else if (actual == lista->fin) {
                anterior->siguiente = lista->inicio;
                lista->fin = anterior;
            } else {
                anterior->siguiente = actual->siguiente;
            }
 
            free(actual);
            return;
        }
 
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != lista->inicio);
}

void imprimir(struct CircularList *lista) {
    struct Nodo *actual = lista->inicio;
 
    if (lista->inicio != NULL) {
        do {
            printf("%d ", actual->dato);
            actual = actual->siguiente;
        } while (actual != lista->inicio);
    }
 
    printf("\n");
}

int main() {
    struct CircularList *lista = crearLista();
    
    printf("Ingrese 5 elementos a la lista:\n");
    for (int i = 0; i < 5; i++) {
        int dato;
        scanf("%d", &dato);
        insertar(lista, dato);
    }

    printf("Lista:\n");
    imprimir(lista);

    printf("Ingrese el elemento a eliminar:\n");
    int dato;
    scanf("%d", &dato);
    eliminar(lista, dato);

    printf("Lista:\n");
    imprimir(lista);
    
    return 0;
}