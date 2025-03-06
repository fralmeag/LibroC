/*6.Crear una función que retorne el siguiente número de una secuencia Fibonacci dado el último número ingresado.
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int last){
    int a = 0, b = 1, c = 1;
    
    while (b <= last) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main(){
    int n;

    printf("Ingrese el ultimo numero de la secuencia Fibonacci: ");
    scanf("%d", &n);

    printf("El siguiente numero de la secuencia Fibonacci es: %d\n", fibonacci(n));
    
    return 0;
}

