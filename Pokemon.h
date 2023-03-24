#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include <string>

class Pokemon{

protected:

    int vida;
    int danio;
    std::string nombrePokemon;

public:

    virtual ~Pokemon(){};

    virtual int ataque(Pokemon* oponente) = 0;//obligado a implementar

    virtual int recibirDanio(int danio, Pokemon* atacante) = 0;

    int getVida(){
        return this->vida;
    }

    int getDanio(){
        return this->danio;
    }

    std::string getNombrePokemon(){
        return this->nombrePokemon;
    }
};

#endif // POKEMON_H_INCLUDED
