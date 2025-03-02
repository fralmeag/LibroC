/*5.Crear struct Persona y mostrar todos sus datos. Crear función para inicializar datos leídos por teclado.*/

#include <stdio.h>

typedef struct{

    char nombre[50];
    int edad;
    float altura;
}Persona;


void escribirPersona(Persona *p){

    printf("Nombre: ");
    scanf("%s", p->nombre);

    printf("Edad: ");
    scanf("%d", &p->edad);

    printf("Altura: ");
    scanf("%f", &p->altura);
}

void mostrarDatos(Persona person){

    printf("\nNombre: %s", person.nombre);
    printf("\nEdad: %d", person.edad);
    printf("\nAltura: %.2f", person.altura);

}

int main(){

    Persona person;

    escribirPersona(&person);

    mostrarDatos(person);

    return 0;
}
