/*46. Implementar una función para convertir un número romano en un número decimal.
*/

#include <stdio.h>
#include <string.h>

int romanToDecimal(char romanNumber[]){
    int decimal = 0;
    int i = 0;

    while (romanNumber[i]){
        if (romanNumber[i] == 'I'){
            if (romanNumber[i + 1] == 'V'){
                decimal += 4;
                i++;
            }else if (romanNumber[i + 1] == 'X'){
                decimal += 9;
                i++;
            }else{
                decimal += 1;
            }
        }else if (romanNumber[i] == 'V'){
            decimal += 5;
        }else if (romanNumber[i] == 'X'){
            if (romanNumber[i + 1] == 'L'){
                decimal += 40;
                i++;
            }else if (romanNumber[i + 1] == 'C'){
                decimal += 90;
                i++;
            }else{
                decimal += 10;
            }
        }else if (romanNumber[i] == 'L'){
            decimal += 50;
        }else if (romanNumber[i] == 'C'){
            if (romanNumber[i + 1] == 'D'){
                decimal += 400;
                i++;
            }else if (romanNumber[i + 1] == 'M'){
                decimal += 900;
                i++;
            }else{
                decimal += 100;
            }
        }else if (romanNumber[i] == 'D'){
            decimal += 500;
        }else if (romanNumber[i] == 'M'){
            decimal += 1000;
        }

        i++;
    }

    return decimal;
}

int main(){
    char romanNumber[100];
    printf("Ingrese un numero romano: ");
    scanf("%s", romanNumber);

    printf("El numero decimal es: %d\n", romanToDecimal(romanNumber));

    return 0;
}