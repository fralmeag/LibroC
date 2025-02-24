/*12. Desarrollar una función que elimine espacios de una cadena de caracteres utilizando punteros.*/

#include <stdio.h>
#include <stdlib.h>

void eliminar_espacios(char *s){
    char *p = s;
 
    while(*s != '\0'){
 
        if(*s != ' '){
            *p++ = *s;
        }
 
        s++;
    }
 
    *p = '\0';
}

int main(){
    char s[100];
    
    printf("Ingrese un string: ");
    fgets(s, sizeof(s), stdin);
    
    eliminar_espacios(s);
    
    printf("El string sin espacios es: %s\n", s);
    
    return 0;
}