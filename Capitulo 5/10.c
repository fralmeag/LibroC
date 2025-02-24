/*10. Escribir una función que invierta un string pasado como parámetro.*/

#include <stdio.h>
#include <string.h>

void invertir(char s[]){
    int i, j;
    char aux;
    
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

int main(){
    char s[] = "Hola mundo";
    
    printf("Antes de invertir: %s\n", s);
    invertir(s);
    printf("Despues de invertir: %s\n", s);
    
    return 0;
}
