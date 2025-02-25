/*33. Desarrollar una función que realice una conversión de temperatura entre grados Celsius, Fahrenheit y Kelvin,
retornando el resultado como double.*/

double conversion(float grado, int tipo){

    switch(tipo){

        case 1: return (grado * 9.0/5.0) + 32;

        case 2: return (grado + 273.15);

        case 3: return (grado - 32) * (5.0/9.0);

        case 4: return (grado-32) * (5.0/9.0) + 273.15;

        case 5: return grado - 273.15;

        case 6: return (grado - 273.15) * (9.0/5.0) + 32;

    }

}

int main(){

    int opcion;
    float grados;

    printf("                MENU");
    printf("\n1. Convertir de Celsius a Fahrenheit");
    printf("\n2. Convertir de Celsius a Kelvin");
    printf("\n3. Convertir de Fahrenheit a Celsius");
    printf("\n4. Convertir de Fahrenheit a Kelvin");
    printf("\n5. Convertir de Kelvin a Celsius");
    printf("\n6. Convertir de Kelvin a Fahrenheit");
    printf("\nElegir una opción ");
    scanf("%d", &opcion);
    printf("\nIngrese los grados: ");
    scanf("%f", &grados);


    printf("--> %.2f", conversion(grados, opcion));

    return 0;


}
