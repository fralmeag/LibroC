/*47. Escribir una función que calcule la distancia entre dos puntos en un plano 2D y retorne el resultado. */

#include <stdio.h>
#include <math.h>

float distancia(float x1, float y1, float x2, float y2){

    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));

}

int main(){

    float x1, y1, x2, y2;

    printf("Ingrese las coordenadas del primer punto: ");
    scanf("%f %f", &x1,&y1);


    printf("Ingrese las coordenadas del segundo punto: ");
    scanf("%f %f", &x2,&y2);

    printf("\nLa distancia entre los dos puntos es: %f", distancia(x1,y1,x2,y2));

    return 0;
}
