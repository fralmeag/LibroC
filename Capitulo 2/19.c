/*19.Realizar un programa que permita ingresar las coordenadas (x,y) de un punto en el plano y determine a qué cuadrante pertenece.*/

#include <stdio.h>

int main(){

    int x, y;

    printf("Ingrese la coordenada en x: ");
    scanf("%d", &x);

    printf("Ingrese la coordenada en y: ");
    scanf("%d", &y);

    if((x > 0) && (y > 0)){
        printf("Primer cuadrante");
    }

    if((x < 0) && (y > 0)){
        printf("Segundo cuadrante");
    }

    if((x < 0) && (y < 0)){
        printf("Tercer cuadrante");
    }

    if((x > 0) && (y < 0)){
        printf("Cuarto cuadrante");
    }

    if((x == 0) && (y == 0)){
        printf("Origen");
    }

    if((x == 0) && (y > 0)){
        printf("Coordenada sobre el eje Y");
    }

    if((x > 0) && (y == 0)){
        printf("Coordenada sobre el eje X");
    }

    return 0;
}
