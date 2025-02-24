/*50. Crear structs para representar una carta de poker con palo y valor. Modelar una mazo de cartas y manos de jugadores con correspondientes arreglos de structs*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52
#define NUM_JUGADORES 4
#define CARTAS_POR_JUGADOR (NUM_CARTAS / NUM_JUGADORES)

typedef enum {
    CORAZONES, DIAMANTES, TREBOLES, PICAS
} Palo;

typedef struct {
    int valor;  
    Palo palo;
} Carta;

typedef struct {
    Carta cartas[NUM_CARTAS];
} Mazo;

typedef struct {
    Carta cartas[CARTAS_POR_JUGADOR]; 
} Mano;

void inicializarMazo(Mazo* mazo) {
    int k = 0;
    for (int palo = 0; palo < 4; palo++) {
        for (int valor = 1; valor <= 13; valor++) {
            mazo->cartas[k].valor = valor;
            mazo->cartas[k].palo = palo;
            k++;
        }
    }
}

void barajarMazo(Mazo* mazo) {
    srand(time(NULL));
   
    for (int i = 0; i < NUM_CARTAS; i++) {
        int j = rand() % NUM_CARTAS;
        Carta temp = mazo->cartas[i];
        mazo->cartas[i] = mazo->cartas[j];
        mazo->cartas[j] = temp;
    }
}

void repartirCartas(Mazo* mazo, Mano* manos) {
    int k = 0; 
    
    for (int i = 0; i < NUM_JUGADORES; i++) {
        for (int j = 0; j < CARTAS_POR_JUGADOR; j++) {
            manos[i].cartas[j] = mazo->cartas[k];
            k++;
        }
    }
}

const char* nombrePalo(Palo palo) {
    switch (palo) {
        case CORAZONES: return "Corazones";
        case DIAMANTES: return "Diamantes";
        case TREBOLES: return "Tréboles";
        case PICAS: return "Picas";
        default: return "Desconocido";
    }
}

void imprimirCarta(Carta carta) {
    const char* nombreValor;
    
    switch (carta.valor) {
        case 1: nombreValor = "As"; break;
        case 11: nombreValor = "J"; break;
        case 12: nombreValor = "Q"; break;
        case 13: nombreValor = "K"; break;
        default: {
            static char buffer[3];
            sprintf(buffer, "%d", carta.valor);
            nombreValor = buffer;
            break;
        }
    }
    
    printf("%s de %s", nombreValor, nombrePalo(carta.palo));
}

void imprimirMano(Mano mano, int jugador) {
    printf("Mano del jugador %d:\n", jugador + 1);
    
    for (int i = 0; i < CARTAS_POR_JUGADOR; i++) {
        imprimirCarta(mano.cartas[i]);
        printf("\n");
    }
    
    printf("\n");
}

int main() {
    Mazo mazo;
    Mano manos[NUM_JUGADORES];

    inicializarMazo(&mazo);
    barajarMazo(&mazo);
    repartirCartas(&mazo, manos);

    for (int i = 0; i < NUM_JUGADORES; i++) {
        imprimirMano(manos[i], i);
    }

    return 0;
}
