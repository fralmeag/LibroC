/*3.Desarrollar una función que retorne el área de un círculo a partir de un radio pasado como parámetro. */

#include <stdio.h>

float area_circulo(float radio_circulo){

    return radio_circulo * radio_circulo * 3.14;

}

int main(){

    float radio, area;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    area = area_circulo(radio);

    printf("\nEl area del circulo es: %f", area);

    return 0;
}
