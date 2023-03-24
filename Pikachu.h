#ifndef PIKACHU_H_INCLUDED
#define PIKACHU_H_INCLUDED

#include "Pokemon.h"
#include <time.h>
#include <windows.h>

class Pikachu : public Pokemon{

private:

    int cantAtaques = 0;

public:

    Pikachu(){
        this->vida = 120;
        this->danio = 30;
        this->nombrePokemon = "Pikachu";
        srand(time(NULL));
    }

    /**Pikachu ataca con 40 de danio despues del tercer ataque**/

    virtual int ataque (Pokemon* oponente){
        if(cantAtaques >= 3){
            oponente->recibirDanio(this->danio + 10, this);
            return this->danio + 10;
        }

        else{
            oponente->recibirDanio(this->danio, this);
            this->cantAtaques++;
            return this->danio;
        }
    }

    /**Pikachu esquiva los ataques con 50% de probabilidad**/

    virtual int recibirDanio(int danio, Pokemon* atacante){
        if((1 + rand() % 100) < 50){
            return 0;
        }

        else{
            this->vida -= danio;
            return danio;
        }
    }
};

#endif // PIKACHU_H_INCLUDED
