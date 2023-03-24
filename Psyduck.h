#ifndef PSYDUCK_H_INCLUDED
#define PSYDUCK_H_INCLUDED

#include "Pokemon.h"
#include <string>

class Psyduck : public Pokemon{

private:

    bool primerGolpe = true;

public:

    Psyduck(){
        this->vida = 100;
        this->danio = 10;
        this->nombrePokemon = "Psyduck";
    }

    /**Por cada golpe recibido, el danio de Psyduck aumenta en 10 unidades. Su vida tambien aumenta en 10 por cada golpe**/

    virtual int ataque(Pokemon* oponente){
        oponente->recibirDanio(this->danio, this);
        this->vida += 10;
        return this->danio;
    }

    /**Ignora el primer golpe**/

    virtual int recibirDanio(int danio, Pokemon* atacante){
        if(!primerGolpe){
            this->vida -= danio;
            return danio;
        }
        else{
            std::cout << this->nombrePokemon << " esquivo el primer ataque." << std::endl;
            primerGolpe = false;
            return 0;
        }
    }
};

#endif // PSYDUCK_H_INCLUDED
