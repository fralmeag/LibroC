/*36. Desarrollar un programa que lea las coordenadas de dos puntos en el plano cartesiano e indique si los puntos son iguales, si están sobre una recta horizontal o vertical, o ninguna de las anteriores.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float x1, y1, x2, y2;
    
    printf("Ingrese las coordenadas del primer punto (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Ingrese las coordenadas del segundo punto (x2, y2): ");
    scanf("%f %f", &x2, &y2);

    if(x1 == x2 && y1 == y2){
        printf("Los puntos son iguales.\n");
    }else if(x1 == x2){
        printf("Los puntos están sobre una recta vertical.\n");
    }else if(y1 == y2){
        printf("Los puntos están sobre una recta horizontal.\n");
    }else{
        printf("Los puntos no están sobre una recta horizontal ni vertical.\n");
    }

    return 0;
}