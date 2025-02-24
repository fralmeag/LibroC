/*30. Declarar tres structs Punto, Circulo y Cilindro, relacionándolos de manera que Círculo y Cilindro utilicen el struct Punto.*/

#include <stdio.h>
#include <stdlib.h>

struct Punto{
    float x;
    float y;
};

struct Circulo{
    struct Punto centro;
    float radio;
};

struct Cilindro{
    struct Circulo base;
    float altura;
};

int main(){
    struct Punto punto;
    struct Circulo circulo;
    struct Cilindro cilindro;

    return 0;
}