/*32. Desarrollar una función que retorne un string dinámico con los dígitos hexadecimales de un entero recibido como parámetro.  
*/

#include <stdio.h>
#include <stdlib.h>

char* hexa(int n){
    char* hex = (char*)malloc(100);
    int i = 0;
 
    while(n > 0){
        int r = n % 16;
        
        if(r < 10){
            hex[i] = r + '0';
        }else{
            hex[i] = r + 55;
        }
        
        n /= 16;
        i++;
    }
 
    hex[i] = '\0';

    //invertir el hexadecimal para que quede en el orden correcto
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
 
    return hex;
}

int main(){
    int n;
    char* hex;
    
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    
    hex = hexa(n);
    
    printf("Hexadecimal: %s\n", hex);
    
    free(hex);
    
    return 0;
}