#ifndef CHARMANDER_H_INCLUDED
#define CHARMANDER_H_INCLUDED

#include "Pokemon.h"
#include <string>

class Charmander : public Pokemon{

private:

    int cantGolpesRecibidos = 0;
    bool revivio = false;

public:

    Charmander(){
        this->vida = 150;
        this->danio = 40;
        this->nombrePokemon = "Charmander";
    }

    /**Charmander pierde 10 de vida con cada ataque**/

    virtual int ataque(Pokemon* oponente){
        oponente->recibirDanio(this->danio, this);
        this->vida -= 10;
        return this->danio;
    }

    /**Si Charmander recibe 3 o mas golpes y muere, puede revivir con 40 puntos de vida(solo una vez)**/

    virtual int recibirDanio(int danio, Pokemon* atacante){
        this->vida -= danio;
        cantGolpesRecibidos++;
        if(this->cantGolpesRecibidos >= 3 && this->vida <= 0 && !revivio){
            this->vida = 40;
            this->revivio = true;
            std::cout << this->nombrePokemon << " revivio con " << this->vida << " de vida" << std::endl;
        }
        return danio;
    }
};

#endif // CHARMANDER_H_INCLUDED
