/*30. Realizar una función que calcule la distancia entre dos puntos representados por arreglos P1=[x1,y1] y P2=[x2,y2]*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void distancia(float P1[], float P2[]){
    float d;
    
    d = sqrt(pow(P2[0]-P1[0],2)+pow(P2[1]-P1[1],2));
    
    printf("\nLa distancia entre los puntos es: %.3f\n", d);
}

int main(){
    float P1[2], P2[2];
    
    printf("Ingrese las coordenadas del primer punto x y: ");
    scanf("%f %f", &P1[0], &P1[1]);
    
    printf("Ingrese las coordenadas del segundo punto x y: ");
    scanf("%f %f", &P2[0], &P2[1]);
    
    distancia(P1, P2);
    
    return 0;
}
