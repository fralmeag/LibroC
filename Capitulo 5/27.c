/*27.Escribir un programa que decodifique código ASCII a caracteres imprimibles. Usar arreglos para mapear códigos.*/

#include <stdio.h>
#include <string.h>

int main(){

    char mensaje[100];
    char decodificacion[100];
    int ascii[100];
    int posicion = 0;
    int i = 0, j, numero;

    printf("Ingrese los codigos ascii separados por espacios: ");
    fgets(mensaje, sizeof(mensaje), stdin);

    while(mensaje[i] != '\0'){

        if(mensaje[i] >= '0' && mensaje[i] <= '9'){
            numero = 0;

            while(mensaje[i] >= '0' && mensaje[i] <= '9'){
                numero = numero * 10 + (mensaje[i] - '0');
                i++;
            }

            if(numero >= 32 && numero <= 126){
                ascii[posicion] = numero;
                posicion++;
            }
        }
        else{
            i++;
        }
    }

    for(j = 0; j < posicion; j++){
        decodificacion[j] = (char)ascii[j];
    }

    decodificacion[posicion] =  '\0';

    printf("\nDecodificacion--> %s", decodificacion);

    return 0;
}
