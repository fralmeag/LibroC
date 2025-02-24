/*8. Desarrollar una función que dadas las coordenadas (x,y) de un punto, retorne a qué cuadrante pertenece.*/

#include <stdio.h>
#include <stdlib.h>

int cuadrante(int x, int y){
    if(x>0 && y>0){
        return 1;
    }else if(x<0 && y>0){
        return 2;
    }else if(x<0 && y<0){
        return 3;
    }else if(x>0 && y<0){
        return 4;
    }else{
        return 0;
    }
}

int main(){
    int x, y;
    
    printf("Ingrese las coordenadas del punto (x,y): ");
    scanf("%d %d", &x, &y);
    
    printf("El punto (%d,%d) pertenece al cuadrante %d\n", x, y, cuadrante(x, y));
    
    return 0;
}