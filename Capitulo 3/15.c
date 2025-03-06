/*15. Realizar una funci�n que eval�e si un a�o es bisiesto y retorne TRUE o FALSE seg�n corresponda. */

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

    printf("Ingrese un a�o: ");
    scanf("%d", &anio);

    if(bisiesto(anio) == 1){
        printf("\nTRUE");
    }
    else{
        printf("\nFALSE");
    }
    return 0;

}


