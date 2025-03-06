/*15. Realizar una función que evalúe si un año es bisiesto y retorne TRUE o FALSE según corresponda. */

int bisiesto(int anio){

    if(anio % 4 == 0){
        if(anio % 100 != 0){
            return 1;
        }
        else{
            if(anio % 400 == 0){
               return 1;
            }
            else{
                return 0;
            }
        }
    }
    else {
        return 0;
    }


}


int main(){

    int anio;

    printf("Ingrese un año: ");
    scanf("%d", &anio);

    if(bisiesto(anio) == 1){
        printf("\nTRUE");
    }
    else{
        printf("\nFALSE");
    }
    return 0;

}


