/*23.Declarar struct Racional para representar una fracción. Sobrecargar operadores entre dos structs Racional.*/

#include <stdio.h>

typedef struct{

    int numerador;
    int denominador;

}Racional;

Racional suma(Racional f1, Racional f2){

    Racional resultado;

    resultado.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;

    resultado.denominador = f1.denominador * f2.denominador;


    return resultado;

}

Racional resta(Racional f1, Racional f2){

    Racional resultado;

    resultado.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;

    resultado.denominador = f1.denominador * f2.denominador;


    return resultado;

}

Racional multiplica(Racional f1, Racional f2){

    Racional resultado;

    resultado.numerador = f1.numerador * f2.numerador;
    resultado.denominador = f1.denominador * f2.denominador;

    return resultado;
}

Racional divide(Racional f1, Racional f2){

    Racional resultado;

    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;

    return resultado;

}

void imprimir(Racional fraccion){

    if(fraccion.denominador == 1){
        printf("%d", fraccion.numerador);
    }
    else{
        printf("%d / %d", fraccion.numerador, fraccion.denominador);
    }

}

int main(){

    Racional fraccion1 = {3,4};
    Racional fraccion2 = {2,5};

    printf("Primera Fraccion: %d / %d ", fraccion1.numerador, fraccion1.denominador);
    printf("\nSegunda Fraccion: %d / %d ", fraccion2.numerador, fraccion2.denominador);

    printf("\nSuma: ");
    imprimir(suma(fraccion1,fraccion2));

    printf("\nResta: ");
    imprimir(resta(fraccion1,fraccion2));

    printf("\nMultiplicacion: ");
    imprimir(multiplica(fraccion1,fraccion2));

    printf("\nDivision: ");
    imprimir(divide(fraccion1,fraccion2));

    return 0;
}
