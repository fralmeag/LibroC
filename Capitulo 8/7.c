/*7.Crear un sistema de facturación que registre facturas emitidas en archivo.
 Los registros deben permitir luego mostrar el monto total facturado en el mes.*/

 #include <stdio.h>
 #include <string.h>

 typedef struct{

     int factura;
     int dia, mes, anio;
     char cliente[50];
     float monto;

 } Factura;

 void registrar(){

     FILE *archivo = fopen("facturas.txt", "ab");

     if(archivo == NULL){

        printf("ERROR: No se pudo abrir el archivo");
     }

     Factura factura;

     printf("Ingrese el numero de factura: ");
     scanf("%d", &factura.factura);

     printf("Ingrese la fecha formato DD MM YYYY: ");
     scanf("%d %d %d", &factura.dia, &factura.mes, &factura.anio);

     printf("Ingrese el nombre del cliente: ");
     getchar();
     fgets(factura.cliente, sizeof(factura.cliente), stdin);
     factura.cliente[strcspn(factura.cliente, "\n")] = 0;

     printf("Ingrese el monto de la factura: ");
     scanf("%f", &factura.monto);

     fwrite(&factura, sizeof(Factura),1,archivo);
     fclose(archivo);

     printf("\nSe registro la factura correctamente\n");

 }

 void calcularMontoMes(){

     FILE *archivo = fopen("facturas.txt", "rb");

     if(archivo == NULL){

        printf("Aun no hay facturas registradas.");

     }

     int mes, anio;
     float total = 0;

     printf("Ingrese el mes y año que desea consultar: ");
     scanf("%d %d", &mes, &anio);

     Factura factura;

     while(fread(&factura, sizeof(Factura),1,archivo)){

        if(factura.mes == mes && factura.anio == anio){

            total = total + factura.monto;
        }
     }

     fclose(archivo);

     printf("\nEl total facturado para el mes %d y año %d es %.2f\n", mes, anio, total);

 }

 int main(){

     int opcion;

     do{

        printf("\nMENU\n");
        printf("1. Registrar factura\n");
        printf("2. Consultar total facturado por mes\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

        case 1:
            registrar();
            break;
        case 2:
            calcularMontoMes();
            break;
        case 3:
            printf("Saliendo...");
            break;
        default:
            printf("Opcion no valida\n");
        }
     }while(opcion != 3);

     return 0;

 }
