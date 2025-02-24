/*6. Desarrollar struct Libro con ISBN, título, autor y precio. Leer N libros e imprimir los con precio mayor a 100.*/

#include <stdio.h>
#include <stdlib.h>

struct Libro{
    int ISBN;
    char titulo[20];
    char autor[20];
    float precio;
};

int main(){
    int N;
 
    printf("Ingrese la cantidad de libros: ");
    scanf("%d", &N);
 
    struct Libro libros[N];
 
    for(int i = 0; i < N; i++){
        printf("Ingrese el ISBN del libro %d: ", i+1);
        scanf("%d", &libros[i].ISBN);
        printf("Ingrese el título del libro %d: ", i+1);
        scanf("%s", libros[i].titulo);
        printf("Ingrese el autor del libro %d: ", i+1);
        scanf("%s", libros[i].autor);
        printf("Ingrese el precio del libro %d: ", i+1);
        scanf("%f", &libros[i].precio);
    }
 
    printf("\nLibros con precio mayor a 100:\n");

    for(int i = 0; i < N; i++){
        if(libros[i].precio > 100){
            printf("ISBN: %d\n", libros[i].ISBN);
            printf("Título: %s\n", libros[i].titulo);
            printf("Autor: %s\n", libros[i].autor);
            printf("Precio: %.2f\n", libros[i].precio);
        }
    }
 
    return 0;
}