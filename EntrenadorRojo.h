#ifndef ENTRENADORROJO_H_INCLUDED
#define ENTRENADORROJO_H_INCLUDED

#include "Pokemon.h"

#include <list>
#include <iostream>

class EntrenadorRojo{

private:

    std::list<Pokemon*>* listaAzul;
    std::list<Pokemon*>* listaRoja;

public:

    EntrenadorAzul(){

        this->listaAzul = new std::list <Pokemon*>;
    }

    EntrenadorRojo(){

        this->listaRoja = new std::list <Pokemon*>;
    }

    ~EntrenadorAzul(){

        delete this->listaAzul;
    }

    ~EntrenadorRojo(){

        delete this->listaRoja;
    }

    void ElegirPokemon(){


    }
};

#endif // ENTRENADORROJO_H_INCLUDED
