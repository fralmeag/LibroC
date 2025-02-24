/*48. Desarrollar una función que retorne la cantidad de vocales que existe en una frase pasada como parámetro.*/

#include <stdio.h>
#include <string.h>

int contarVocales(char frase[]){
    int i, cont=0;
    
    for(i=0; i<strlen(frase); i++){
        if(frase[i]=='a' || frase[i]=='e' || frase[i]=='i' || frase[i]=='o' || frase[i]=='u' || frase[i]=='A' || frase[i]=='E' || frase[i]=='I' || frase[i]=='O' || frase[i]=='U'){
            cont++;
        }
    }
    
    return cont;
}

int main(){
    char frase[100];
    
    printf("Ingrese una frase: ");
    scanf("%[^\n]", frase);
    
    printf("La cantidad de vocales en la frase es: %d\n", contarVocales(frase));
    
    return 0;
}