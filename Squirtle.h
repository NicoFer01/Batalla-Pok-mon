#ifndef SQUIRTLE_H_INCLUDED
#define SQUIRTLE_H_INCLUDED

#include "Pokemon.h"
#include <time.h>
#include <windows.h>
#include <string>

class Squirtle : public Pokemon{

public:

    Squirtle(){
        this->vida = 80;
        this->danio = this->vida;
        this->nombrePokemon = "Squirtle";
        srand(time(NULL));
    }

    /**Squirtle ataca normal**/

    virtual int ataque(Pokemon* oponente){
        oponente->recibirDanio(this->danio, this);
        return this->danio;
    }

    /**Al morir lanza un golpe critico con 30% de probabilidad**/

    virtual int recibirDanio(int danio, Pokemon* atacante){
        this->vida -= danio;
        if(this->vida <= 0){
            if((1 + rand() % 100) <= 30){
                atacante->recibirDanio(50, this);
                std::cout << this->nombrePokemon << "realizo un ataque critico  en " << atacante->getNombrePokemon() << std::endl;
            }
        }
        return danio;
    }
};

#endif // SQUIRTLE_H_INCLUDED
