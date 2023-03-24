#ifndef ENTRENADORES_H_INCLUDED
#define ENTRENADORES_H_INCLUDED

#include "Pokemon.h"
#include "Pikachu.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Psyduck.h"
#include "Buizel.h"
#include "GeneradorAleatorio.h"

#include <list>
#include <string>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

class Entrenadores {


private:

    /*std::list<Pokemon*>* listaAzul;
    std::list<Pokemon*>* listaRoja;*/
    //srand(time(NULL));
    GeneradorAleatorio miGenerador;

public:

    /*Entrenadores(){

        this->listaAzul = new std::list <Pokemon*>;
        this->listaRoja = new std::list <Pokemon*>;
    }

    ~Entrenadores(){

        delete this->listaAzul;
        delete this->listaRoja;
    }*/

    void Reglas(){

        std::cout << "Reglas: " << std::endl << std::endl;
        std::cout << "- Uno de los dos JUGADORES sera elegido (ROJO o AZUL) para ser el primero en elegir sus 3 POKEMONES "
        "para el combate." << std::endl << "Luego sera el turno del otro JUGADOR. " << std::endl << std::endl <<

        "- Una vez que ambos hayan elegido a sus Pokemones, SELECCIONARAN 1 para el combate." << std::endl <<
        "Estos se enfrentaran hasta que uno de los Pokemones sea DERROTADO." << std::endl << std::endl <<

        "- El GANADOR de la pelea ganara 1 PUNTO, y el PERDEDOR podra elegir a su siguiente Pokemon." << std::endl << std::endl<<

        "- Gana el que logre alcanzar los 3 PUNTOS" << std::endl << std::endl <<

        "- BUENA SUERTE A AMBOS ENTRENADORES!" << std::endl << std::endl << std::endl;

        std::cout << "Presione una tecla para continuar...";
    }

    std::string OpcionesPokemon(){

        int opciones = miGenerador.ElegirPokemon();

        switch(opciones){

            case 1:
                return "PIKACHU";
                break;

            case 2:
                return "BULBASAUR";
                break;

            case 3:
                return "CHARMANDER";
                break;

            case 4:
                return "SQUIRTLE";
                break;

            case 5:
                return "PSYDUCK";
                break;

            case 6:
                return "BUIZEL";
                break;
        }
    }

    void ElegirPokemon(std::list<Pokemon*>* lista){

        int i;
        for (i = 0; i < 3; i++){
            Sleep(1000);
            std::string opcionPokemon1 = OpcionesPokemon();
            Sleep(1000);
            std::string opcionPokemon2 = OpcionesPokemon();
            std::string pokemonElegido;
            int eleccion;

            std::cout << "\nIntroduzca el NUMERO de uno de los Pokemon en pantalla para elegirlo" << std::endl;

            std::cout << "1)" << opcionPokemon1 << "\n2)" << opcionPokemon2 << std::endl << std::endl;

            std::cin >> eleccion;

            while(eleccion != 1 && eleccion != 2){
                std::cout << "Solo puede elegir uno de los 2 Pokemon que estan en pantalla.\nIntente nuevamente." << std::endl << std::endl;
                std::cin >> eleccion;
            }

            if (eleccion == 1){
                pokemonElegido = opcionPokemon1;
            }
            else if (eleccion == 2){
                pokemonElegido = opcionPokemon2;
            }

            if (pokemonElegido == "PIKACHU"){
                Pikachu* raton = new Pikachu();
                lista->push_back(raton);
                std::cout << "\nHas elegido ha " << raton->getNombrePokemon() << std::endl;
            }
            if(pokemonElegido == "BULBASAUR"){
                Bulbasaur* planta = new Bulbasaur();
                lista->push_back(planta);
                std::cout << "\nHas elegido ha " << planta->getNombrePokemon() << std::endl;
            }
            if(pokemonElegido == "CHARMANDER"){
                Charmander* dragon = new Charmander();
                lista->push_back(dragon);
                std::cout << "\nHas elegido ha " << dragon->getNombrePokemon() << std::endl;
            }
            if(pokemonElegido == "SQUIRTLE"){
                Squirtle* tortuga = new Squirtle();
                lista->push_back(tortuga);
                std::cout << "\nHas elegido ha " << tortuga->getNombrePokemon() << std::endl;
            }
            if(pokemonElegido == "PSYDUCK"){
                Psyduck* pato = new Psyduck();
                lista->push_back(pato);
                std::cout << "\nHas elegido ha " << pato->getNombrePokemon() << std::endl;
            }
            if(pokemonElegido == "BUIZEL"){
                Buizel* nutria = new Buizel();
                lista->push_back(nutria);
                std::cout << "\nHas elegido ha " << nutria->getNombrePokemon() << std::endl;
            }
        }
        std::cout << "\nSus 3 Pokemones han sido elegidos." << std::endl << std::endl;
        Sleep(750);
        std::cout << "\nPresione cualquier tecla para continuar..." << std::endl;
        getch();
        system("cls");
    }

    void RecorrerLista(const std::list<Pokemon*>* lista, std::string turno){

        int numero = 1;
        std::list <Pokemon*>::const_iterator pos;
        pos = lista->begin();

        if (turno == "AZUL"){
            std::cout << "Pokemones del ENTRANADOR " << turno << ":" << std::endl;
        }
        else if (turno == "ROJO"){
            std::cout << "Pokemones del ENTRANADOR " << turno << ":" << std:: endl;
        }

        while(pos != lista->end()){
            std::cout << numero << ") " << (*pos)->getNombrePokemon();
            if ((*pos)->getVida() > 0){
                std::cout << ": Listo para la batalla" << std::endl;
            }
            else if ((*pos)->getVida() <= 0){
                std::cout << ": Fuera de combate" << std::endl;
            }
            numero++;
            pos++;
        }
    }

    void LimpiarLista(std::list<Pokemon*>* lista){

        std::list <Pokemon*>::const_iterator pos;
        pos = lista->begin();
        while(pos != lista->end()){
            delete (*pos);
            pos++;
        }
        std::cout << "\t-- Lista borrada --" << std::endl << std::endl;
    }
};


#endif // ENTRENADORES_H_INCLUDED
