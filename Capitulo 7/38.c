/*38. Crear tipo de dato Vector para almacenar arrays de 3 floats. Sumar dos vectores sobrecargando el operador + entre dos structs Vector.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector{
    float x;
    float y;
    float z;
}Vector;

Vector addVectors(Vector a, Vector b){
    Vector c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
 
    return c;
}

int main(){
    printf("Ingrese los valores del primer vector\n");
    Vector a;
    printf("x: ");
    scanf("%f", &a.x);
    printf("y: ");
    scanf("%f", &a.y);
    printf("z: ");
    scanf("%f", &a.z);

    printf("Ingrese los valores del segundo vector\n");
    Vector b;
    printf("x: ");
    scanf("%f", &b.x);
    printf("y: ");
    scanf("%f", &b.y);
    printf("z: ");
    scanf("%f", &b.z);

    Vector c = addVectors(a, b);

    printf("El resultado de la suma de los vectores es: (%.2f, %.2f, %.2f)\n", c.x, c.y, c.z);

    return 0;
}