/*40. Crear una aplicación que lea dos fechas (día, mes y año) e indique cual es la más reciente, o si son iguales.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int dia1, mes1, anio1, dia2, mes2, anio2;
    
    printf("Ingrese la primera fecha (dia, mes, año): ");
    scanf("%d %d %d", &dia1, &mes1, &anio1);
    printf("Ingrese la segunda fecha (dia, mes, año): ");
    scanf("%d %d %d", &dia2, &mes2, &anio2);
    
    //Verificar que las fechas sean válidas
    if(dia1 < 1 || dia1 > 31 || mes1 < 1 || mes1 > 12 || anio1 < 0){
        printf("La primera fecha no es válida.\n");
        return 1;
    }

    if(dia2 < 1 || dia2 > 31 || mes2 < 1 || mes2 > 12 || anio2 < 0){
        printf("La segunda fecha no es válida.\n");
        return 1;
    }

    //Comparar las fechas
    if(anio1 > anio2){
        printf("La primera fecha es la más reciente.\n");
    }else if(anio1 < anio2){
        printf("La segunda fecha es la más reciente.\n");
    }else{
        if(mes1 > mes2){
            printf("La primera fecha es la más reciente.\n");
        }else if(mes1 < mes2){
            printf("La segunda fecha es la más reciente.\n");
        }else{
            if(dia1 > dia2){
                printf("La primera fecha es la más reciente.\n");
            }else if(dia1 < dia2){
                printf("La segunda fecha es la más reciente.\n");
            }else{
                printf("Las fechas son iguales.\n");
            }
        }
    }

    return 0;
}