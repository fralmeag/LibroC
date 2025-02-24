/*10. Generar 20 números aleatorios entre 1 y 10 con ciclo for.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i;
    
    srand(time(NULL));
    
    for(i = 0; i < 20; i++){
        printf("%d ", rand() % 10 + 1);
    }

    printf("\n");

    return 0;
}