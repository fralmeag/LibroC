/*6. Ordenar un vector de máximo 100 números utilizando el método de la burbuja.*/

#include <stdio.h>
#include <stdlib.h>

void burbuja(int *v, int n){
    int i, j, aux;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

int main(){
    int n, i;
    int v[100];
    printf("Introduce el número de elementos del vector: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("Introduce el elemento %d: ", i+1);
        scanf("%d", &v[i]);
    }
   
    burbuja(v, n);
    
    printf("Vector ordenado: ");
    
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    
    printf("\n");
    
    return 0;
}