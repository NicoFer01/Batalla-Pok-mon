#ifndef BUIZEL_H_INCLUDED
#define BUIZEL_H_INCLUDED

#include "Pokemon.h"
#include <time.h>
#include <windows.h>
#include <string>

class Buizel : public Pokemon{

public:

    Buizel(){
        this->vida = 100;
        this->danio = 20;
        this->nombrePokemon = "Buizel";
        srand(time(NULL));
    }

    /**Buizel tiene un 30% de probabilidad de hacer el doble de danio**/

    virtual int ataque(Pokemon* oponente){
        if((1 + rand() % 100) <= 30){
            oponente->recibirDanio(this->danio*2, this);
            return this->danio*2;
        }
        else{
            oponente->recibirDanio(this->danio, this);
            return this->danio;
        }
    }

    /**Buizel tiene un 10% de recibir la mitad del danio recibido**/

    virtual int recibirDanio(int danio, Pokemon* atacante){
        if((1 + rand() % 100) <= 10){
            this->vida -= danio/2;
            std::cout << this->nombrePokemon << " solo recibio la mitad del ataque de " << atacante->getNombrePokemon() << std::endl;
            return danio/2;
        }
        else{
            this->vida -= danio;
            return danio;
        }
    }
};

#endif // BUIZEL_H_INCLUDED
