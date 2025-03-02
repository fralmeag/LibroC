/*31.Desarrollar tipo enumerativo con los meses del año y utilizar en struct Fecha para validar mes correcto.*/

#include <stdio.h>

typedef enum{

    ENERO = 1, FEBRERO = 2, MARZO = 3, ABRIL = 4, MAYO = 5, JUNIO = 6,
    JULIO = 7, AGOSTO = 8, SEPTIEMBRE = 9, OCTUBRE = 10, NOVIEMBRE = 11, DICIEMBRE = 12
} Mes;

typedef struct{

    int dia;
    Mes mes;
    int anio;

}Fecha;

int validaMes(int mes){

    if(mes >= ENERO && mes <= DICIEMBRE){
        return 1;
    }
    else{
        return 0;
    }

}

int main(){

    Fecha fecha;

    printf("Dia: ");
    scanf("%d", &fecha.dia);

    printf("Mes: ");
    scanf("%d", &fecha.mes);

    printf("Anio: ");
    scanf("%d", &fecha.anio);

    if(validaMes(fecha.mes)){
        printf("\nMes valido");
    }
    else{
        printf("\nMes no valido");
    }

    return 0;
}
