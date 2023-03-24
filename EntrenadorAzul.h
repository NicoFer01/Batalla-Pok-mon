#ifndef ENTRENADORAZUL_H_INCLUDED
#define ENTRENADORAZUL_H_INCLUDED

#include "Pokemon.h"

#include <list>
#include <iostream>

//Crear una sola clase para Entrenadores e iniciar una para cada jugador
//Crear una clase que incluya ambas listas con sus métodos

class EntrenadorAzul{

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

#endif // ENTRENADORAZUL_H_INCLUDED
