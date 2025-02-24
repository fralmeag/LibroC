/*42. Declarar struct Fecha y desarrollar funciones para calcular días transcurridos entre dos fechas y sumar/restar días.*/

#include <stdio.h>
#include <stdlib.h>

struct Fecha{
    int dia;
    int mes;
    int anio;
};

void ingresarFecha(struct Fecha *f){
    printf("Ingrese el dia: ");
    scanf("%d", &f->dia);
    printf("Ingrese el mes: ");
    scanf("%d", &f->mes);
    printf("Ingrese el anio: ");
    scanf("%d", &f->anio);
}

int diasTranscurridos(struct Fecha f1, struct Fecha f2){
    int dias = 0;
    int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if(f1.anio == f2.anio){
        if(f1.mes == f2.mes){
            dias = f2.dia - f1.dia;
        }else{
            for(int i = f1.mes; i < f2.mes; i++){
                dias += diasMeses[i-1];
            }
            dias += f2.dia - f1.dia;
        }
    }else{
        for(int i = f1.anio; i < f2.anio; i++){
            if(i % 4 == 0){
                dias += 366;
            }else{
                dias += 365;
            }
        }
        for(int i = f1.mes; i <= 12; i++){
            dias += diasMeses[i-1];
        }
        for(int i = 1; i < f2.mes; i++){
            dias += diasMeses[i-1];
        }
        
        dias += f2.dia - f1.dia;
    }
 
    return dias;
}

void sumarDias(struct Fecha *f, int dias){
    int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    for(int i = 0; i < dias; i++){
        if(f->anio % 4 == 0){
            diasMeses[1] = 29;
        }else{
            diasMeses[1] = 28;
        }
        
        if(f->dia == diasMeses[f->mes-1]){
            f->dia = 1;
            if(f->mes == 12){
                f->mes = 1;
                f->anio++;
            }else{
                f->mes++;
            }
        }else{
            f->dia++;
        }
    }
}

void restarDias(struct Fecha *f, int dias){
    int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    for(int i = 0; i < dias; i++){
        if(f->anio % 4 == 0){
            diasMeses[1] = 29;
        }else{
            diasMeses[1] = 28;
        }
        
        if(f->dia == 1){
            if(f->mes == 1){
                f->mes = 12;
                f->anio--;
            }else{
                f->mes--;
            }
            f->dia = diasMeses[f->mes-1];
        }else{
            f->dia--;
        }
    }
}

int main(){
    struct Fecha f1, f2;
    int dias, diasRestar, diasSumar;
    
    printf("Ingrese la primera fecha:\n");
    ingresarFecha(&f1);
    printf("Ingrese la segunda fecha:\n");
    ingresarFecha(&f2);
    
    dias = diasTranscurridos(f1, f2);
    printf("Dias transcurridos entre fechas: %d\n", dias);
    
    printf("Ingrese la cantidad de dias a sumar: ");
    scanf("%d", &diasSumar);
    sumarDias(&f1, 5);
    printf("Fecha sumada: %d/%d/%d\n", f1.dia, f1.mes, f1.anio);
    
    printf("Ingrese la cantidad de dias a restar: ");
    scanf("%d", &diasRestar);
    restarDias(&f1, diasRestar);
    printf("Fecha restada: %d/%d/%d\n", f1.dia, f1.mes, f1.anio);
    
    return 0;
}
