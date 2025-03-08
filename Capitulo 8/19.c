/*19. Crear un programa para comparar los registros de respuestas de dos cuestionarios (archivos) y
generar un informe con las preguntas respondidas incorrectamente por cada participante.*/

#include <stdio.h>
#include <string.h>

void compararRespuestas(){

    char respuestasCorrectas[100];
    char respuestasParticipante[100];

    FILE *archivo = fopen("correctas.txt", "r");

    if(archivo == NULL){

        printf("ERROR: No se pudo abrir el archivo de respuestas correctas.");
        return;
    }

    fgets(respuestasCorrectas, 100, archivo);
    fclose(archivo);

    archivo = fopen("participante.txt", "r");

    if(archivo == NULL){
        printf("ERROR: No se pudo abrir el archivo del participante.");
        return;
    }

    fgets(respuestasParticipante, 100, archivo);
    fclose(archivo);

    printf("\nPreguntas respondidas incorrectamente:\n");

    for(int i = 0; respuestasCorrectas[i] != '\0' && respuestasParticipante[i] != '\0'; i++){
        if(respuestasCorrectas[i] != respuestasParticipante[i]){
            printf("Pregunta %d: Correcta (%c), Respondida(%c)\n", i+1, respuestasCorrectas[i], respuestasParticipante[i]);
        }
    }
}

int main(){

    compararRespuestas();

    return 0;

}
