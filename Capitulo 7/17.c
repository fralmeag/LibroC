/*17.Declarar struct Pais para almacenar datos demográficos. Ordenar array de structs Pais por tamaño población.*/

#include <stdio.h>
#include <string.h>

typedef struct{

    char nombre[50];
    double poblacion;
    double superficie;
}Pais;

void imprimir(Pais paises[], int n){

    printf("%-20s %-15s %-10s\n\n", "Nombre", "Poblacion", "Superficie");

    for(int i = 0; i < n; i++){
        printf("%-20s %-15.5f %-10.2f\n", paises[i].nombre, paises[i].poblacion, paises[i].superficie);
    }

}

void ordenarXpoblacion(Pais paises[], int n){

    Pais temp;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(paises[j].poblacion < paises[j+1].poblacion){
                temp = paises[j];
                paises[j] = paises[j+1];
                paises[j+1] = temp;
            }
        }
    }

}

int main(){

    Pais paises[] = {

        {"Argentina", 46000000, 2780400},
        {"Chile", 19500000, 756950},
        {"Colombia", 51500000, 1141748}

    };

    int n = sizeof(paises) / sizeof(paises[0]);

    printf("Paises:\n");
    imprimir(paises,n);

    ordenarXpoblacion(paises,n);

    printf("\nPaises ordenados por poblacion: \n");
    imprimir(paises, n);

    return 0;

}
