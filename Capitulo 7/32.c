/*32. Crear un sistema bancario utilizando arrays de structs Cuenta con atributos como saldo actual, interés anual, etc. Realizar transacciones de consignación y retiro entre cuentas.*/

#include <stdio.h>
#include <stdlib.h>

struct Cuenta{
    int numero;
    float saldo;
    float interesAnual;
};

void consignar(struct Cuenta *cuentas, int cuenta, float cantidad){
    cuentas[cuenta].saldo += cantidad;
}

void retirar(struct Cuenta *cuentas, int cuenta, float cantidad){
    cuentas[cuenta].saldo -= cantidad;
}

void imprimirCuentas(struct Cuenta *cuentas, int n){
    for(int i = 0; i < n; i++){
        printf("Cuenta %d\n", cuentas[i].numero);
        printf("Saldo: %.2f\n", cuentas[i].saldo);
        printf("Interes anual: %.2f\n", cuentas[i].interesAnual);
        printf("\n");
    }
}

int main(){
    struct Cuenta cuentas[3];
    cuentas[0].numero = 1;
    cuentas[0].saldo = 1000;
    cuentas[0].interesAnual = 0.05;

    cuentas[1].numero = 2;
    cuentas[1].saldo = 2000;
    cuentas[1].interesAnual = 0.05;

    cuentas[2].numero = 3;
    cuentas[2].saldo = 3000;
    cuentas[2].interesAnual = 0.05;

    printf("Saldo de las cuentas\n");
    imprimirCuentas(cuentas, 3);
    
    printf("Consiganción de 500 a la cuenta 1\n");
    consignar(cuentas, 0, 500);
    
    printf("\nRetiro de 1000 a la cuenta 2\n");
    retirar(cuentas, 1, 1000);

    printf("\nSaldo de las cuentas\n");
    imprimirCuentas(cuentas, 3);

    printf("\n");

    return 0;
}