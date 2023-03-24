#include "GeneradorAleatorio.h"

int GeneradorAleatorio::ElegirEntrenador(){

    srand(time(NULL));
    return (1 + (rand() % 2));
}

int GeneradorAleatorio::ElegirPokemon(){

    srand(time(NULL));
    return (1 + (rand() % 6));
}
