/*6. Leer números hasta ingresar -99 y mostrar el promedio usando ciclo while*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, suma = 0, cont = 0;
    float promedio;
   
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    
    while(num != -99){
        suma += num;
        cont++;
        printf("Ingrese un numero: ");
        scanf("%d", &num);
    }
    
    promedio = (float)suma / cont;
    printf("El promedio es: %.2f\n", promedio);
    
    return 0;
}