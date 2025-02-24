/*10. Crear struct Triángulo con struct Punto como campos x,y. Calcular tipo de triángulo según 3 puntos.*/

#include <stdio.h>
#include <math.h>

struct Punto {
    float x;
    float y;
};

struct Triangulo {
    struct Punto a;
    struct Punto b;
    struct Punto c;
};

float distancia(struct Punto a, struct Punto b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    struct Triangulo t;
    float l1, l2, l3;

    printf("Introduce las coordenadas del punto A: ");
    scanf("%f %f", &t.a.x, &t.a.y);
    printf("Introduce las coordenadas del punto B: ");
    scanf("%f %f", &t.b.x, &t.b.y);
    printf("Introduce las coordenadas del punto C: ");
    scanf("%f %f", &t.c.x, &t.c.y);

    l1 = distancia(t.a, t.b);
    l2 = distancia(t.b, t.c);
    l3 = distancia(t.c, t.a);

    if (l1 == l2 && l2 == l3) {
        printf("Triangulo equilatero\n");
    } else if (l1 == l2 || l2 == l3 || l3 == l1) {
        printf("Triangulo isosceles\n");
    } else {
        printf("Triangulo escaleno\n");
    }

    return 0;
}