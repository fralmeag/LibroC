/*3.Desarrollar una funci�n que retorne el �rea de un c�rculo a partir de un radio pasado como par�metro. */

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
