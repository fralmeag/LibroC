/*11.Abrir un archivo de registros con ubicaciones GPS de una ruta y calcular la distancia total en línea recta entre todos los puntos.*/

#include <stdio.h>
#include <math.h>



double radianes(double grados){

    return grados * M_PI / 180.0;

}

double calculo(double lat1, double lon1, double lat2, double lon2){

    double dLat = radianes(lat2-lat1);
    double dLon = radianes(lon2 - lon1);
    lat1 = radianes(lat1);
    lat2 = radianes(lat2);

    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);

    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return 6378.137 * c;

}

int main(){

    FILE *archivo = fopen("rutas.txt", "r");

    if(archivo == NULL){

        printf("ERROR: No se pudo abrir el archivo");
        return 1;
    }

    double lat1, lon1, lat2, lon2;
    double total = 0.0;

    if(fscanf(archivo, "%lf %lf", &lat1, &lon1)!= 2){
        printf("Error en el formato del archivo");
        fclose(archivo);
        return 1;
    }

    while(fscanf(archivo, "%lf %lf", &lat2, &lon2) == 2){
        total = total + calculo(lat1, lon1, lat2, lon2);
        lat1 = lat2;
        lon1 = lon2;
    }

    fclose(archivo);

    printf("Distancia total: %.2f", total);

    return 0;

}
