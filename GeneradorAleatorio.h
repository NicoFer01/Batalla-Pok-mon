#ifndef GENERADORALEATORIO_H_INCLUDED
#define GENERADORALEATORIO_H_INCLUDED

#include <time.h>
#include <windows.h>

class GeneradorAleatorio{

public:

    int ElegirEntrenador(){
        srand(time(NULL));
        return (1 + (rand() % 2));
    }

    int ElegirPokemon(){
        srand(time(NULL));
        return (1 + (rand() % 6));
    }
};

#endif // GENERADORALEATORIO_H_INCLUDED
