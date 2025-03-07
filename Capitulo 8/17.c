/*17.Abrir un archivo de registros de cuentas bancarias con saldo y escribir un programa para detectar y reportar todas las cuentas con saldo negativo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char numeroCuenta[20];
    char nombreTitular[50];
    float saldo;
}CuentaBancaria;

void saldos(){

    FILE *archivo = fopen("saldos.txt", "r");

    if(archivo == NULL){

        printf("ERROR: No se pudo abrir el archivo");
        return;
    }

    CuentaBancaria cuenta;
    int encontrado = 0;

    while(fscanf(archivo, " %19[^,], %49[^,], %f", cuenta.numeroCuenta, cuenta.nombreTitular, &cuenta.saldo) == 3){

        if(cuenta.saldo < 0){
            printf("Cuenta: %s, Titular: %s, Saldo: %.2f\n", cuenta.numeroCuenta, cuenta.nombreTitular, cuenta.saldo);
            encontrado = 1;
        }
    }

    if(encontrado == 0){
        printf("No hay cuentas con saldo negativo.\n");
    }

    fclose(archivo);

}

int main(){

    saldos();

    return 0;

}
