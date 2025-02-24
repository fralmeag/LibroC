/*38. Escribir un programa que dado el monto de una compra solicite al usuario si desea descuento por pronto pago. Si el descuento se elige, rebajar 10% si la compra es mayor a $10000, 20% si es mayor a $20000 ó 30% si es mayor a $50000. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float monto;
    char descuento;

    printf("Ingrese el monto de la compra: ");
    scanf("%f", &monto);
    printf("Desea descuento por pronto pago? (s/n): ");
    scanf(" %c", &descuento);

    if(descuento == 's' || descuento == 'S'){
        if(monto > 50000){
            monto = monto - (monto * 0.3);
        }else if(monto > 20000){
            monto = monto - (monto * 0.2);
        }else if(monto > 10000){
            monto = monto - (monto * 0.1);
        }
    }
    printf("El monto a pagar es: %.2f\n", monto);
    
    return 0;
}