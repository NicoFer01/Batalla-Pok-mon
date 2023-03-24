#ifndef BULBASAUR_H_INCLUDED
#define BULBASAUR_H_INCLUDED

#include "Pokemon.h"
#include <time.h>
#include <windows.h>
#include <string>

class Bulbasaur : public Pokemon{

public:

    Balbasaur(){
        this->vida = 100;
        this->danio = 0;
        this->nombrePokemon = "Bulbasaur";
        srand(time(NULL));
    }

    /**Bulbasaur ataca con un danio aleatorio entre 10 y 60. Solo multiplos de 10**/

    virtual int ataque(Pokemon* oponente){
        int danioAct = (1 + (rand() % 6) *10);
        oponente->recibirDanio(danioAct, this);
        return danioAct;
    }

    /**Bulbasaur devuelve los ataque con un 30% de probabilidad**/

    virtual int recibirDanio(int danio, Pokemon* atacante){
        this->vida -= danio;
        if((1 + rand() % 100) <= 30){
            atacante->recibirDanio(danio, this);
            std::cout << this->nombrePokemon << " regreso el ataque de " << atacante->getNombrePokemon() << std::endl;
        }
        return danio;
    }
};

#endif // BULBASAUR_H_INCLUDED
