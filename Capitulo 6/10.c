/*10. Implementar una función que concatene dos string utilizando punteros y sin usar funciones de biblioteca.*/

#include <stdio.h>
#include <stdlib.h>

void concatenar(char *s1, char *s2, char *s3){
    while(*s1 != '\0'){
        *s3++ = *s1++;
    }
    
    while(*s2 != '\0'){
        *s3++ = *s2++;
    }

    *s3 = '\0';
}

int main(){
    char s1[100], s2[100], s3[200];
    
    printf("Ingrese el primer string: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Ingrese el segundo string: ");
    fgets(s2, sizeof(s2), stdin);

    concatenar(s1, s2, s3);

    printf("El string concatenado es: %s\n", s3);

    return 0;
}