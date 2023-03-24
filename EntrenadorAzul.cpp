#include "EntrenadorAzul.h"

#include "Pokemon.h"
#include <conio.h>

EntrenadorAzul::EntrenadorAzul(){

    this->listaAzul = new std::list <*Pokemon>;
}

EntrenadorAzul::~EntrenadorAzul(){

    delete this->listaAzul;
}

void EntrenadorAzul::ElegirPokemon(){

    int elegidos = 0;

        int i;

        std::cout << "¡Entrenador Azul, eliga a sus 3 Pokemon!" << std::endl;

        do{
            for (i = 1; i > 2; i++){

                int opciones = generador->ElegirPokemon();

                if (opciones == 1){
                    std::cout << "\n1) Pikachu" << std::endl;
                }

                if (opciones == 2){
                    std::cout << "\n2) Bulbasaur" << std::endl;
                }

                if (opciones == 3){
                    std::cout << "\n3) Charmander" << std::endl;
                }

                if (opciones == 4){
                    std::cout << "\4) Squirtle" << std::endl;
                }

                if (opciones == 5){
                    std::cout << "\n5) Psyduck" << std::endl;
                }

                if (opciones == 6){
                    std::cout << "\6) Buizel" << std::endl;
                }
            }

            int eleccion;
            std::cin >> eleccion;

            if (eleccion == 1){
                Pikachu* raton = new Pikachu();
                listaAzul->push_back(raton);
                std::cout << "Has elegido ha " << raton->getNombrePokemon() << std::endl;
                elegidos++;
            }

            if (eleccion == 2){
                Bulbasaur* planta = new Bulbasaur();
                listaAzul->push_back(planta);
                std::cout << "Has elegido ha " << planta->getNombrePokemon() << std::endl;
                elegidos++;
            }

            if (eleccion == 3){
                Charmander* dragon = new Charmander();
                listaAzul->push_back(dragon);
                std::cout << "Has elegido ha " << dragon->getNombrePokemon() << std::endl;
                elegidos++;
            }

            if (eleccion == 4){
                Squirtle* tortuga = new Squirtle();
                listaAzul->push_back(tortuga);
                std::cout << "Has elegido ha " << tortuga->getNombrePokemon() << std::endl;
                elegidos++;
            }

            if (eleccion == 5){
                Psyduck* pato = new Psyduck();
                listaAzul->push_back(pato);
                std::cout << "Has elegido ha " << pato->getNombrePokemon() << std::endl;
                elegidos++;
            }

            if (eleccion == 6){
                Buizel* nutria = new Buizel();
                listaAzul->push_back(nutria);
                std::cout << "Has elegido ha " << nutria->getNombrePokemon() << std::endl;
                elegidos++;
            }

            else{
                std::cout << "Solo puede elegir los pokemon que esten en pantalla" << std::endl;
            }

        }while(elegidos != 3 || getch());
    }
}
