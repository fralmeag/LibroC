/*28. Desarrollar una función que determina si dos strings son anagramas (contienen las mismas letras).*/

#include <stdio.h>
#include <string.h>

int anagrama(char s1[], char s2[]){
    int i, j, cont = 0;
    
    if(strlen(s1) != strlen(s2)){
        return 0;
    }
    
    for(i = 0; i < strlen(s1); i++){
        for(j = 0; j < strlen(s2); j++){
            if(s1[i] == s2[j]){
                cont++;
                break;
            }
        }
    }
    
    if(cont == strlen(s1)){
        return 1;
    }
    
    return 0;
}

int main(){
    char s1[100], s2[100];

    printf("Ingrese la primera cadena: ");
    scanf("%s", s1);
    printf("Ingrese la segunda cadena: ");
    scanf("%s", s2);
    
    if(anagrama(s1, s2)){
        printf("Son anagramas\n");
    }else{
        printf("No son anagramas\n");
    }
    
    return 0;
}