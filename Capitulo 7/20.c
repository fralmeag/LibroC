/*20. Declara una Unión para almacenar un int a float g. ¿Cómo cambiarías valores entre int y float?*/

#include <stdio.h>
#include <string.h>

union valores{
    int a;
    float g;
};

int main()
{
    union valores valor;
    valor.a = 5;
 
    printf("El valor de a es: %d\n", valor.a);
    
    valor.g = 5.5;
    
    printf("El valor de g es: %f\n", valor.g);
    
    return 0;
}